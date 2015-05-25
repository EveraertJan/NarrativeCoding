#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include "cinder/gl/Fbo.h"
#include "cinder/params/Params.h"
using namespace ci;
using namespace ci::app;
using namespace std;


#include "UI.h"
#include "Track.h"
#include "Cam.h"
#include "Story.h"
#include "Compiler.h"

class storyBlocks_v2App : public AppNative {
  public:
	void setup();
    void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
	void update();
	void draw();
    
    
    
    int state;
    
    UI ui;
    Track track;
    Cam cam;
    Story story;
    Compiler c;
    
    
    Vec2i ul;
    Vec2i dr;
    
    Boolean camVis;
    params::InterfaceGl mParams;
    
    Boolean isset;
};
void storyBlocks_v2App::setup(){
    
    
    setWindowSize(800, 600);
    setFullScreen(true);
    setWindowPos(0, 0);
    
    isset = false;
    ul = Vec2i(0, 0);
    dr = Vec2i(getWindowWidth(), getWindowHeight());
    
    
    state = -1;
    cam.setup();
    camVis = true;
    
    mParams = params::InterfaceGl( "tracking", Vec2i( 200, 200 ) );
    mParams.addParam( "tag threshold", &track.tagThreshold, "min=0.0 max=255.0 step=2.0");
    mParams.addParam( "init threshold", &track.threshold );
    mParams.addParam("show cam", &camVis);
    
    mParams.addSeparator();
    mParams.addParam("ulx", &ul.x);
    mParams.addParam("uly", &ul.y);
    mParams.addParam("drx", &dr.x);
    mParams.addParam("dry", &dr.y);

}
void storyBlocks_v2App::update(){
    cam.update();
}
void storyBlocks_v2App::draw(){
    
    if(isset){
        cam.draw(ul, dr);
    } else {
        cam.draw(getWindowBounds().getUL(), getWindowBounds().getLR());
    }
    
    Surface w = copyWindowSurface();
    if(!camVis){
        gl::clear(Color(20, 20, 20));
    }
    if(!isset){
        ci::gl::color(255, 255, 255);
    }
    
    switch(state){
        {case -1:
            ci::gl::color(255, 255, 255);
            ci::gl::drawSolidCircle(ul, 10);
            ci::gl::drawSolidCircle(dr, 10);
            ci::gl::lineWidth(5);
            ci::gl::drawStrokedRect(getWindowBounds());
            ci::gl::lineWidth(2);
            break;
        }
        {case 0:
            ci::Area sa = ui.showBookScan();
            
            if(track.trackcode(w.clone(sa), sa.getUL(),  true) == 1552){
                if(story.loadStory(1552)){
                    state++;
                } else {
                    ci::app::console() << "couldn't load \n";
                }
            }
            //scan book when completed
            break;}
        case 1:
            //green card situation;
            if(track.greenScan(w.clone(ui.showGreenCard()))){
                state++;
            }
            break;
        {case 2:
            
            //track code moment
            ci::Area sa = ui.showBookScan();
            int id = track.trackcode(w.clone(sa), sa.getUL(), false);
            if(id == 1){
                state++;
            }
            break;}
        {case 3:
            // show tutorial and green card
            ui.tutorial();
            if(track.greenScan(w.clone(ui.showGreenCard()))){
                state++;
            }
            break;
        }
        {case 4:
            ci::Area sa = ui.TagScan();
            track.trackcode(w.clone(sa), sa.getUL(), false);
            track.followTags(w);
            ui.showTagConnections(track.tagPos);
            if(track.greenScan(w.clone(ui.showGreenCard()))){
                //compile ;
            }
            // codeBlock, add tags
            break;}
        case 5:
            c.input.clear();
            c.passes.clear();
            
            /*for(int i  =0; i<cardPos.size(); i++){
                int code = track.getCode(copyWindowSurface(cardPos.at(i)), false);
                //ci::app::console() << code << "\n";
                if(c.conv.isSet(code)){
                    ci::app::console() << "pushed \n";
                    c.input.push_back(code);
                }
            }*/
            // compile
            if(c.compile()){
                state++;
            } else {
                //show error
                state--;
            }
            
            break;
        case 6:
            setFrameRate(2);
            c.draw(true);
            
            // display output
            break;
        case 7:
        
            // show results
            break;
            
    }
    if(state>0) {
        track.trackBook(w);
    }
  /*
    Surface drawn = copyWindowSurface();
    
    gl::clear();
    gl::color(255, 255, 255);
    gl::draw(drawn, Rectf(ul.x, ul.y, dr.x, dr.y));
    */
    
    gl::color(255, 0, 0);
    gl::drawString(toString(state), Vec2i(10, 10));
    
    mParams.setPosition(Vec2i(0, 0));
    mParams.draw();
    
}
void storyBlocks_v2App::mouseDown( MouseEvent event ){
   
}

void storyBlocks_v2App::keyDown(cinder::app::KeyEvent event){
    if(event.getChar() == ' '){
        if(mParams.isVisible()){
            mParams.hide();
        } else {
            mParams.show();
        }
    } else if(event.getChar() == 's'){
        isset = true;
        state++;
    }
}

CINDER_APP_NATIVE( storyBlocks_v2App, RendererGl )

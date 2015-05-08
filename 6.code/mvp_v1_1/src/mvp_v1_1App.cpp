#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Compiler.h"
#include "Cam.h"
#include "Book.h"
#include "Tracker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class mvp_v1_1App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void keyDown(KeyEvent event);
	void update();
	void draw();
    void readCards();
    void showScanner();
    
    Compiler c;
    Cam cam;
    Book b;
    Tracker track;
    
    Boolean play;
    Boolean loaded;
    Boolean compiled;
    int bookSize;
    
    std::vector<Area> cardPos;
};

void mvp_v1_1App::setup(){
    b.setup(0);
    cam.setup();
    setWindowSize(1024, 768);
    compiled = false;
    loaded = false;
    play = false;
    bookSize = 200;
}

void mvp_v1_1App::mouseDown( MouseEvent event ){
}
void mvp_v1_1App::keyDown( KeyEvent event ){
    if(event.getChar() == 'r'){
        play = true;
    }
    if(event.getChar() == 'e'){
        readCards();
    }
}

void mvp_v1_1App::update(){
    cam.update();
    if(b.isFound){
        b.update();
    }
}

void mvp_v1_1App::readCards(){
    ci::app::console() << "init \n";
    c.input.clear();
    c.passes.clear();
    for(int i  =0; i<cardPos.size(); i++){
        int code = track.getCode(copyWindowSurface(cardPos.at(i)), false);
        //ci::app::console() << code << "\n";
        if(c.checkCode(code)){
            c.input.push_back(code);
        }
    }
    loaded = true;
    cardPos.clear();
//    play = true;
}

void mvp_v1_1App::draw(){
    gl::clear( Color( 0, 0, 0 ) );
    cam.draw();
    if(!b.isFound){
        showScanner();
    } else{
        b.draw(bookSize);
        track.getCorners(copyWindowSurface());
        b.dispPosTop = track.trackPos;
        b.dispPosDown = track.trackPos2;
        gl::color(255, 255, 0);
        gl::drawSolidCircle(b.dispPosTop, 10);
        
        if(!loaded){
            cardPos.clear();
            int scanSize =bookSize*0.375;
            int xOffset = 100;
            int yOffset = 200;
            for(int i = 0; i<8; i++){
                gl::drawStrokedRect(Rectf(i*(scanSize+10)+xOffset, getWindowHeight()-scanSize-yOffset, i*(scanSize+10)+(scanSize)+xOffset, getWindowHeight()-yOffset));
                cardPos.push_back(Area(i*(scanSize+10)+xOffset, getWindowHeight()-scanSize-yOffset, i*(scanSize+10)+(scanSize)+xOffset, getWindowHeight()-yOffset));
            }
            
        }
        
    }
    if(play){
        if(c.running && !c.died){
            if(compiled){
                setFrameRate(2);
                c.draw(true);
            }else {
                c.compile();
                compiled = true;
            }
        } else {
            setFrameRate(30);
            if(b.isFound){
                c.draw(false);
            }
            
        }
    }
	// clear out the window with black
	
}
void mvp_v1_1App::showScanner(){
    int xS = ci::app::getWindowWidth()/2;
    int yS = ci::app::getWindowHeight()/2;
    int scanS = bookSize/2;
    int yOffset = bookSize*0.305;
    ci::Surface surfScan = copyWindowSurface(Area(int(xS-scanS/2),int((yS-scanS/2)-yOffset), int(xS+(scanS/2)), int(yS+(scanS/2)-yOffset)));
    int bW = bookSize;
    int bH = bookSize*1.5;
    gl::drawStrokedRect(Rectf(xS-(bW/2), yS-(bH/2), xS+(bW/2), yS+(bH/2)));
    gl::drawStrokedRect(Rectf((xS-scanS/2),(yS-scanS/2)-yOffset, xS+(scanS/2), yS+(scanS/2)-yOffset));
    int code = track.getCode(surfScan, true);
    //ci::app::console() << code << "\n";
    if(b.exists(code)){
        b.setup(code);
        c.setup(code);
    }
    
    
    
    track.trackPos.x = (xS+bW/2)-10;
    track.trackPos.y = (yS-bH/2)-10;
    
    track.trackPos2.x = (xS+bW/2)-10;
    track.trackPos2.y = (yS+bH/2)-10;
    
}

CINDER_APP_NATIVE( mvp_v1_1App, RendererGl )

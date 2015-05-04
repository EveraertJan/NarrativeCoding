#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Compiler.h"
#include "TagDetect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class gameEngineApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    
    TagDetect td;
    Compiler c;
    
    
    Boolean downloading;
    Boolean outputting;
};

void gameEngineApp::setup()
{
    ci::app::setFrameRate(2);
    
    c.setup();
    td.setup();
    
    outputting = false;
    downloading = false;
    
    
}
void gameEngineApp::mouseDown( MouseEvent event ){
    ci::app::console() << "started \n";
    downloading = true;
    outputting = true;
}
void gameEngineApp::update(){
    // adding steps, alter numbers for other steps
    std::vector<int> in;
    if(downloading){
        if(td.tracked.size()>0){
            c.input = td.tracked;
        } else {
            c.input = in;
            ci::app::console() << "input size: " << c.input.size() << "\n";
        }
        //build and fill in passes to see what char should do
        c.compile();
    }
    td.update();
}

void gameEngineApp::draw(){
    ci::gl::clear( Color(20, 20, 20));
    ci::gl::color(200, 0, 0);
    if(outputting){
        downloading = false;
        c.draw(outputting);
        if(c.running == false){
            outputting = false;
        }
    } else {
        td.draw();
    }
    
    
}


CINDER_APP_NATIVE( gameEngineApp, RendererGl )

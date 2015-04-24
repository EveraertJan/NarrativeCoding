#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Compiler.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class gameEngineApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    
    
    Compiler c;
    
    
    Boolean downloading;
    Boolean outputting;
};

void gameEngineApp::setup()
{
    ci::app::setWindowPos(500, 500);
    ci::app::setFrameRate(2);
    
    c.setup();
    outputting = true;
    downloading = true;
}
void gameEngineApp::mouseDown( MouseEvent event ){
    
}
void gameEngineApp::update(){
    // adding steps, alter numbers for other steps
    std::vector<int> in;
    in.push_back(0);
    in.push_back(2);
    in.push_back(3);
    in.push_back(2);
    if(downloading){
        c.input = in;
        //build and fill in passes to see what char should do
        c.compile();
        downloading = false;
    }
}

void gameEngineApp::draw(){
    ci::gl::clear();
    c.draw(outputting);
    if(c.running == false){
        outputting = false;
    }
}


CINDER_APP_NATIVE( gameEngineApp, RendererGl )

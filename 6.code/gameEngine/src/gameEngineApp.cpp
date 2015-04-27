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
    ci::app::setWindowPos(500, 500);
    ci::app::setFrameRate(20);
    
    c.setup();
    td.setup();
    
    outputting = true;
    downloading = true;
    
    
}
void gameEngineApp::mouseDown( MouseEvent event ){
    
}
void gameEngineApp::update(){
    // adding steps, alter numbers for other steps
    std::vector<int> in;
    in.push_back(15);
    in.push_back(5);
    in.push_back(3);
    in.push_back(2);
    in.push_back(3);
    in.push_back(0);
    in.push_back(5);
    in.push_back(5);
    
    if(downloading){
        c.input = in;
        //build and fill in passes to see what char should do
        c.compile();
        downloading = false;
    }
    
    td.update();
}

void gameEngineApp::draw(){
    ci::gl::clear( Color(20, 20, 20));
    ci::gl::color(200, 0, 0);
    c.draw(outputting);
    if(c.running == false){
        outputting = false;
    }
    td.draw();
    
}


CINDER_APP_NATIVE( gameEngineApp, RendererGl )

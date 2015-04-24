#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "User.h"

using namespace ci;
using namespace ci::app;
using namespace std;



class project_noVisionApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    User user;
    
};

void project_noVisionApp::setup(){
    ci::app::setWindowSize(1400, 900);
    ci::app::setFullScreen();
    
    user.setup();
    
}

void project_noVisionApp::mouseDown( MouseEvent event ){
}

void project_noVisionApp::update(){
    user.update(600, 400);
}

void project_noVisionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    ci::Surface s  = copyWindowSurface();
    user.draw(s);
}

CINDER_APP_NATIVE( project_noVisionApp, RendererGl )

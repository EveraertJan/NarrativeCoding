#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Cam.h"
#include "DetectTag.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class compiler_v1App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Cam webcam;
    DetectTag dt;
};

void compiler_v1App::setup()
{
    webcam.setup();
    dt.setup(Area(10, 10, 110, 110));
}

void compiler_v1App::mouseDown( MouseEvent event )
{
}

void compiler_v1App::update()
{
    webcam.update();
    
}

void compiler_v1App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    webcam.draw();
    Surface s  = copyWindowSurface();
    //dt.scan(s);
    dtq.draw();
}

CINDER_APP_NATIVE( compiler_v1App, RendererGl )

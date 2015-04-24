#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Cam.h"
#include "User.h"


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
    vector<User> users;
    ci::Vec2i midpoint;
    Area scanArea;
    int numUsers=2;
    
    Boolean track = false;;
};

void compiler_v1App::setup(){
    webcam.setup();
    
}

void compiler_v1App::mouseDown( MouseEvent event ){
    track = true;
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
    if(track){
    ci::Surface pres = copyWindowSurface(scanArea);
    int degChange = abs(360/numUsers);
    for(int i = 0; i<numUsers; i++){
        int deg = degChange*i;
        cinder::gl::pushMatrices();
        ci::gl::rotate(deg);
        ci::gl::popMatrices();
        Area ar = Area(0, 0, 10, 10);
        Surface s  = copyWindowSurface(ar);
        users[i].update(s);
    }
    }
    
}

CINDER_APP_NATIVE( compiler_v1App, RendererGl )

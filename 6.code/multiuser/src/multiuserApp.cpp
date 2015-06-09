#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "User.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class multiuserApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    params::InterfaceGl mParams;
    
    
    User user;
};

void multiuserApp::setup()
{
    
    setWindowSize(960, 540);
    setFullScreen(TRUE);
    setFrameRate(24);
    setWindowPos(0, 0);
    user.setup(getWindowCenter().x, getWindowCenter().y, getWindowWidth(), getWindowHeight());
    
    
    
    mParams = params::InterfaceGl( "tracking", Vec2i( 200, 300 ) );
    //mParams.addParam( "tag threshold", &user.track.tagThreshold, "min=0.0 max=255.0 step=2.0");
    
    mParams.addParam("xrot", &user.track.cam.xrot);
    mParams.addParam("yrot", &user.track.cam.yrot);
    mParams.addParam("zrot", &user.track.cam.zrot);
    mParams.addParam("width", &user.track.cam.width);
    mParams.addParam("height", &user.track.cam.height);
    mParams.addParam("x", &user.track.cam.x);
    mParams.addParam("y", &user.track.cam.y);
    mParams.addSeparator();
    mParams.addParam("state", &user.state);
    mParams.addParam("treshold greencard", &user.track.treshold);
    mParams.addParam("show cam", &user.showCam);
    mParams.addParam("tag size", &user.tagSize);
}

void multiuserApp::mouseDown( MouseEvent event ){
    user.state++;
}

void multiuserApp::update(){
    user.update();
}

void multiuserApp::draw(){
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    user.draw();
    
    //if(user.ui.settingsVis){
        mParams.setPosition(Vec2i(0, 0));
        mParams.draw();
    //} else {
    //    mParams.hide();
    //}
}

CINDER_APP_NATIVE( multiuserApp, RendererGl )

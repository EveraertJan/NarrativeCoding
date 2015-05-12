#include "cinder/app/AppNative.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Capture.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/params/Params.h"
#include "cinder/Camera.h"
#include "cinder/gl/Light.h"



using namespace ci;
using namespace ci::app;
using namespace std;

class engineTestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void setCamera();
	void update();
	void draw();
    
    params::InterfaceGl	mParams;
    
    // CAMERA Controls
    CameraPersp mCamPrep;
//    CameraOrtho mCamPrep;
    Quatf				mSceneRotation;
    float				mCameraDistance;
    Vec3f				mEye, mCenter, mUp;
    
    
};

void engineTestApp::setup(){
    ci::app::setWindowSize(1024, 768);
    setCamera();
    
    
}

void engineTestApp::setCamera(){
    mCameraDistance = 500.0f;
    mEye			= Vec3f( 5.0f, 5.0f, mCameraDistance );
    mCenter			= Vec3f::zero();
    mUp				= Vec3f::yAxis();
    mCamPrep.setPerspective(  75.0f, getWindowAspectRatio(), 5.0f, 2000.0f );
    gl::enableAlphaBlending();
    
    //mSceneRotation = Quatf(45, 0, 45);
    
    // SETUP PARAMS
    mParams = params::InterfaceGl( "LearnHow", Vec2i( 200, 160 ) );
    mParams.addParam( "Scene Rotation", &mSceneRotation, "opened=1" );
    mParams.addSeparator();
    mParams.addParam( "Eye Distance", &mCameraDistance, "min=50.0 max=1500.0 step=50.0 keyIncr=s keyDecr=w" );

    
}

void engineTestApp::mouseDown( MouseEvent event )
{
}

void engineTestApp::update(){
    mEye = Vec3f( 5.0f, 5.0f, mCameraDistance );
    mCamPrep.lookAt(mEye, Vec3f::zero(), mUp);
    gl::setMatrices( mCamPrep );
    gl::rotate(mSceneRotation);
    
}

void engineTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    gl::setMatrices( mCamPrep );

    gl::color(200, 20, 20);
    for(int i  =0; i<800; i+=80){
        for(int j = 0; j<800; j+=80){
            gl::drawCube(Vec3f(i-400, j-400, 0), Vec3f(40, 40, 8));
        }
    }
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    //params::InterfaceGl::draw();
    mParams.draw();
    
}

CINDER_APP_NATIVE( engineTestApp, RendererGl )

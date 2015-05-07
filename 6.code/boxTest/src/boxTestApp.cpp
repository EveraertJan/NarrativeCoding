
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/CinderMath.h"

#include "boost/function.hpp"
#include "boost/bind.hpp"
#include "boost/lambda/lambda.hpp"

#include "DeferredRenderer.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class boxTestApp : public AppNative {
  public:
    void prepareSettings(Settings *settings);
    void setup();
    void keyDown( KeyEvent event );
    void update();
    void draw();
    
    CameraPersp mCam;
    
    //deferred render functionality
    DeferredRenderer    mDeferredRenderer;
    int                 mRenderView;
    void drawShadowCasters(gl::GlslProg* deferShader) const;
    void drawNonShadowCasters(gl::GlslProg* deferShader) const;
    void drawOverlay() const;
    void drawDepthParticles() const;
};

void boxTestApp::prepareSettings(Settings *settings)
{
    settings->setFrameRate(10.0f);
    settings->setWindowSize(1280, 720);
}

void boxTestApp::setup()
{
    //set up camera
    mCam.setPerspective( 45.0f, getWindowAspectRatio(), 0.1f, 10000.0f );
    mCam.lookAt(Vec3f( 0.0f, 0.0f, 7.0f ), Vec3f::zero(), Vec3f(0.0f, 1.0f, 0.0f) );
    mCam.setCenterOfInterestPoint(Vec3f::zero());
    
    //create functions pointers to send to deferred renderer
    boost::function<void(gl::GlslProg*)> fRenderShadowCastersFunc = boost::bind( &boxTestApp::drawShadowCasters, this, boost::lambda::_1 );
    boost::function<void(gl::GlslProg*)> fRenderNotShadowCastersFunc = boost::bind( &boxTestApp::drawNonShadowCasters, this,  boost::lambda::_1 );
    boost::function<void(void)> fRenderOverlayFunc = boost::bind( &boxTestApp::drawOverlay, this );
    boost::function<void(void)> fRenderParticlesFunc = boost::bind( &boxTestApp::drawDepthParticles, this );
    
    mRenderView = DeferredRenderer::SHOW_FINAL_VIEW;
    mDeferredRenderer.setup( fRenderShadowCastersFunc, fRenderNotShadowCastersFunc, NULL, NULL, &mCam, Vec2i(1280, 720), 1280, true, true, true);
    //mDeferredRenderer.addPointLight( Vec3f(-2.5f, 3.0f, 0.0f), Color(1.0f, 1.0f, 1.0f) * LIGHT_BRIGHTNESS_DEFAULT * 0.3f, true, false);      //blue
    //mDeferredRenderer.addPointLight( Vec3f(2.5f, 3.0f, 0.0f), Color(0.94f, 0.15f, 0.23f) * LIGHT_BRIGHTNESS_DEFAULT * 0.3f, true, false);      //red
    mDeferredRenderer.addPointLight(Vec3f( 0.0f, 2.0f, 4.0f ), Color(1.0f, 1.0f, 1.0f) * LIGHT_BRIGHTNESS_DEFAULT * 0.6f, true, false);
}

void boxTestApp::keyDown( KeyEvent event )
{
    //toggle through deferred render modes using - and + keys
    switch (event.getCode()) {
        case KeyEvent::KEY_EQUALS:
        {
            mRenderView++;
            if(mRenderView>(DeferredRenderer::NUM_RENDER_VIEWS - 1)) {
                mRenderView = 0;
            }
            
            console() << mRenderView << "\n";
        }
            break;
        case KeyEvent::KEY_KP_MINUS:
        {
            mRenderView--;
            if(mRenderView<0) {
                mRenderView = DeferredRenderer::NUM_RENDER_VIEWS - 1;
            }
            
            console() << mRenderView << "\n";
        }
            break;
        default:
            break;
    }
}

void boxTestApp::update()
{
    //moving some lights for effect
    int counter = 0;
    for( vector<Light_Point*>::iterator lightIter = mDeferredRenderer.mCubeLights.begin(); lightIter != mDeferredRenderer.mCubeLights.end(); lightIter++ ) {
        (*lightIter)->setPos(Vec3f( math<float>::sin(getElapsedSeconds() + (M_PI * counter)) * 3.0f, math<float>::cos(getElapsedSeconds() + (M_PI * counter)) * 3.0f, 3.0f ));
        counter++;
    }
}

void boxTestApp::draw()
{
    mDeferredRenderer.renderFullScreenQuad(mRenderView);
}


void boxTestApp::drawShadowCasters(gl::GlslProg* deferShader) const
{
    gl::color(0.2f, 0.2f, 0.2f);
    gl::drawCube(Vec3f::zero(), Vec3f(7.2, 3.6, 1));
    gl::drawCube(Vec3f(0.0f, 0.05f, 0.0f), Vec3f(7.2, 0.1, 1.1));
    gl::drawCube(Vec3f(0.0f, 0.05f, 0.0f), Vec3f(1.44, 0.1, 3.0));
    for(int i = 0; i<5; i++){
        gl::drawCube(Vec3f(-3.0f+(7.2/5)*i, 0.05f, 0.0f), Vec3f(1.44, 0.1, 1.1));
    }
}

void boxTestApp::drawNonShadowCasters(gl::GlslProg* deferShader) const
{
    //a plane to capture shadows (though it won't cast any itself)
    /*int size = 3000;
    glColor3ub(255, 255, 255);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3i( size, -2,-size);
    glVertex3i(-size, -2,-size);
    glVertex3i(-size, -2, size);
    glVertex3i( size, -2, size);
    glEnd();*/
}

void boxTestApp::drawOverlay() const
{}

void boxTestApp::drawDepthParticles() const
{}

CINDER_APP_NATIVE( boxTestApp, RendererGl )

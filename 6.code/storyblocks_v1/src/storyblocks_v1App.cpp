#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Cam.h"
#include "BoardDetect.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class storyblocks_v1App : public AppNative {
public:
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    Cam webcam;
    Detect d1;
    Detect d2;
    Boolean startScan = false;
};

void storyblocks_v1App::setup()
{
    webcam.setup();
    ci::app::setFrameRate(24);
    d1.setup(Area(180, 180, 280, 280));
    d2.setup(Area(400, 180, 500, 280));
}

void storyblocks_v1App::mouseDown( MouseEvent event )
{
    startScan = true;
}

void storyblocks_v1App::update()
{
    webcam.update();
    
}
void storyblocks_v1App::draw(){
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    webcam.draw();
    gl::color(200, 200, 200);
    if(!d1.b.isFound){
        gl::drawStrokedRect(Rectf(d1.scanArea));
    }
    if(!d2.b.isFound){
        gl::drawStrokedRect(Rectf(d2.scanArea));
    }
    if(startScan){
        Surface s = ci::app::copyWindowSurface();
        d1.scan(s);
        d1.draw();
        d2.scan(s);
        d2.draw();
    }
}

CINDER_APP_NATIVE( storyblocks_v1App, RendererGl )

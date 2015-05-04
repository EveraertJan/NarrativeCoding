#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Book.h"
#include "Cam.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class bookLoadTestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    void showScanner();
    void trackCode(Area scanArea, ci::Surface surf);
    
    Cam webc;
    Book book;
    Boolean BookSet;
    
    int bookCode;
    
};

void bookLoadTestApp::setup(){
    ci::app::setWindowSize(1024, 768);
    //ci::app::setFullScreen();
    
    bookCode = 0;
    BookSet = false;
    webc.setup();
}

void bookLoadTestApp::mouseDown( MouseEvent event ){
}

void bookLoadTestApp::update(){
    
    webc.update();
    if(BookSet){
        book.update();
    }
}

void bookLoadTestApp::draw(){
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    webc.draw();
    if(bookCode == 0){
        showScanner();
    } else if(!BookSet){
        book.setup(bookCode);
        BookSet=  true;
    } else {
        book.draw();
    }
}

void bookLoadTestApp::showScanner(){
    int xS = ci::app::getWindowWidth()/2;
    int yS = ci::app::getWindowHeight()/2;
    int bW = 360;
    int bH = 560;
    int scanS = 160;
    int yOffset = 110;
    ci::Surface surfScan = copyWindowSurface(Area(int(xS-scanS/2),int((yS-scanS/2)-yOffset), int(xS+(scanS/2)), int(yS+(scanS/2)-yOffset)));
    
    gl::drawStrokedRect(Rectf(xS-(bW/2), yS-(bH/2), xS+(bW/2), yS+(bH/2)));
    gl::drawStrokedRect(Rectf((xS-scanS/2),(yS-scanS/2)-yOffset, xS+(scanS/2), yS+(scanS/2)-yOffset));
    trackCode(Area(int(xS-scanS/2),int((yS-scanS/2)-yOffset), int(xS+(scanS/2)), int(yS+(scanS/2)-yOffset)), surfScan);
    
}

void bookLoadTestApp::trackCode(Area scanArea, ci::Surface surf){
    
        int oX = scanArea.getX1();
        int oY = scanArea.getY1();
        scanArea = Area(0, 0, scanArea.getX2()-scanArea.getX1(), scanArea.getY2()-scanArea.getY1()) ;
        //ci::gl::draw(ci::gl::Texture(surf));
        int bX = surf.getWidth()/2;
        int bY = surf.getHeight()/2;
        std::vector<ci::Vec2i> points;
    std:vector<Boolean> isset;
        for(int i = 0; i<4; i++){
            points.push_back(ci::Vec2i(bX, bY));
            isset.push_back(false);
        }
        ColorAT<unsigned char> avg = surf.areaAverage(scanArea);
        for(int i = 100; i>20; i--){
            for(int st = 0; st<360; st+=2){
                ci::gl::color(0, 250, 0);
                int x = int(bX+(i*sin(ci::toRadians(float(st)))));
                int y = int(bY+(i*cos(ci::toRadians(float(st)))));
                int rad = floor(st/90);
                if(!isset.at(rad)){
                    if(x>0 && y>0 && x<surf.getWidth() && y<surf.getHeight()){
                        ci::ColorAT<unsigned char> c = surf.getPixel(ci::Vec2i(x, y));
                        //if((c.r+c.g+c.b)/3<){
                        if(c.r>avg.r && c.b>avg.b && c.g>avg.g){
                            if(x>0 && y>0 && x<surf.getWidth() && y<surf.getHeight()){
                                ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
                                isset.at(rad) = true;
                                
                                
                                int nx = int(bX+(((i/5)*4.5)*sin(ci::toRadians(float(st)))));
                                int ny = int(bY+(((i/5)*4.5)*cos(ci::toRadians(float(st)))));
                                points.at(rad) = ci::Vec2i(nx, ny);
                            }
                        }
                    }
                }
            }
        }
        
        int steps = 5;
        int bit = 1;
        int total = 0;
        for(int j = 1; j<steps; j++) {
            for(int i = 1; i<steps; i++){
                float xos = (((points[1].x-points[2].x)/steps)*j);
                float xoe = (((points[0].x-points[3].x)/steps)*j);
                float x = (points[2].x+xos) + (((points[3].x+xoe)-(points[2].x+xos))/steps)*i;
                
                float yos = (((points[3].y-points[2].y)/steps)*i);
                float yoe = (((points[0].y-points[1].y)/steps)*i);
                float y = (points[2].y+yos) + (((points[1].y+yoe)-(points[2].y+yos))/steps)*j;
                cinder::ColorT<unsigned char> c = surf.getPixel(ci::Vec2i((int)x, (int)y));
                ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
                if(c.r>avg.r && c.b>avg.b && c.g>avg.g){
                    total+=bit;
                }
                bit = bit*2;
                
                
            }
        }
    bookCode = total;
        
        
    

}

CINDER_APP_NATIVE( bookLoadTestApp, RendererGl )

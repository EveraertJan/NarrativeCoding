#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Book.h"
#include "Cam.h"
#include "cinder/gl/Fbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class mvpApp : public AppNative {
public:
    void setup();
    void mouseDown( MouseEvent event );
    void keyDown (KeyEvent event);
    void update();
    void draw();
    void showScanner();
    void trackCorner();
    void trackCode(Area scanArea, ci::Surface surf);
    
    Cam webc;
    Book book;
    Boolean BookSet;
    
    int bookCode;
    Vec2i trackPos;
    Vec2i trackPos2;
    
    
    int bookSize=200;
    int bW;
    int bH;
};

void mvpApp::setup(){
    ci::app::setWindowSize(1024, 768);
    //ci::app::setFullScreen();
    ci::app::setFrameRate(24);
    bookCode = 0;
    BookSet = false;
    webc.setup();
    bW = bookSize;
    bH = bookSize*1.5;
}
void mvpApp::keyDown( KeyEvent event ) {
    if( event.getChar() == 'r' || event.getChar() == 'R' ){
        BookSet = false;
        bookCode = 0;
    }
}
void mvpApp::mouseDown( MouseEvent event ){
    book.outputting = true;
    book.downloading = true;
}

void mvpApp::update(){
    
    webc.update();
    if(BookSet){
        book.update();
    }
}

void mvpApp::draw(){
    gl::clear( Color( 0, 0, 0 ) );
    gl::color(255, 255, 255);
    webc.draw();
    if(!book.exists(bookCode)){
        showScanner();
    } else if(!BookSet){
        book.setup(bookCode);
        BookSet=  true;
    } else {
        trackCorner();
        gl::color(255, 255, 255);
        book.draw(bookSize);
    }
}
void mvpApp::trackCorner(){
    vector<Vec2i> arr;
    Boolean tb = false;
    Surface s = copyWindowSurface();
    gl::color(255, 255, 255);
    gl::color(0, 0, 255);
    int treshold = 20;
    ColorAT<unsigned char> c = s.getPixel(trackPos);
    if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
        tb = true;
        book.codeMoment = false;
    } else if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
        tb = false;
        book.codeMoment = true;
        book.dispPosTop.x = trackPos.x;
        book.dispPosTop.y = trackPos.y;
        book.dispPosDown.x = trackPos2.x;
        book.dispPosDown.y = trackPos2.y;
    }
    
    
    
    for(int i = 0; i<360; i+=5){
        for (int j = 0; j<50; j+=5) {
            int x = int(trackPos.x+(j*sin(ci::toRadians(float(i)))));
            int y = int(trackPos.y+(j*cos(ci::toRadians(float(i)))));
            
            
            ColorAT<unsigned char> c = s.getPixel(Vec2i(x, y));
            if(tb){
                if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
                    gl::color(0, 0, 255);
                    //gl::drawSolidCircle(Vec2i(x, y), 2);
                    arr.push_back(Vec2i(x, y));
                }
            } else {
                gl::color(0, 255, 0);
                if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
                    //gl::drawSolidCircle(Vec2i(x, y), 2);
                    arr.push_back(Vec2i(x, y));
                }
            }
        }
    }
    if(arr.size()>10){
        Vec2i total;
        for(int i = 0; i<arr.size(); i++){
            total.x+=arr[i].x;
            total.y+=arr[i].y;
        }
        total.x = total.x/arr.size();
        total.y = total.y/arr.size();
        trackPos = total;
    } else {
        book.codeMoment = false;
    }
    gl::drawSolidCircle(trackPos, 2);
    arr.clear();
    
    for(int i = 0; i<360; i+=5){
        for (int j = 0; j<50; j+=5) {
            int x = int(trackPos2.x+(j*sin(ci::toRadians(float(i)))));
            int y = int(trackPos2.y+(j*cos(ci::toRadians(float(i)))));
            
            
            ColorAT<unsigned char> c = s.getPixel(Vec2i(x, y));
            if(tb){
                if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
                    gl::color(0, 0, 255);
                    arr.push_back(Vec2i(x, y));
                }
            } else {
                if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
                    gl::color(0, 255, 0);
                    arr.push_back(Vec2i(x, y));
                }
            }
            
        }
    }
    if(arr.size()>10){
        Vec2i total;
        for(int i = 0; i<arr.size(); i++){
            total.x+=arr[i].x;
            total.y+=arr[i].y;
        }
        total.x = total.x/arr.size();
        total.y = total.y/arr.size();
        trackPos2 = total;
    } else {
        book.codeMoment = false;
    }
    gl::drawSolidCircle(trackPos2, 2);
    if(trackPos.distance(trackPos2)>bookSize*2){
        BookSet = false;
        bookCode = 0;
        
    }
    
}

void mvpApp::showScanner(){
    int xS = ci::app::getWindowWidth()/2;
    int yS = ci::app::getWindowHeight()/2;
    int scanS = 100;
    int yOffset = bookSize*0.305;
    ci::Surface surfScan = copyWindowSurface(Area(int(xS-scanS/2),int((yS-scanS/2)-yOffset), int(xS+(scanS/2)), int(yS+(scanS/2)-yOffset)));
    
    gl::drawStrokedRect(Rectf(xS-(bW/2), yS-(bH/2), xS+(bW/2), yS+(bH/2)));
    gl::drawStrokedRect(Rectf((xS-scanS/2),(yS-scanS/2)-yOffset, xS+(scanS/2), yS+(scanS/2)-yOffset));
    trackCode(Area(int(xS-scanS/2),int((yS-scanS/2)-yOffset), int(xS+(scanS/2)), int(yS+(scanS/2)-yOffset)), surfScan);
    
    trackPos.x = (xS+bW/2)-10;
    trackPos.y = (yS-bH/2)-10;
    
    trackPos2.x = (xS+bW/2)-10;
    trackPos2.y = (yS+bH/2)-10;
    
}

void mvpApp::trackCode(Area scanArea, ci::Surface surf){
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
    //ci::app::console() << total << "\n";
    bookCode = total;
    
    
    
    
}

CINDER_APP_NATIVE( mvpApp, RendererGl )

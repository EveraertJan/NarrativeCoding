//
//  TagDetect.cpp
//  gameEngine
//
//  Created by jan everaert on 25/04/15.
//
//

#include "TagDetect.h"

void TagDetect::setup(){
    webcam.setup();
}
void TagDetect::update(){
    webcam.update();
    
}
void TagDetect::draw(Surface surf){
    tracked.clear();
    getCode(surf.getBounds(), surf, 1);
    gl::drawStrokedRect(Rectf(surf.getBounds()));
    
}

void TagDetect::getCode(Area scanArea, ci::Surface surf, int offset){
    ci::gl::draw(surf);
    
    int oX = scanArea.getX1();
    int oY = scanArea.getY1();
    scanArea = Area(0, 0, scanArea.getX2()-scanArea.getX1(), scanArea.getY2()-scanArea.getY1()) ;
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
                    if(c.r<avg.r && c.b<avg.b && c.g<avg.g){
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
            if(c.r<avg.r && c.b<avg.b && c.g<avg.g){
                total+=bit;
            }
            bit = bit*2;
            
            
        }
    }
    tracked.push_back(total);
    ci::gl::color(255, 255, 255);
    //ci::app::console() << total << "\n";
    
    
}

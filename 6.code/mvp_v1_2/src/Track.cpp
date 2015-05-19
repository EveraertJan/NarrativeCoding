//
//  Track.cpp
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#include "Track.h"


void Track::setup(){
    cam.setup();
}
void Track::update(){
    cam.update();
}
void Track::draw(){
    cam.draw();
    curScreen = copyWindowSurface();
}

ci::Vec2i Track::updateCorner(ci::Vec2i curPos){
    return curPos;
}

Boolean Track::greenCard(ci::Area cardArea){
    ci::Surface surf;
    surf = curScreen.clone(cardArea);
    ColorAT<unsigned char> c = surf.areaAverage(surf.getBounds());
    if(c.g>200 && c.b<50 && c.r<50){
        return true;
    } else {
        return false;
    }
}

int Track::getTagId(ci::Area scan, Boolean negative){
    ci::Surface surf;
    surf = curScreen.clone(scan);
    int oX = surf.getBounds().getX1();
    int oY = surf.getBounds().getY1();
    //scanArea = Area(0, 0, scanArea.getX2()-scanArea.getX1(), scanArea.getY2()-scanArea.getY1()) ;
    int bX = surf.getWidth()/2;
    int bY = surf.getHeight()/2;
    std::vector<ci::Vec2i> points;
    std::vector<Boolean> isset;
    for(int i = 0; i<4; i++){
        points.push_back(ci::Vec2i(bX, bY));
        isset.push_back(false);
    }
    ci::ColorAT<unsigned char> avg = surf.areaAverage(surf.getBounds());
    for(int i = 100; i>20; i--){
        for(int st = 0; st<360; st+=2){
            ci::gl::color(0, 250, 0);
            int x = int(bX+(i*sin(ci::toRadians(float(st)))));
            int y = int(bY+(i*cos(ci::toRadians(float(st)))));
            int rad = floor(st/90);
            if(!isset.at(rad)){
                if(x>0 && y>0 && x<surf.getWidth() && y<surf.getHeight()){
                    ci::ColorAT<unsigned char> c = surf.getPixel(ci::Vec2i(x, y));
                    Boolean go;
                    if(negative){
                        if(c.r>avg.r && c.b>avg.b && c.g>avg.g){
                            go = true;
                        } else {
                            go = false;
                        }
                    } else {
                        if(c.r<avg.r && c.b<avg.b && c.g<avg.g){
                            go = true;
                        } else {
                            go = false;
                        }
                    }
                    if(go){
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
            gl::pushMatrices();
            gl::translate(scan.x1, scan.y1);
            ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
            gl::popMatrices();
            Boolean go;
            if(negative){
                if(c.r>avg.r && c.b>avg.b && c.g>avg.g){
                    go = true;
                } else {
                    go = false;
                }
            } else {
                if(c.r<avg.r && c.b<avg.b && c.g<avg.g){
                    go = true;
                } else {
                    go = false;
                }
            }
            
            if(go){
                total+=bit;
            }
            bit = bit*2;
            
            
        }
    }
    return total;

}

int Track::getPageCode(ci::Vec2i top, ci::Vec2i bottom){
    //extract pageCode based on gray areas between points;
    int count = 0;
    int multi = 1;
    gl::drawSolidCircle(top, 20);
    for(int i  =1; i<5; i++){
        ci::Vec2i cur = ci::Vec2i(top.x+((bottom.x-top.x)/6)*i, top.y+((bottom.y-top.y)/6)*i);
        
        gl::color(255, 0, 0);
        gl::drawSolidCircle(cur, 20);
        ColorAT<unsigned char> c = curScreen.getPixel(cur);
        int th = 150;
        if(c.r<th && c.g<th && c.b<th){
            count+=multi;
        }
        multi*=2;
    }
    return count;
}
//
//  Track.cpp
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

#include "Track.h"


void Track::setup(){
    cam.setup();
    
    ul = Vec2i(0, 0);
    ur = Vec2i(ci::app::getWindowWidth(), 0);
    dl = Vec2i(0, ci::app::getWindowHeight());
    dr = Vec2i(ci::app::getWindowWidth(), ci::app::getWindowHeight());
    
    
    treshold=20;
    
}
void Track::update(){
    cam.update();
}
void Track::draw(Boolean showCam){
    
    
    if(cam.started){
        cam.draw(ul,ur, dr, dl);
        c = copyWindowSurface();
    }
    
    
    if(!showCam){
        ci::gl::clear();
    }
    
}
int Track::trackTag(ci::Area ar, Boolean negative){

    ci::Surface surf = c.clone(ar);
    int oX = surf.getBounds().getX1();
    int oY = surf.getBounds().getY1();
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
        for(int st = 0; st<360; st+=1){
            ci::gl::color(0, 250, 0);
            int x = int(bX+(i*sin(ci::toRadians(float(st)))));
            int y = int(bY+(i*cos(ci::toRadians(float(st)))));
            int rad = floor(st/90);
            if(!isset.at(rad)){
                if(x>0 && y>0 && x<surf.getWidth() && y<surf.getHeight()){
                    ci::ColorAT<unsigned char> c = surf.getPixel(ci::Vec2i(x, y));
                    Boolean go;
                    if(negative){
                        ci::gl::color(255, 0,0);
                        if(c.r-treshold>avg.r && c.b-treshold>avg.b && c.g-treshold>avg.g){
                            ci::gl::drawSolidCircle(ci::Vec2i(ar.x1+x+oX, ar.y1+y+oY), 1);
                            go = true;
                        } else {
                            go = false;
                        }
                    } else {
                        if(c.r<avg.r-treshold && c.b<avg.b-treshold && c.g<avg.g-treshold){
                            ci::gl::drawSolidCircle(ci::Vec2i(ar.x1+x+oX, ar.y1+y+oY), 1);
                            go = true;
                        } else {
                            go = false;
                        }
                    }
                    if(go){
                        if(x>0 && y>0 && x<surf.getWidth() && y<surf.getHeight()){
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
            ci::gl::pushMatrices();
            ci::gl::translate(surf.getBounds().x1, surf.getBounds().y1);
            ci::gl::drawSolidCircle(ci::Vec2i(ar.x1+x+oX, ar.y1+y+oY), 1);
            ci::gl::popMatrices();
            Boolean go;
            if(negative){
                if(c.r-treshold>avg.r && c.b-treshold>avg.b && c.g-treshold>avg.g){
                    go = true;
                } else {
                    go = false;
                }
            } else {
                if(c.r<avg.r-treshold && c.b<avg.b-treshold && c.g<avg.g-treshold){
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
    
    ci::gl::drawStringCentered(ci::toString(total), ci::Vec2i(ar.x1+(ar.x2-ar.x1)/2, ar.y1-50));
    ci::Vec2i p = ((points.at(0)+points.at(1)+points.at(2)+points.at(3))/4);
    p.x+=int(ar.getCenter().x);
    p.y+=int(ar.getCenter().y);
    return total;
}
ci::Surface Track::returnSurf(ci::Area ar){
    return c.clone(ar);
}
Boolean Track::trackGreen(ci::Area ar){
    ci::ColorAT<unsigned char> col;
    col = c.areaAverage(ar);
    if(col.g-col.b>treshold && col.g-col.r>treshold){
        return true;
    } else {
        return false;
    }
}
Boolean Track::trackRed(ci::Area ar){
    ci::ColorAT<unsigned char> col;
    col = c.areaAverage(ar);
    if(col.r-col.b>treshold && col.r-col.g>treshold){
        return true;
    } else {
        return false;
    }
}

Boolean Track::checkExistance(int tagId){
    for(int i = 0; i<tags.size(); i++){
        if(tags.at(i)==tagId){
            return true;
        }
    }
    return false;
}
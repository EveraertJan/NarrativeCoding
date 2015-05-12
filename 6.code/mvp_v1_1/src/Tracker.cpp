//
//  Tracker.cpp
//  mvp_v1_1
//
//  Created by jan everaert on 08/05/15.
//
//

#include "Tracker.h"

void Tracker::setup(){
    isGreen = false;
}

int Tracker::getCode(ci::Surface surf, Boolean inv){
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
                    if(inv){
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
            ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
            Boolean go;
            if(inv){
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

void Tracker::getCorners(ci::Surface s){
    std::vector<ci::Vec2i> arr;
    Boolean tb = false;
    ci::gl::color(255, 255, 255);
    ci::gl::color(0, 0, 255);
    int treshold = 20;
    cinder::ColorAT<unsigned char> c = s.getPixel(trackPos);
    if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
        tb = true;
        isGreen = false;
    } else if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
        tb = false;
        isGreen = true;
    }
    
    
    
    for(int i = 0; i<360; i+=5){
        for (int j = 0; j<50; j+=5) {
            int x = int(trackPos.x+(j*sin(ci::toRadians(float(i)))));
            int y = int(trackPos.y+(j*cos(ci::toRadians(float(i)))));
            
            
            ci::ColorAT<unsigned char> c = s.getPixel(ci::Vec2i(x, y));
            if(tb){
                if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
                    ci::gl::color(0, 0, 255);
                    //gl::drawSolidCircle(Vec2i(x, y), 2);
                    arr.push_back(ci::Vec2i(x, y));
                }
            } else {
                ci::gl::color(0, 255, 0);
                if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
                    //gl::drawSolidCircle(Vec2i(x, y), 2);
                    arr.push_back(ci::Vec2i(x, y));
                }
            }
        }
    }
    if(arr.size()>10){
        ci::Vec2i total;
        for(int i = 0; i<arr.size(); i++){
            total.x+=arr[i].x;
            total.y+=arr[i].y;
        }
        total.x = total.x/arr.size();
        total.y = total.y/arr.size();
        trackPos = total;
    } else {
        isGreen = false;
    }
    ci::gl::drawSolidCircle(trackPos, 2);
    arr.clear();
    
    for(int i = 0; i<360; i+=5){
        for (int j = 0; j<50; j+=5) {
            int x = int(trackPos2.x+(j*sin(ci::toRadians(float(i)))));
            int y = int(trackPos2.y+(j*cos(ci::toRadians(float(i)))));
            
            
            ci::ColorAT<unsigned char> c = s.getPixel(ci::Vec2i(x, y));
            if(tb){
                if((c.b - c.r)>treshold && (c.b - c.g)>treshold){
                    ci::gl::color(0, 0, 255);
                    arr.push_back(ci::Vec2i(x, y));
                }
            } else {
                if((c.g - c.b)>treshold && (c.g - c.r)>treshold){
                    ci::gl::color(0, 255, 0);
                    arr.push_back(ci::Vec2i(x, y));
                }
            }
            
        }
    }
    if(arr.size()>10){
        ci::Vec2i total;
        for(int i = 0; i<arr.size(); i++){
            total.x+=arr[i].x;
            total.y+=arr[i].y;
        }
        total.x = total.x/arr.size();
        total.y = total.y/arr.size();
        trackPos2 = total;
    } else {
        isGreen = false;
    }
    

}
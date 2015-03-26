//
//  Detect.cpp
//  CinderProject
//
//  Created by jan everaert on 21/03/15.
//
//

#include "BoardDetect.h"
void Detect::setup(ci::Area r){
    scanArea = r;
    b = *new Board();
}
void Detect::draw(){
    if(b.isFound){
        b.draw();
    }
}
void Detect::scan(cinder::Surface s){
    if(b.isFound){
        scanOld(s);
    } else {
        if(scanDetect(s)){
            ci::Surface scanSurf;
            scanSurf = s.clone(scanArea);
            scanNew(scanSurf);
            b.tagNum = readTag(scanSurf);
        }
    }
}
void Detect::scanOld(ci::Surface s){
    ci::Vec2f oldC = ci::Vec2f(b.center.x, b.center.y);
    std::vector<ci::Vec2f>points;
    points.push_back(oldC);
    points.push_back(oldC);
    points.push_back(oldC);
    points.push_back(oldC);
    for(int i = 0; i<360; i+=5){
        float dist= oldC.distance(b.points[0])*1.2;
        if(dist<50){
            dist = 50;
        }
        for(int j = 10; j<dist; j+=5){
            int xp = oldC.x+(j*cos(ci::toRadians((float)i)));
            int yp = oldC.y+(j*sin(ci::toRadians((float)i)));
            ci::Vec2i pos = ci::Vec2i(xp, yp);
            ci::gl::color(0, 200, 200);
            if(pos.x>0 && pos.y>0 && pos.x<s.getWidth() && pos.y<s.getHeight()){
                cinder::ColorT<unsigned char> c = s.getPixel(pos);
                if(c.r+c.g+c.b < detectThreshold){
                    int quart = floorf((i/90));
                    if(oldC.distance(pos)>oldC.distance(points[quart])){
                        points[quart] = pos;
                    }
                }
            }
        }
    }
    ci::gl::drawSolidCircle(b.center, 3);
    float rot = 0;
    float dx = points[3].x-points[2].x;
    float dy = points[3].y-points[2].y;
    
    rot=ci::toDegrees(atan2(dy, dx));
    b.rotation.push_back(rot);
        b.points =points;
    float x;
    float y;
    for(int i = 0; i<points.size(); i++){
        x +=points[i].x;
        y +=points[i].y;
    }
    b.center = ci::Vec2f(x/points.size(), y/points.size());
    points.clear();

    ci::Area sArea = ci::Area(b.points[2].x-50, b.points[2].y-50, b.points[0].x+50, b.points[0].y+50);
    ci::Surface surf = s.clone(sArea);
    if(readTag(surf) == 0){
        b.isFound = false;
    }
    
}
Boolean Detect::scanDetect(cinder::Surface s){
    cinder::ColorT<unsigned char> ch = s.areaAverage(scanArea);
    if(ch.r+ch.g+ch.b<detectThreshold*3){
        return true;
    } else {
        return false;
    }
}
int Detect::readTag(ci::Surface s){
    std::vector<ci::Vec2f> v= b.points;
    int steps = 4;
    int bit = 1;
    int total = 0;
    for(int j = 1; j<steps; j++) {
        for(int i = 1; i<steps; i++){
            float xos = (((v[1].x-v[2].x)/steps)*j);
            float xoe = (((v[0].x-v[3].x)/steps)*j);
            float x = (v[2].x+xos) + (((v[3].x+xoe)-(v[2].x+xos))/steps)*i;
            
            float yos = (((v[3].y-v[2].y)/steps)*i);
            float yoe = (((v[0].y-v[1].y)/steps)*i);
            float y = (v[2].y+yos) + (((v[1].y+yoe)-(v[2].y+yos))/steps)*j;
            cinder::ColorT<unsigned char> c = s.getPixel(ci::Vec2i((int)x, (int)y));
            if(c.r+c.g+c.b> detectThreshold){
                total+=bit;
            }
            bit = bit*2;
            
            
        }
    }
    ci::app::console() << total << "\n";
    return total;
}
void Detect::scanNew(ci::Surface s){
    float w = s.getWidth();
    float h = s.getHeight();
    ci::Vec2f center = ci::Vec2f(w/2, h/2);
    std::vector<ci::Vec2f>points;
    points.push_back(center);
    points.push_back(center);
    points.push_back(center);
    points.push_back(center);
    for(int i = 0; i<360; i+=5){
        for(int j = 10; j<s.getWidth()/1.5; j+=5){
            int xp = w/2+(j*cos(ci::toRadians((float)i)));
            int yp = h/2+(j*sin(ci::toRadians((float)i)));
            ci::Vec2i pos = ci::Vec2i(xp, yp);
            if(pos.x>0 && pos.y>0 && pos.x<s.getWidth() && pos.y<s.getHeight()){
                cinder::ColorT<unsigned char> c = s.getPixel(pos);
                if(c.r+c.g+c.b < detectThreshold){
                    int quart = floorf((i/90));
                    if(center.distance(pos)>center.distance(points[quart])){
                        points[quart] = pos;
                    }
                }
            }
        }
    }
    float rot = 0;
    float dx = points[0].x-scanArea.getCenter().x;
    float dy = points[0].y-scanArea.getCenter().y;
    rot+=ci::toDegrees(atan2f(dy, dx));
    
    ci::app::console() << "rotation: " << rot/4 << "\n";
    b.setup(points);
    float x;
    float y;
    for(int i = 0; i<points.size(); i++){
        x +=points[i].x;
        y +=points[i].y;
    }
    b.center = ci::Vec2f((x/points.size())+scanArea.getX1(), (y/points.size())+scanArea.getY1());
    ci::app::console() << b.center << "center;\n";
    b.rotation.push_back(rot);
    b.isFound = true;
}

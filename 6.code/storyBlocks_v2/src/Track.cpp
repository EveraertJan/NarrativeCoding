//
//  Track.cpp
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#include "Track.h"

void Track::trackBook(ci::Surface surf){
    //tracking corners
    
    //update cornerTopPos;
    // update cornerBottomPos
    std::vector<ci::Vec2i> pos;
    for(int i = 0; i<180; i+=2){
        for(int j = 0; j<20; j++){
            float x = cornerTopPos.x+(j*sin(ci::toRadians(float(i))));
            float y = cornerTopPos.y+(j*cos(ci::toRadians(float(i))));
            
            ci::ColorAT<unsigned char> c;
            c = surf.getPixel(ci::Vec2i(x, y));
            if(c.r-c.g<0 && c.b-c.g<0){
                pos.push_back(ci::Vec2i(x, y));
            }
        }
    }
    ci::Vec2i total;
    for(int i = 0; i<pos.size(); i++){
        total.x += pos.at(i).x;
        total.y += pos.at(i).y;
    }
    if(pos.size()>0){
        total.x = total.x/pos.size();
        total.y = total.y/pos.size();
    }
    
    //naar rechts::1120
    //naar links: 1600
    // naar onder: 2144
    //naar bove: 1552
    tags.push_back(1120);
    tags.push_back(1600);
    tags.push_back(2144);
    tags.push_back(1552);
    
}

ci::Area Track::getBounds(ci::Surface surf){
    
    int xp = ci::app::getWindowCenter().x;
    int yp = ci::app::getWindowCenter().y;
    ci::ColorAT<unsigned char> ref = surf.getPixel(ci::Vec2i(0, 0));
    
    for(int i = 0; i<360; i++){
        for(int j = 0; j<ci::app::getWindowWidth()/2; j+=5){
            float x = xp+(j*sin(ci::toRadians(float(i))));
            float y = yp+(j*cos(ci::toRadians(float(i))));
            
            ci::ColorAT<unsigned char> c = surf.getPixel(ci::Vec2i(x, y));
            if(c.r>ref.r && c.g>ref.g && c.b>ref.b){
                //still in proj
                ci::gl::color(255, 0, 0);
                ci::gl::drawSolidCircle(ci::Vec2i(x, y), 2);
            }
        }
    }
}


Boolean Track::greenScan(ci::Surface greenArea){
    ci::ColorAT<unsigned char> c;
    c = greenArea.areaAverage(greenArea.getBounds());
    if(c.g-c.b>threshold && c.g-c.r>threshold){
        return true;
    } else {
        return false;
    }
}

int Track::trackcode(ci::Surface surf, ci::Vec2i areaP, Boolean negative){
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
                            //ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
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
            ci::gl::drawSolidCircle(ci::Vec2i(x+oX, y+oY), 3);
            ci::gl::popMatrices();
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
    ci::gl::drawStringCentered(ci::toString(total), ci::app::getWindowCenter());
    ci::Vec2i p = ((points.at(0)+points.at(1)+points.at(2)+points.at(3))/4);
    p.x+=int(areaP.x);
    p.y+=int(areaP.y);
    if(checkExistance(total) && checkInArray(p)){
        tagPos.push_back(p);
    }
    return total;
    
}
Boolean Track::checkInArray(ci::Vec2i pos){
    int results = 0;
    for(int i = 0; i<tagPos.size(); i++){
        if(pos.distance(tagPos.at(i))<100){
            results++;
        }
    }
    if(results == 0){
        return true;
    } else {
        return false;
    }
}

void Track::followTags(ci::Surface surf){
    for(int k = 0; k<tagPos.size(); k++){
        ci::Vec2i curPos = tagPos.at(k);
        //ci::Area a = ci::Area(curPos.x-100, curPos.y-100, curPos.x+100, curPos.y+100);
        // ci::ColorAT<unsigned char> c = surf.areaAverage(a);
        //th = (c.r+c.g+c.b)/3;
        int tpx = 0;
        int tpy = 0;
        int count = 0;
        std::vector<Boolean>blocked;
        for(int i = 0; i<360; i++){
            blocked.push_back(false);
        }
        for(int j = 0; j<55; j+=4){
            for(int i = 0; i<360; i+=5){
            if(!blocked.at(i)){
                    int x = curPos.x + (j*sin(ci::toRadians(float(i))));
                    int y = curPos.y + (j*cos(ci::toRadians(float(i))));
                    ci::ColorAT<unsigned char> cc = surf.getPixel(ci::Vec2i(x, y));
                    if(cc.r>tagThreshold && cc.g>tagThreshold && cc.b<tagThreshold){
                        ci::gl::color(50*k, 0, 50*k);
                        ci::gl::drawSolidEllipse(ci::Vec2i(x, y), 2, 2);
                        tpx+=x;
                        tpy+=y;
                        count++;
                    } else if(cc.r>tagThreshold && cc.b>tagThreshold && cc.g>tagThreshold){
                        blocked.at(i) = true;
                        ci::gl::color(50*k, 255, 50*k);
                        ci::gl::drawSolidEllipse(ci::Vec2i(x, y), 2, 2);
                    }
                }
            }
        }
        if(count>0){
            tagPos.at(k).x = int(tpx/count);
            tagPos.at(k).y = int(tpy/count);
        }
        
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

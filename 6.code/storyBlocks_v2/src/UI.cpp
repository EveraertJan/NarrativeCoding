//
//  UI.cpp
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#include "UI.h"

ci::Area UI::showBookScan(){
    ci::gl::color(255, 255, 255);
    cx = ci::app::getWindowWidth()/2;
    cy = ci::app::getWindowHeight()/2;
    ci::Area a = ci::Area(cx-tagSize, cy-tagSize, cx+tagSize, cy+tagSize);
    ci::gl::drawStrokedRect(ci::Rectf(a));
    ci::gl::drawStringCentered("scan a book", a.getCenter());
    return a;
}

ci::Area UI::showGreenCard(){
    ci::gl::color(255, 255, 255);
    ci::Area a = ci::Area(cx-tagSize, cy*2-200, cx+tagSize, cy*2-200+tagSize*2);
    ci::gl::drawSolidRect(ci::Rectf(a));
    ci::gl::color(0, 255, 0);
    ci::gl::drawSolidRect(ci::Rectf(a.getCenter().x-10, a.getCenter().y-15, a.getCenter().x+10, a.getCenter().y+15));
    ci::gl::drawStringCentered("scan", ci::Vec2i(a.getCenter().x, a.getCenter().y-30));
    return a;
}
ci::Area UI::TagScan(){
    ci::gl::color(255, 255, 255);
    ci::Area a = ci::Area(cx-tagSize-100, cy*2-200, cx+tagSize-100, cy*2-200+tagSize*2);
    ci::gl::drawStrokedRect(ci::Rectf(a));
    ci::gl::color(255, 255, 255);
    ci::gl::drawSolidRect(ci::Rectf(a.getCenter().x-10, a.getCenter().y-15, a.getCenter().x+10, a.getCenter().y+15));
    ci::gl::drawStringCentered("scan", ci::Vec2i(a.getCenter().x, a.getCenter().y-30));
    return a;

}

void UI::tutorial(){
    ci::gl::drawString("drawing tutorial", ci::app::getWindowCenter());
    
    
}

void UI::showTagConnections(std::vector<ci::Vec2i> tags){
    for(int i = 0; i<tags.size(); i++){
        ci::gl::color(255, 255, 255);
        ci::gl::drawSolidEllipse(tags.at(i), 5, 5);
        int dist = 200;
        for(int j = i; j<tags.size(); j++){
            if(tags.at(i).distance(tags.at(j))<dist){
                ci::gl::lineWidth(2);
                ci::gl::drawLine(tags.at(i), tags.at(j));
                //ci::gl::drawStringCentered("tracking", ci::Vec2f(ci::app::getWindowCenter().x, ci::app::getWindowCenter().y+30));
            }
        }
    }/*
    ci::Vec2i last = ci::Vec2i(0, 0);
    for(int x = 0; x<ci::app::getWindowWidth(); x++){
        for(int i = 0; i<tags.size(); i++){
            if(tags.at(i).x == x){
                if(last.x !=0){
                    ci::gl::color(255, 255, 255);
                    ci::gl::drawSolidEllipse(tags.at(i), 5, 5);
                    ci::gl::drawLine(last, tags.at(i));
                    last = tags.at(i);
                }
            }
        }
    }*/
}
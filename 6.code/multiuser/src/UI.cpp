//
//  UI.cpp
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

#include "UI.h"


void UI::showSettings(){
    ci::gl::color(255, 255, 255);
    ci::gl::drawStringCentered("in settings", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    ci::gl::drawStringCentered("use the settings to ajust the mapping", ci::Vec2i(ci::app::getWindowCenter().x, 200));
    settingsVis = true;
    
}

void UI::showScanner(ci::Area ar){
    ci::gl::clear();
    ci::gl::color(255, 255, 255);
    ci::gl::drawSolidRect(ci::Rectf(ar));
    ci::gl::drawStringCentered("in bookscan", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    settingsVis = false;
}


void UI::showCodeMomentScanner(ci::Area ar){
    ci::gl::color(255, 255, 255);
    ci::gl::drawSolidRect(ci::Rectf(ar));
    ci::gl::drawStringCentered("scan codemoment", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    settingsVis = false;
}

void UI::showGreenScanner(ci::Area ar){
    ci::gl::color(255, 255, 255);
    ci::gl::drawSolidRect(ci::Rectf(ar));
    ci::gl::drawStringCentered("scan green card", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    settingsVis = false;
}
void UI::showCodeMoment(CodeMoment cm, ci::Area ar){
    ci::gl::color(255, 255, 255);
    ci::gl::drawString(ci::toString(cm.id), ci::Vec2i(ci::app::getWindowWidth()-300, 100));
    ci::gl::drawString(ci::toString(cm.numcards), ci::Vec2i(ci::app::getWindowWidth()-300, 130));
    
    ci::Surface back = ci::loadImage(ci::loadUrl(cm.backgroundurl));
    ci::Vec2i c = ci::Vec2i(ci::app::getWindowCenter().x, 400);
    int imgSize = 600/2;
    ci::gl::draw(ci::gl::Texture(back), ci::Rectf(c.x-imgSize, c.y-imgSize, c.x+imgSize, c.y+imgSize));
    
    int tagSize = ar.x2-ar.x1;
    
    std::vector<Area>sa;
    for(int i =0; i< cm.numcards+1; i++){
        Vec2i p = Vec2i((getWindowWidth()/2-imgSize+(tagSize/2))+(i*(tagSize+20)), getWindowHeight()/2+imgSize);
        Area a = Area(p.x-tagSize/2, p.y-tagSize/2, p.x+tagSize/2, p.y+tagSize/2);
        if(i<cm.numcards+1){
            gl::drawSolidRect(Rectf(a));
        } else {
            gl::color(0, 255, 0);
            gl::drawStrokedRect(Rectf(a));
        }
        sa.push_back(a);
    }
    
    scanArs = sa;
    
    
    
}
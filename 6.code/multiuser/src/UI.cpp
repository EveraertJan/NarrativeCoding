//
//  UI.cpp
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
// deze class dient enkel en alleen voor het uitprojecteren van scanvelden en andere info
//

#include "UI.h"


void UI::showSettings(){
    ci::gl::color(255, 255, 255);
    ci::gl::drawStringCentered("in settings", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    ci::gl::drawStringCentered("use the settings to ajust the mapping", ci::Vec2i(ci::app::getWindowCenter().x, 200));
    settingsVis = true;
    imgSet = false;
    
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

void UI::showGreenScanner(ci::Area ar, std::string info){
    gl::color(255, 255, 255);
    ci::gl::drawStrokedRect(ci::Rectf(ar));
    //ci::gl::drawStringCentered("scan green card", ci::Vec2i(ci::app::getWindowCenter().x, 100));
    ci::gl::drawStringCentered(info, ci::Vec2i(ci::app::getWindowCenter().x, 100));
    settingsVis = false;
}
void UI::showCodeMoment(CodeMoment cm, ci::Area ar, Vec2i pos){
    ci::gl::color(255, 255, 255);
    ci::gl::drawString(ci::toString(cm.id), ci::Vec2i(ci::app::getWindowWidth()-300, 100));
    ci::gl::drawString(ci::toString(cm.maxCards), ci::Vec2i(ci::app::getWindowWidth()-300, 130));
    ci::gl::drawString(ci::toString(cm.tags.size()), ci::Vec2i(ci::app::getWindowWidth()-300, 160));
    
    
    if(!imgSet){
        back = ci::loadImage(ci::loadUrl(cm.backgroundurl));
    } else {
    }
    ci::Vec2i c = ci::Vec2i(ci::app::getWindowCenter().x, 400);
    int imgSize = 600/2;
    ci::gl::draw(ci::gl::Texture(back), ci::Rectf(c.x-imgSize, c.y-imgSize, c.x+imgSize, c.y+imgSize));
    Vec2i base = Vec2i(c.x-imgSize, c.y-imgSize);
    gl::color(255, 255, 0);
    ci::gl::drawSolidRect(Rectf(base.x+(pos.x*imgSize/5), base.y+(pos.y*imgSize/5), base.x+(pos.x*imgSize/5)+(imgSize/5), base.y+(pos.y*imgSize/5)+(imgSize/5)));

    int tagSize = ar.x2-ar.x1;
    
    ci::gl::color(255, 255, 255);
    std::vector<Area>sa;
    
    for(int i = 0; i<cm.tags.size()+1; i++){
        Vec2i p = Vec2i((getWindowWidth()/4-imgSize+(tagSize/2))+(i*(tagSize+20)), getWindowHeight()/2+imgSize);
        Area a = Area(p.x-tagSize/2, p.y-tagSize/2, p.x+tagSize/2, p.y+tagSize/2);
        if(i<cm.tags.size()+1){
            gl::drawStrokedRect(Rectf(a));
        } else {
            gl::color(0, 255, 0);
            gl::drawStrokedRect(Rectf(a));
        }
        sa.push_back(a);
    }
    
    scanArs = sa;
}

void UI::showOutput(CodeMoment cm, ci::Area ar, Vec2i pos){
    gl::color(255, 255, 255);
    ci::Vec2i c = ci::Vec2i(ci::app::getWindowCenter().x, 400);
    int imgSize = 600/2;
    ci::gl::draw(ci::gl::Texture(back), ci::Rectf(c.x-imgSize, c.y-imgSize, c.x+imgSize, c.y+imgSize));
    Vec2i base = Vec2i(c.x-imgSize, c.y-imgSize);
    gl::color(255, 255, 0);
    ci::gl::drawSolidRect(Rectf(base.x+(pos.x*imgSize/5), base.y+(pos.y*imgSize/5), base.x+(pos.x*imgSize/5)+(imgSize/5), base.y+(pos.y*imgSize/5)+(imgSize/5)));
    
}
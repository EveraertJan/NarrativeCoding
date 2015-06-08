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

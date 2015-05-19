//
//  Interface.cpp
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#include "Interface.h"


void Interface::setup(float sc){
    scale = sc;
    DCX = ci::app::getWindowWidth()/2;
    DCY = ci::app::getWindowHeight()/2;
    bookWidth = 145*scale;
    bookHeight = 210*scale;
    scanSize = 50*scale;
}

void Interface::drawBookScan(){
    scanAreas.clear();
    //first frame, welcome and area for bookScanning
    //set scanarea to center of book;
    bookArea = ci::Area(DCX-bookWidth/2, DCY-bookHeight/2, DCX+bookWidth/2, DCY+bookHeight/2);
    ci::gl::color(255, 255, 255);
    ci::gl::drawStrokedRect(ci::Rectf(bookArea));
    scanAreas.push_back(getArea(DCX, DCY-(50*scale)));
    drawAreas();
    
}
void Interface::drawGreenCard(){
    
    //first page, place greencard in place to advance
    //set greencard area
    greenCard = getArea(DCX, DCY+100*scale);
    ci::gl::color(255, 255, 255);
    ci::gl::drawStrokedRect(ci::Rectf(greenCard));
    
}

void Interface::drawCodeMoment(int numFields){
    
}
void Interface::drawFinal(){
    
}
void Interface::drawTutorialOverlay(){
    
}
void Interface::updateBookPos(ci::Vec2i bookTop, ci::Vec2i bookDown){
    
}

ci::Area Interface::getArea(int x, int y){
    return ci::Area(x-scanSize/2, y-scanSize/2, x+scanSize/2, y+scanSize/2);
}

void Interface::drawAreas(){
    ci::gl::color(255, 255, 255);
    for(int i = 0; i<scanAreas.size(); i++){
        ci::gl::drawStrokedRect(ci::Rectf(scanAreas.at(i)));
    }
}
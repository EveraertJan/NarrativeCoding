//
//  Character.cpp
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#include "Character.h"

void Character::setup(int startX, int startY){
    x = startX;
    y = startY;
    rot = 0;
}

void Character::updatePos(ci::Vec2i pos){
    if(x<pos.x){
        rot = 90;
    } else if(x>pos.x){
        rot = 270;
    }
    if(y<pos.y){
        rot = 180;
    } else if(y>pos.y){
        rot = 0;
    }
    y = pos.y;
    x = pos.x;
    ci::app::console() << x << "\n";
}

void Character::draw(){
    ci::gl::pushMatrices();
    ci::gl::translate(x*50, y*50);
    ci::gl::drawSolidRect(ci::Rectf(0, 0, 50, 50));
    ci::gl::popMatrices();
}

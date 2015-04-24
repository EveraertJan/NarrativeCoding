
//
//  User.cpp
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#include "User.h"


void User::setup(){
    
}
void User::update(int x, int y){
    xPos = x;
    yPos = y;
}
void User::draw(ci::Surface surf){
    cinder::gl::pushMatrices();
    ci::gl::translate(-300, -200);
    ci::gl::rotate(rotation);
    ci::gl::translate(xPos, yPos);
    ci::gl::color(255, 255, 255);
    ci::gl::drawSolidRect(ci::Rectf(xAdj, yAdj, 600, 400));
    ci::gl::popMatrices();
}
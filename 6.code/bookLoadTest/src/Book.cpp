//
//  Book.cpp
//  bookLoadTest
//
//  Created by jan everaert on 04/05/15.
//
//

#include "Book.h"


void Book::setup(int c){
    code = c;
    isFound = false;
    try{
        cover = loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/bookCover_"+ci::toString(code)+".png"));
        //cover = loadImage( cinder::app::loadAsset( "bookCover_"+ci::toString(code)+".png" ) );
        isFound = true;
    } catch ( ... ){
        ci::app::console() << "asset not found ";
    }
}
void Book::update(){
    
}
void Book::draw(){
    if(isFound && codeMoment){
        
        float dX = dispPosDown.x-dispPosTop.x;
        float dY = dispPosDown.y-dispPosTop.y;
        
        float angleD = (atan2f(dY, dX)*180/pi)-90;
        //ci::app::console() << angleD << "\n";
        
        ci::gl::pushMatrices();
        ci::gl::translate(dispPosTop.x-180+20, dispPosTop.y+290-10);
        ci::gl::rotate(angleD);
        ci::gl::enableAlphaBlending();
        ci::gl::draw(cover, ci::Vec2f(-180, -280));
        ci::gl::disableAlphaBlending();
        ci::gl::popMatrices();
    }
}


Boolean Book::exists(int c){
    if(c==1552){
        return true;
    } else {
        return false;
    }
}
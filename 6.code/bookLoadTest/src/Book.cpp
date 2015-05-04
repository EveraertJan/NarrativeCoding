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
        if(code == 1552){
            cover = loadImage( cinder::app::loadAsset( "bookCover_1552.png" ) );
            isFound = true;
        }
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
        ci::app::console() << angleD << "\n";
        
        ci::gl::pushMatrices();
        ci::gl::translate(dispPosTop.x-360+10, dispPosTop.y-10);
        ci::gl::rotate(angleD);
        ci::gl::draw(cover);
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
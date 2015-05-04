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
    if(isFound){
        ci::gl::pushMatrices();
        ci::gl::translate(ci::app::getWindowWidth()/2-190, ci::app::getWindowHeight()/2-290);
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
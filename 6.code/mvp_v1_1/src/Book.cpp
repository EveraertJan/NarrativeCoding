//
//  Book.cpp
//  mvp_v1_1
//
//  Created by jan everaert on 08/05/15.
//
//

#include "Book.h"

void Book::setup(int c){
    bookCode = c;
    isFound = false;
    if(c!=0){
    try{
        cover = loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/bookCover_"+ci::toString(bookCode)+".png"));
        //cover = loadImage( cinder::app::loadAsset( "bookCover_"+ci::toString(code)+".png" ) );
        isFound = true;
    } catch ( ... ){
        ci::app::console() << "asset cover not found ";
    }
    }
}

void Book::update() {
    
}

void Book::draw(int size){
    
}

Boolean Book::exists(int c){
    //dynamic read
    if(c==1552){
        return true;
    } else {
        return false;
    }
}
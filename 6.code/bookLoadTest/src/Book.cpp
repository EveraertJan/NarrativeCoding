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
    cover = loadImage( cinder::app::loadAsset( "bookCover_1552.png" ) );
        isFound = true;
    } catch ( ... ){
        ci::app::console() << "asset not found ";
    }
}
void Book::update(){
    
}
void Book::draw(){
    if(isFound){
        ci::gl::draw(cover);
    }
    
}


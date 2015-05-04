//
//  Book.h
//  bookLoadTest
//
//  Created by jan everaert on 04/05/15.
//
//

#pragma once
#include "cinder/gl/Texture.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"

class Book{
public:
    void setup(int c);
    void draw();
    void update();
    Boolean exists(int c);
    int code;
    Boolean scanned;
    Boolean codeMoment;
    
    Boolean isFound;
    ci::gl::Texture cover;
    
    ci::Vec2i dispPosTop;
    ci::Vec2i dispPosDown;
    
};
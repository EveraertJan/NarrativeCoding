//
//  Book.h
//  mvp_v1_1
//
//  Created by jan everaert on 08/05/15.
//
//

#pragma once

#include "cinder/Utilities.h"
#include "cinder/gl/Texture.h"

class Book{
public:
    void setup(int code);
    void update();
    void draw(int size);
    Boolean exists(int code);
    
    ci::gl::Texture cover;
    
    int bookCode;
    
    Boolean scanned;
    Boolean codeMoment;
    
    Boolean isFound;
    
    ci::Vec2i dispPosTop;
    ci::Vec2i dispPosDown;
    
};
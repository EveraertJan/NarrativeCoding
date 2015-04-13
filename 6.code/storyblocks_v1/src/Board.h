//
//  Board.h
//  storyblocks_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Board{
public:
    void setup(int x, int y, int r);
    void setup();
    
    void updatePos(int x, int y, int r);
    void updateStory(int rate);
    void draw(ci::Surface s);
    
    int xpos;
    int ypos;
    int rot;
    
    int storypos;
    
    
};
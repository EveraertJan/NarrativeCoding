//
//  User.h
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class User{
public:
    void setup();
    void update(int x, int y);
    void draw(ci::Surface surf);
    
    int hoofdstuk;
    
    std::vector<int> code;
    
    int xPos;
    int yPos;
    int xAdj = 0;
    int yAdj = 0;
    int rotation = 0;
};
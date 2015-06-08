//
//  Track.h
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//
#pragma once
#include "Cam.h"

class Track{
public:
    void setup();
    void update();
    void draw();
    int trackTag(ci::Area ar, Boolean negative);
    Boolean trackGreen(ci::Area ar);
    Boolean checkExistance(int tagId);
    
    
    
    Cam cam;
    Vec2i ul;
    Vec2i ur;
    Vec2i dl;
    Vec2i dr;
    
    std::vector<int> tags;
    
    int treshold;
};
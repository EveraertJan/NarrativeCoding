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
    void draw(Boolean showCam);
    int trackTag(ci::Area ar, Boolean negative);
    Boolean trackGreen(ci::Area ar);
    Boolean trackRed(ci::Area ar);
    Boolean checkExistance(int tagId);
    void saveSurf();
    
    
    ci::Surface returnSurf(ci::Area ar);
    
    Cam cam;
    Vec2i ul;
    Vec2i ur;
    Vec2i dl;
    Vec2i dr;
    
    ci::Surface c;
    
    std::vector<int> tags;
    int treshold;
};
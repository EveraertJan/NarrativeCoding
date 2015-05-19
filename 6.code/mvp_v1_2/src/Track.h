//
//  Track.h
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#pragma once
#include "Cam.h"
class Track{
public:
    void setup();
    void update();
    void draw();
    
    
    ci::Vec2i updateCorner(ci::Vec2i curPos);
    int getPageCode(ci::Vec2i top, ci::Vec2i bottom);
    int getTagId(ci::Area scan, Boolean neg);
    
    Boolean greenCard(ci::Area cardArea);
    
    ci::Surface curScreen;
    Cam cam;
};
//
//  Tracker.h
//  mvp_v1_1
//
//  Created by jan everaert on 08/05/15.
//
//

#pragma once
#include "cinder/Surface.h"

class Tracker{
public:
    void setup();
    void getCorners(ci::Surface s);
    int getCode(ci::Surface s, Boolean inv);
    
    
    ci::Vec2i trackPos;
    ci::Vec2i trackPos2;
    
    Boolean isGreen;
};
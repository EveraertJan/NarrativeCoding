//
//  TagDetect.h
//  gameEngine
//
//  Created by jan everaert on 25/04/15.
//
//

#pragma once

#include "cinder/gl/gl.h"
#include "Cam.h"



class TagDetect{
public:
    void setup();
    void update();
    void draw(ci::Surface surf);
    Cam webcam;
    void getCode(Area scanArea, ci::Surface s);
    float intAvg;
    ci::Surface getSurf();
    
    std::vector<int>tracked;
};

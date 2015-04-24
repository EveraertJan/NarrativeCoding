//
//  CodeMoment.h
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#pragma once
#include "cinder/app/AppBasic.h"
class CodeMoment{
public:
    void setup();
    void addSteps(int i);
    void addResult(int xpos, int ypos);
    void update();
    void draw();
    
    
    
    std::vector<int> FixedRes;
    ci::Vec2i endRes;
    std::vector<int> invoer;
};
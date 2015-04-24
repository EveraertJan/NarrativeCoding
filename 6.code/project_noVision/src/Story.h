//
//  Story.h
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#pragma once

#include "cinder/app/appBasic.h"
#include "Chapter.h"
#include "CodeMoment.h"

class Story{
public:
    
    void setup();
    void update();
    void setPages(std::vector<Chapter> pgs);
    void draw();
    
    std::vector<Chapter> pages;
};
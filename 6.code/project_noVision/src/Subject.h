//
//  Subject.h
//  project_noVision
//
//  Created by jan everaert on 22/04/15.
//
//

#pragma once

class Subject{
public:
    
    void setup(std::vector<ci::Surface>body,int x, int y, int rot);
    void draw();
    
    std::vector<ci::Surface> body;
    int xpos;
    int ypos;
    int rotation;
};
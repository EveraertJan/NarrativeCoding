//
//  CodeMoment.cpp
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#include "CodeMoment.h"

void CodeMoment::setup(){
}
void CodeMoment::addSteps(int i){
    FixedRes.push_back(i);
}
void CodeMoment::addResult(int xpos, int ypos){
    endRes = ci::Vec2i(xpos, ypos);
}
void CodeMoment::update(){
    
}
void CodeMoment::draw(){
    
}
//
//  CForLoop.h
//  project_noVision
//
//  Created by jan everaert on 22/04/15.
//
//
#pragma once
#include "CMovement.h"

class CForLoop{
    void createLoop();
    void AddToLoop(CMovement move);
    void runLoop();
    
    
    std::vector<CMovement> moveLoop;
    
};
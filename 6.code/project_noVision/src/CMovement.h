//
//  CMovement.h
//  project_noVision
//
//  Created by jan everaert on 22/04/15.
//
//

#pragma once

#include "cinder/app/appBasic.h"
#include "Subject.h"

class CMovement{
public:
    void moveLeft(Subject s);
    void moveRight(Subject s);
    void moveUp(Subject s);
    void moveDown(Subject s);
    
    int stepSize;
};
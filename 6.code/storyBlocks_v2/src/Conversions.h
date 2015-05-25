//
//  Conversions.h
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#pragma once
#include "cinder/app/appBasic.h"

class Conversions{
public:
    void setup(int totalMovements);
    void setMovement(int pointer, ci::Vec2i posC);
    ci::Vec2i getMovement(int pointer);
    Boolean isSet(int pointer);
    std::vector<ci::Vec2i> movements;
};
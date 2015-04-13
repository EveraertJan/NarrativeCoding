//
//  DetectTag.h
//  compiler_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#pragma once


#include "cinder/app/AppBasic.h"
#include "Board.h"

#include "Compiler.h"


class DetectTag{
    
public:
    void setup(ci::Area r);
    void scan(cinder::Surface s);
    Boolean scanDetect(cinder::Surface s);
    void scanNew(ci::Surface s);
    void scanOld(ci::Surface s);
    int readTag(ci::Surface s);
    void draw();
    ci::Area scanArea;
    
    Board b;
    float detectThreshold = 150;
    
    Compiler comp;
    
};
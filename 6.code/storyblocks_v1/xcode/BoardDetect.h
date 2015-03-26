
//
//  Detect.h
//  CinderProject
//
//  Created by jan everaert on 21/03/15.
//
//

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Thread.h"
#include "cinder/CinderMath.h"

#include "BoardGraph.h"

class Detect{
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
};
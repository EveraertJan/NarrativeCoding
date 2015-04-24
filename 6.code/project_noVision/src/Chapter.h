//
//  Chapter.h
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#pragma once
#include "CodeMoment.h"
#include "cinder/app/appBasic.h"


#include "Compiler.h"


class Chapter{
public:
    void setup();
    void create(ci::Surface s);
    void provision(std::vector<ci::Surface>page);
    void checkFixed();
    void checkResult();
    ci::Surface getPage(int num);
    
    
    std::vector<ci::Surface> pageS;
    std::vector<CodeMoment> moments;
    Compiler c;
};
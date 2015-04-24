//
//  Compiler.h
//  compiler_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#pragma once
#include "cinder/app/AppBasic.h"

class Compiler{
public:
    void setup();
    void compile();
    void setResult();
    
    
    std::vector<int> idArr;
    
    
};
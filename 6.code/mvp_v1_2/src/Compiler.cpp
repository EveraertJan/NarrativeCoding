//
//  Compiler.cpp
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#include "Compiler.h"

void Compiler::setup(std::vector<ci::Vec2i> blocks, std::vector<ci::Vec2i> dead){
    isBuild = false;
}


int Compiler::build(){
    return 0;
}

ci::Vec2i Compiler::translate(int code){
    
}

ci::Surface Compiler::drawOutput(int frame, ci::Surface mainChar){
    ci::Surface output;
    //draw corresponding frame, will include surface of main char
    return output;
}
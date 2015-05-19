//
//  Compiler.h
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#pragma once

class Compiler{
public:
    void setup(std::vector<ci::Vec2i> blocks, std::vector<ci::Vec2i> dead);
    int build();
    ci::Surface drawOutput(int frame, ci::Surface mainChar);
    ci::Vec2i translate(int code);
    
    Boolean isBuild;
    std::vector<int> cards;
};
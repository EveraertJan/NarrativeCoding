//
//  Level.h
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#pragma once

class Level{    
public:
    void setup(ci::Surface level, ci::Surface background);
    ci::Surface drawLevel();
    
    Boolean isBlock(ci::Vec2i place);
    Boolean isDead(ci::Vec2i place);
    
    std::vector<ci::Vec2i> blocks;
    std::vector<ci::Vec2i> dead;
    
    ci::Surface background;
    
    Boolean isset = false;
};
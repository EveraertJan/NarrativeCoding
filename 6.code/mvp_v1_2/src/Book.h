//
//  Book.h
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#pragma once
#include "Level.h"
#include "cinder/Utilities.h"
#include "Compiler.h"

class Book{
public:
    void setup(int code);
    void update(int page);
    Boolean Exists(int code);
    
    void setupLevel(int levelId);
    void drawCode(int level, Boolean greenCard);
    void setSteps(std::vector<int> steps);
    
    int id;
    
    Boolean isset = false;
    
    ci::Vec2i topPos;
    ci::Vec2i downPos;
    
    int curLevel;
    std::vector<Level> levels;
    Compiler compiler;
    
    ci::Surface cover;
};
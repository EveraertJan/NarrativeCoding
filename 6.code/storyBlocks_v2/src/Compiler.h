//
//  Compiler.h
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//
#pragma once

#include "cinder/app/appBasic.h"
#include "cinder/Utilities.h"
#include "cinder/gl/Texture.h"
#include "Character.h"
#include "Conversions.h"
#include "Resources.h"
class Compiler{
public:
    void setup(int code);
    void draw(Boolean play);
    
    Boolean compile();
    int validMove(ci::Vec2i move);
    void addBlock(ci::Vec2i pos);
    void addHole(ci::Vec2i pos);
    void drawScenery();
    void buildLevel(int level);
    
    void fillConversion();
    
    
    std::vector<ci::Vec2i> blocks;
    std::vector<ci::Vec2i> holes;
    
    Character ch;
    Conversions conv;
    
    ci::Surface background;
    
    int curPas;
    ci::Vec2i curPosition;
    
    std::vector<int> input;
    std::vector<ci::Vec2i> passes;
    
    Boolean running;
    Boolean died;
    
    
    int count;
    int maxCount = 1;
    
    
    
};
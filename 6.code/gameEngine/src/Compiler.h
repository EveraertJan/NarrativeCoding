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
#include "Character.h"
#include "Conversions.h"
#include "Resources.h"
class Compiler{
public:
    void setup();
    void draw(Boolean play);
    
    void compile();
    int validMove(ci::Vec2i move);
    void addBlock(ci::Vec2i pos);
    void addHole(ci::Vec2i pos);
    void drawScenery();
    
    void buildLevel();
    
    void fillConversion();
    
    
    std::vector<ci::Vec2i> blocks;
    std::vector<ci::Vec2i> holes;
    
    Character ch;
    Conversions conv;
    
    
    int curPas;
    ci::Vec2i curPosition;
    
    std::vector<int> input;
    std::vector<ci::Vec2i> passes;
    
    Boolean running;
    Boolean died;
    
    

};
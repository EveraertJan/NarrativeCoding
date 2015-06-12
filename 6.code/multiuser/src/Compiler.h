//
//  Compiler.h
//  multiuser
//
//  Created by jan everaert on 09/06/15.
//
//

#pragma once
#include "CodeMoment.h"
#include "Card.h"
#include "cinder/Utilities.h"
#include "cinder/gl/Texture.h"
#include "cinder/Xml.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Compiler{
public:
    void setup();
    void loadLevel(CodeMoment cm);
    std::string translate(int cardId);
    
    void compile(std::vector<int>tags, CodeMoment cm);
    
    Boolean checkDeath(Vec2i next);
    Boolean checkBlock(Vec2i next);
    Boolean play(int timeCode, CodeMoment cm);
    Boolean checkSpecial(int tag);
    
    Boolean compiled;
    
    std::vector<Vec2i>blocks;
    std::vector<Vec2i>death;
    std::vector<Vec2i>move;
    std::vector<Vec2i>go;
    Vec2i start;
    Vec2i pos;
    Vec2i end;
    
    Boolean achieved;
    
    std::vector<Card> cards;
    std::vector<int> exists;
    
    int curPlaying;
    int frameWait;
    
    Boolean levelSet;
    Boolean isset = false;
    
    
};
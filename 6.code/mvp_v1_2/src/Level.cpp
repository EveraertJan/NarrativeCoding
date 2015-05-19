//
//  Level.cpp
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#include "Level.h"


void Level::setup(ci::Surface level, ci::Surface background){
    //extract level and fill blocks;
    isset = true;
}

ci::Surface Level::drawLevel(){
    return background;
}

Boolean Level::isBlock(ci::Vec2i place){
    int blockCount = 0;
    for(int i = 0; i<blocks.size();i++){
        if(blocks.at(i) == place){
            blockCount++;
        }
    }
    //check in array
    if(blockCount>0){
        return true;
    } else {
        return false;
    }
}

Boolean Level::isDead(ci::Vec2i place){
    int deadCount = 0;
    for(int i = 0; i<dead.size();i++){
        if(dead.at(i) == place){
            deadCount++;
        }
    }
    //check in array
    if(deadCount>0){
        return true;
    } else {
        return false;
    }
}
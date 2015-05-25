//
//  Level.cpp
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#include "Level.h"

void Level::setLevel(ci::Surface s, ci::Surface b){
    background = b;
    level = s;
}
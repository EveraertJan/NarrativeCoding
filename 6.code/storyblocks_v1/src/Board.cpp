//
//  Board.cpp
//  storyblocks_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#include "Board.h"

void Board::setup(int x, int y, int r){
    xpos = x;
    ypos = y;
    rot = r;
}
void Board::updatePos(int x, int y, int r){
    xpos = x;
    ypos = y;
    rot = r;
}
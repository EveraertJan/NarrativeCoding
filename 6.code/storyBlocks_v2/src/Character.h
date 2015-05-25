//
//  Character.h
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#pragma once

class Character{
public:
    
    void setup(int startX, int startY);
    void draw();
    void updatePos(ci::Vec2i pos);
    int x;
    int y;
    int rot;
};
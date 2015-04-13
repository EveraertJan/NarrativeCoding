//
//  Board.h
//  compiler_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#pragma once

class Board{
public:
    void setup();
    void setup(std::vector<ci::Vec2f> p);
    void draw();
    void draw(int x, int y);
    void update();
    
    Boolean isFound = false;
    std::vector<float> rotation;
    float curRot;
    std::vector<cinder::Vec2f> avgP;
    std::vector<cinder::Vec2f> points;
    cinder::Vec2f curPoint;
    ci::Vec2f center;
    int tagNum;
};
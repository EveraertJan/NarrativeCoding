//
//  Interface.h
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#pragma once

class Interface{
public:
    void setup(float scale);
    void drawBookScan();
    void drawGreenCard();
    void drawCodeMoment(int numFields);
    void drawTutorialOverlay();
    void drawFinal();
    
    void updateBookPos(ci::Vec2i bookTop, ci::Vec2i bookDown);
    
    
    
    float scale;
    
    
    int DCX;
    int DCY;
    
    
    int bookWidth;
    int bookHeight;
    
    int scanSize;
    
    ci::Area bookArea;
    std::vector<ci::Area> scanAreas;
    ci::Area greenCard;

    
    void drawAreas();
    ci::Area getArea(int x, int y);
    
};
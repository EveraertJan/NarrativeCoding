//
//  UI.h
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#pragma once

class UI{
public:
    ci::Area showBookScan();
    ci::Area showGreenCard();
    ci::Area TagScan();
    void tutorial();
    
    void showTagConnections(std::vector<ci::Vec2i> tags);
    
    int cx;
    int cy;
    int tagSize = 100/2;
};
//
//  Level.h
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//
#pragma once

class Level{
public:
    
    void setLevel(ci::Surface s, ci::Surface b);
    
    ci::Surface background;
    ci::Surface level;
    
};
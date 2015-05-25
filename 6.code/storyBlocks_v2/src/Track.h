//
//  Track.h
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//
#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/Utilities.h"
class Track{
public:
    void trackBook(ci::Surface surf);
    int trackcode(ci::Surface surf, ci::Vec2i pos, Boolean negative);
    ci::Area getBounds(ci::Surface surf);
    Boolean greenScan(ci::Surface greenArea);
    void followTags(ci::Surface surf);
    Boolean checkExistance(int tagId);
    Boolean checkInArray(ci::Vec2i pos);
    
    ci::Vec2i cornerTopPos;
    ci::Vec2i cornerBotPos;
    
    std::vector<ci::Vec2i> tagPos;
    
    int threshold = 30;
    
    int tagThreshold  = 100;
    std::vector<int> tags;
};
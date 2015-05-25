//
//  Story.h
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#pragma once
#include "cinder/Utilities.h"
#include "Level.h"
class Story{
public:
    Boolean loadStory(int bookId);
    
    std::vector<Level> levels;
    
    
    
};
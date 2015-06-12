//
//  CodeMoment.h
//  multiuser
//
//  Created by jan everaert on 08/06/15.
//
//

#pragma once 
#include "Tag.h"

class CodeMoment{
public:
    void push();
    int id;
    std::string backgroundurl;
    std::string placementurl;
    int maxCards;
    
    
    int curCards;
    std::vector<Tag> tags;
};
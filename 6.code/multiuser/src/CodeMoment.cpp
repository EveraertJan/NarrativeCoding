//
//  CodeMoment.cpp
//  multiuser
//
//  Created by jan everaert on 08/06/15.
//
//

#include "CodeMoment.h"

void CodeMoment::push(){
    Tag t;
    t.tag = 0;
    t.val = 0;
    tags.push_back(t);
    
}
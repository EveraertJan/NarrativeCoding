//
//  Chapter.cpp
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#include "Chapter.h"

void Chapter::setup(){
    
    for(int i = 0; i<moments.size(); i++){
        moments.at(i).setup();
    }
}

void Chapter::checkFixed(){
    
}
void Chapter::checkResult(){
    
}

void Chapter::provision(std::vector<ci::Surface> page){
    for(int i = 0; i<page.size(); i++){
        pageS.push_back(page.at(i));
    }
    pageS = page;
}
ci::Surface Chapter::getPage(int num){
    if(num>pageS.size()){
        return ci::Surface();
    } else {
        return pageS.at(num);
    }
}
//
//  User.cpp
//  compiler_v1
//
//  Created by jan everaert on 13/04/15.
//
//

#include "User.h"

void User::setup(int x, int y, int rot){
    
}
void User::update(ci::Surface sur){
    curSurf = sur;
    
}
void User::draw(){
    
}
void User::checkBoard(){
    //go check for other pieces of code
    
    int code = reader.readTag(curSurf);
    compiler.idArr.push_back(code);
}
void User::checkCode(){
    
}
void User::checkInput(){
    
}
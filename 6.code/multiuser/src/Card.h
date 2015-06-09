//
//  Card.h
//  multiuser
//
//  Created by jan everaert on 09/06/15.
//
//
#pragma once 

class Card{
public:
    int cardid;
    std::string name;
    
    std::string type;
    ci::Vec2i movement;
};
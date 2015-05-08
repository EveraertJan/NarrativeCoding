//
//  Conversions.cpp
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#include "Conversions.h"

void Conversions::setup(int totalMovements){
    for(int i = 0; i<totalMovements; i++){
        movements.push_back(ci::Vec2i(0, 0));
    }
}

void Conversions::setMovement(int pointer, ci::Vec2i posC){
    try{
        movements.at(pointer) = posC;
    } catch ( ... ){
        ci::app::console() << "not there \n";
    }
}
ci::Vec2i Conversions::getMovement(int pointer){
    try{
        return movements.at(pointer);
    } catch ( ... ){
        return ci::Vec2i(0, 0);
    }
}
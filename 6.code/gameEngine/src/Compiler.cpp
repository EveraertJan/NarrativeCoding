//
//  Compiler.cpp
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#include "Compiler.h"


void Compiler::setup(){
    ch.setup(0, 0);
    curPosition = ci::Vec2i(0, 0);
    conv.setup(10);
    fillConversion();
    
    
    buildLevel();
    
    //addBlock(ci::Vec2i(0, 2));
    //addHole(ci::Vec2i(0, 2));
    
    curPas = 0;
    running = true;
    died  = false;
}
void Compiler::draw(Boolean play){
    if(play){
        if(curPas<passes.size()){
            ch.updatePos(passes.at(curPas));
            //ci::app::console() << "passing on: " << passes.at(curPas) << "\n";
            curPas++;
            ch.draw();
        } else {
            running = false;
            curPas = 0;
            ch.draw();
        }
    } else {
        ch.draw();
    }
}
void Compiler::compile(){
    for(int i = 0; i<input.size(); i++){
        ci::Vec2i move = conv.getMovement(input.at(i));
        int valid = validMove(move);
        switch (valid){
            case 0:
                passes.push_back(curPosition+move);
                curPosition+=move;
                break;
            case 1:
                passes.push_back(curPosition);
                break;
            case -1:
                passes.push_back(ci::Vec2i(0, 0));
                died = true;
                ci::app::console() << "died \n";
                break;
        }
    }
    
}

int Compiler::validMove(ci::Vec2i move){
    int toReturn = 0;
    for(int i = 0; i<blocks.size(); i++){
        if(curPosition+move == blocks.at(i)){
            toReturn+= 1;
        } else  {
            toReturn +=0;
        }
    }
    for(int i = 0; i<holes.size(); i++){
        if(curPosition+move == holes.at(i)){
            toReturn-= 1;
        } else  {
            toReturn +=0;
        }
    }
    //ci::app::console() << "returned " << toReturn << "\n";
    return toReturn;
}

void Compiler::buildLevel(){
    ci::Surface s = cinder::loadImage(cinder::app::loadAsset("levelTest.png"));
    
    for(int i = 0; i<10; i++){
        for (int j = 0; j<10; j++){
            cinder::ColorAT<unsigned char> color = s.areaAverage(ci::Area(i*50+10, j*50+10,i*50+40, j*50+40));
            if(color.r == 255 && color.g == 0 && color.b == 0){
                addHole(ci::Vec2i(i, j));
            }
            if(color.r == 0 && color.g == 0 && color.b == 255){
                addBlock(ci::Vec2i(i, j));
            }
        }
    }
}


void Compiler::addBlock(ci::Vec2i pos){
    blocks.push_back(pos);
}
void Compiler::addHole(ci::Vec2i pos){
    holes.push_back(pos);
}
void Compiler::fillConversion(){
    conv.setMovement(0, ci::Vec2i(0, 0));
    conv.setMovement(1, ci::Vec2i(0, -1));
    conv.setMovement(2, ci::Vec2i(0, 1));
    conv.setMovement(3, ci::Vec2i(1, 0));
    conv.setMovement(4, ci::Vec2i(-1, 0));
}

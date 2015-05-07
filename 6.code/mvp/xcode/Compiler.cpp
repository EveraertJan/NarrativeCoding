//
//  Compiler.cpp
//  gameEngine
//
//  Created by jan everaert on 24/04/15.
//
//

#include "Compiler.h"


void Compiler::setup(int code){
    ch.setup(5, 5);
    curPosition = ci::Vec2i(5, 5);
    conv.setup(3000);
    fillConversion();
    
    buildLevel(code);

    count = 0;
    curPas = 0;
    running = true;
    died  = false;
}
void Compiler::draw(Boolean play){
    if(play){
        if(curPas<passes.size()){
            count++;
            if(count == maxCount){
                ch.updatePos(passes.at(curPas));
                ci::app::console() << "passing on: " << passes.at(curPas) << "\n";
                curPas++;
                ch.draw();
                count = 0;
            }
        } else {
            running = false;
            curPas = 0;
            ch.draw();
        }
    } else {
        ch.draw();
    }
    drawScenery();
}
void Compiler::compile(){
    
    std::vector<int> toEx;
    
    for(int i = 0; i<input.size(); i++){
        //if(input.at(i)>10){
            //ci::app::console() << "doing this " << input.at(i)-10 << " times \n";
           /* for(int k = 0; k<input.at(i)-10; k++){
                Boolean tracking = true;
                for(int j = i+1; j< input.size()-1; j++){
                    if(input.at(j) == 0){
                        tracking = false;
                    } else if(tracking){
                        toEx.push_back(input.at(j));
                    }
                }
            }
            //code in forloop mag niet meer uitgevoerd worden
        } else if(input.at(i)<10 && input.at(i)!=0){*/
            toEx.push_back(input.at(i));
        //}
    }
    
    for(int i = 0; i<toEx.size(); i++){
        //ci::app::console() << toEx.at(i) << "\n";
        //if(toEx.at(i) > 10){
            //if/else
            
        //} else if(toEx.at(i) == 0){
            
        //} else {
            ci::Vec2i move = conv.getMovement(toEx.at(i));
            int valid = validMove(move);
            switch (valid){
                case 0:
                    passes.push_back(curPosition+move);
                    curPosition+=move;
                    ci::app::console() << "moved \n";
                    break;
                case 1:
                    passes.push_back(curPosition);
                    ci::app::console() << "didn't move \n";
                    break;
                case -1:
                    passes.push_back(ci::Vec2i(0, 0));
                    died = true;
                    ci::app::console() << "died \n";
                    break;
           // }
        }
    }
    running = true;
}

int Compiler::validMove(ci::Vec2i move){
    int toReturn = 0;
    ci::Vec2i nextPos = curPosition+move;
    if(nextPos.x<0){ return 1; }
    if(nextPos.x>10){ return 1; }
    if(nextPos.y<0){ return 1; }
    if(nextPos.y>10){ return 1; }
    for(int i = 0; i<blocks.size(); i++){
        if(nextPos == blocks.at(i)){
            toReturn+= 1;
        } else  {
            toReturn +=0;
        }
    }
    for(int i = 0; i<holes.size(); i++){
        if(nextPos == holes.at(i)){
            toReturn-= 1;
        } else  {
            toReturn +=0;
        }
    }
    //ci::app::console() << "returned " << toReturn << "\n";
    return toReturn;
}

void Compiler::buildLevel(int level){
    ci::Surface s;
    try{
        s = cinder::loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/level_"+cinder::toString(level)+"_1.png"));
        ci::app::console() << "it is loaded \n";
    } catch ( ... ){
        ci::app::console() << "can't load level \n";
        return;
    }
    
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
    conv.setMovement(1, ci::Vec2i(0, 0));
    conv.setMovement(2, ci::Vec2i(0, -1));
    conv.setMovement(2144, ci::Vec2i(0, 1));
    conv.setMovement(1552, ci::Vec2i(1, 0));
    conv.setMovement(4, ci::Vec2i(-1, 0));
    conv.setMovement(5, ci::Vec2i(1, 0));
}

void Compiler::drawScenery(){
    ci::gl::color(0, 0, 0);
    for(int i = 0; i<holes.size(); i++){
        ci::gl::drawSolidRect(ci::Rectf(holes.at(i).x*50, holes.at(i).y*50, holes.at(i).x*50+50, holes.at(i).y*50+50));
    }
    ci::gl::color(200, 0, 0);
    for(int i = 0; i<blocks.size(); i++){
        ci::gl::drawSolidRect(ci::Rectf(blocks.at(i).x*50, blocks.at(i).y*50, blocks.at(i).x*50+50, blocks.at(i).y*50+50));
    }
    ci::gl::color(255, 255, 255);
}
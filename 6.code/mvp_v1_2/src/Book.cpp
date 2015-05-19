//
//  Book.cpp
//  mvp_v1_2
//
//  Created by jan everaert on 16/05/15.
//
//

#include "Book.h"


void Book::setup(int code){
    id = code;
    isset = true;
    curLevel = 0;
    Level l;
    ci::Surface s;
    ci::Surface b;
    try{
        s = cinder::loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/structure_"+cinder::toString(code)+"_1.png"));
        b = cinder::loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/background_"+cinder::toString(code)+"_1.png"));
        ci::app::console() << "it is loaded \n";
    } catch ( ... ){
        ci::app::console() << "can't load level \n";
        return;
    }
    l.setup(s, b);
    levels.push_back(l);
    //load entire book;
    //load levels;
    //setup levels;
}

Boolean Book::Exists(int code){
    try{
        if(code == 1552){
        /*
        cover = loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/bookCover_"+ci::toString(code)+".png"));
        //cover = loadImage( cinder::app::loadAsset( "bookCover_"+ci::toString(code)+".png" ) );*/
        return true;
        } else {
            return false;
        }
    } catch ( ... ){
        return false;
    }
}
void Book::setupLevel(int levelId){
    curLevel = levelId;
    try{
        //load in files
        ci::Surface level;
        ci::Surface background;
        levels.at(curLevel).setup(level, background);
        if(levels.at(curLevel).isset){
            compiler.setup(levels.at(curLevel).blocks, levels.at(curLevel).dead);
        } else {
            ci::app::console() << "error in levelBuild \n";
        }
    } catch( ... ){
        ci::app::console() << "could not load level \n";
    }
}
void Book::drawCode(int levelId, Boolean greenCard){
    ci::Surface main;
    //change main to character;
    
    if(!levels.at(levelId).isset){
        setupLevel(levelId);
    } else {
        levels.at(levelId).drawLevel();
        if(greenCard){
            if(compiler.isBuild){
                //get cur frame, based on playRate and starttime
                compiler.drawOutput(0, main);
            } else {
                int output = compiler.build();
                switch (output){
                    case 0:
                            //draw, but you will die;
                    break;
                }
            }
        }
        //draw level and track
    }
    
}
void Book::setSteps(std::vector<int> cards){
    compiler.cards = cards;
}
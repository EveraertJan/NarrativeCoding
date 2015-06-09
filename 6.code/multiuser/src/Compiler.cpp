//
//  Compiler.cpp
//  multiuser
//
//  Created by jan everaert on 09/06/15.
//
//

#include "Compiler.h"


void Compiler::setup(){
    compiled = false;
    
    //load possible cards
    try{
    ci::XmlTree doc( ci::app::loadAsset("cards.xml" ) );
    ci::XmlTree bookxml = doc.getChild( "cards" );
    
    for( XmlTree::Iter card = bookxml.begin(); card != bookxml.end(); ++card ){
        Card ca;
        for( XmlTree::Iter tag = card->begin(); tag != card->end(); ++tag ){
            if(tag->getTag() == "id"){
                ca.cardid=tag->getValue<int>();
                //console() << tag->getValue<int>() << "\n";
            } else if(tag->getTag() == "string"){
                ca.name = tag->getValue();
                //console() << tag->getValue() << "\n";
            } else if(tag->getTag() == "move"){
                ca.type = tag->getValue();
            } else if(tag->getTag() == "x"){
                ca.movement.x = tag->getValue<int>();
                console() << tag->getValue<int>() << "\n";
            } else if(tag->getTag() == "y"){
                ca.movement.y = tag->getValue<int>();
            }
        }
        cards.push_back(ca);
    }
    } catch( ... ){
        console() << "could not load xml";
    }
    
    levelSet = false;
    isset = true;
    frameWait = 48;
    
}

void Compiler::loadLevel(CodeMoment cm){
    
    ci::Surface back = ci::loadImage(ci::loadUrl(cm.placementurl));
    
    ci::Vec2i p = ci::Vec2i(ci::app::getWindowCenter().x, 400);
    int imgSize = 600/2;
    
    int w = back.getWidth();
    int h = back.getHeight();
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            int x = ((w/10)/2)+((w/10)*i);
            int y = ((h/10)/2)+((h/10)*j);
            ColorAT<unsigned char> c;
            c = back.getPixel(Vec2i(x, y));
            if(c.g+c.b<c.r){
                death.push_back(Vec2i(i, j));
                gl::color(0, 255, 0);
            } else if(c.b>150 && c.r+c.g<50){
                blocks.push_back(Vec2i(i, j));
                gl::color(255, 0, 0);
            } else if(c.b+c.g+c.r<20){
                end = (Vec2i(i, j));
                gl::color(0, 0, 0);
            } else if(c.b+c.r<c.g){
                start = Vec2i(i, j);
                pos = (Vec2i(i, j));
                gl::color(0, 0, 0);
                console() << "startpos: " << pos << "\n";
            } else {
                gl::color(255, 255, 255);
            }
            gl::drawSolidCircle(Vec2i(p.x-imgSize+(i*imgSize*2/10), p.y-imgSize+(j*imgSize*2/10)), 3);
        }
    }
    
    levelSet = true;
    
    
}

std::string Compiler::translate(int cardId){
    int found = 0;
    for(int i  =0; i<cards.size(); i++){
        if(cardId == cards.at(i).cardid){
            found++;
            return cards.at(i).name;
        }
    }
    return "";
}

void Compiler::compile(std::vector<int> tags){
    
    std::vector<int> process;
    for(int i = 0; i<tags.size(); i++){
        
        if(translate(tags.at(i))!= ""){
            process.push_back(tags.at(i));
            console() << "adding " << tags.at(i) << "\n";
        }
        //check for specials, and act likewise
    }
    move.clear();
    for(int i = 0; i<process.size(); i++){
        Boolean found = false;
        for(int j =0; j<cards.size(); j++){
            if(cards.at(j).cardid == process.at(i) && !found){
                move.push_back(cards.at(j).movement);
                found = true;
                console() << "to move: " << cards.at(j).movement << "\n";
            }
        }
    }
    pos = start;
    go.clear();
    go.push_back(start);
    for(int i = 0; i<move.size(); i++){
        Vec2i to = Vec2i(pos.x+move.at(i).x, pos.y+move.at(i).y);
        console() << "going to " << to << "\n";
        if(!checkDeath(to)){
            if(!checkBlock(to)){
                console() << "no blocks\n";
                go.push_back(to);
                pos=to;
            }
        } else {
            //diededed
        }
        
    }
    compiled = true;
    curPlaying = -1;
}
Boolean Compiler::play(int timeCode, CodeMoment cm){
    
    
    if(timeCode%frameWait == 0){
        curPlaying++;
    }
    

    try{
        if(curPlaying >=0){
            pos = go.at(curPlaying);
        } else {
            pos = go.at(0);
        }
        return true;
    } catch( ... ) {
        return false;
    }
    /*
    
    int tagSize = 40;
    int imgSize = 600/2;
    std::vector<Area>sa;
    for(int i =0; i< cm.numcards+1; i++){
        Vec2i p = Vec2i((getWindowWidth()/2-imgSize+(tagSize/2))+(i*(tagSize+20)), getWindowHeight()/2+imgSize);
        Area a = Area(p.x-tagSize/2, p.y-tagSize/2, p.x+tagSize/2, p.y+tagSize/2);
        if(i<cm.numcards+1){
            gl::drawStrokedRect(Rectf(a));
        } else {
            gl::color(0, 255, 0);
            gl::drawStrokedRect(Rectf(a));
        }
        sa.push_back(a);
    }
    
    */
    
}


Boolean Compiler::checkBlock(Vec2i next){
    Vec2i to = pos+next;
    int found = 0;
    for(int i = 0; i<blocks.size(); i++){
        if(blocks.at(i) == to){
            found++;
        }
    }
    if(found == 0){
        return false;
    } else {
        return true;
    }
}
Boolean Compiler::checkDeath(Vec2i next){
    Vec2i to = pos+next;
    int found = 0;
    for(int i = 0; i<death.size(); i++){
        if(death.at(i) == to){
            found++;
        }
    }
    if(found == 0){
        return false;
    } else {
        return true;
    }
}
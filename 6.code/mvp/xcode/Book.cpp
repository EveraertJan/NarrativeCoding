//
//  Book.cpp
//  bookLoadTest
//
//  Created by jan everaert on 04/05/15.
//
//

#include "Book.h"


void Book::setup(int c){
    code = c;
    isFound = false;
    AreaSet = false;
    downloading = false;
    outputting =  false;
    try{
        cover = loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/bookCover_"+ci::toString(code)+".png"));
        //cover = loadImage( cinder::app::loadAsset( "bookCover_"+ci::toString(code)+".png" ) );
        isFound = true;
        compiler.setup(code);
        td.setup();
    } catch ( ... ){
        ci::app::console() << "asset cover not found ";
    }
}
void Book::update(){
    
    std::vector<int> in;
    if(downloading){
        if(td.tracked.size()>0){
            compiler.input = td.tracked;
        } else {
            compiler.input = in;
            ci::app::console() << "input size: " << compiler.input.size() << "\n";
        }
        //build and fill in passes to see what char should do
        compiler.compile();
    }
    td.update();
    
}
void Book::draw(int bookSize){
    if(isFound && codeMoment){
        
        float dX = dispPosDown.x-dispPosTop.x;
        float dY = dispPosDown.y-dispPosTop.y;
        
        float angleD = (atan2f(dY, dX)*180/pi)-90;
        //ci::app::console() << angleD << "\n";
        
        ci::gl::pushMatrices();
        ci::gl::translate((dispPosTop.x+dispPosDown.x)/2-180+20, (dispPosTop.y+dispPosDown.y)/2-10);
        ci::gl::rotate(angleD);
        ci::gl::enableAlphaBlending();
        
        
        ci::gl::draw(cover, ci::Vec2f(-180, -280));
        
        
        if(outputting){
            //ci::gl::clear( Color(20, 20, 20));
            downloading = false;
            compiler.draw(outputting);
            if(compiler.running == false){
                outputting = false;
            }
        } else {
            if(AreaSet){
                for(int i = 0; i<codeArea.size(); i++){
                    //td.draw(codeArea.at(i));
                }
            }
        }

        ci::gl::disableAlphaBlending();
        ci::gl::popMatrices();
        if(!AreaSet){
            codeArea.clear();
            for(int i = 0; i<5; i++){
                ci::gl::color(255, 255, 255);
                ci::gl::drawStrokedRect(Rectf(Area((dispPosDown.x-bookSize)+10+((bookSize*0.38+10)*i), (dispPosDown.y)+30, (dispPosDown.x)-bookSize+bookSize*0.38+10+((bookSize*0.38+10)*i), (dispPosDown.y)+bookSize*0.38+30)));
                
                codeArea.push_back(copyWindowSurface(Area((dispPosDown.x-bookSize)+10, (dispPosDown.y)+30, (dispPosDown.x)-bookSize+bookSize*0.38+10, (dispPosDown.y)+bookSize*0.38+30)));
            }
            
            AreaSet = true;
        }
        
        
        
    }
}


Boolean Book::exists(int c){
    if(c==1552){
        return true;
    } else {
        return false;
    }
}
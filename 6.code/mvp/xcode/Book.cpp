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
    downloading = false;
    outputting =  false;
    reading = false;
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
            for(int i = 0; i<td.tracked.size(); i++){
                if(td.tracked.at(i)>100){
                    td.tracked.erase(td.tracked.begin()+i);
                }
            }
            compiler.input = td.tracked;
        } else {
            compiler.input = in;
            ci::app::console() << "input size: " << compiler.input.size() << "\n";
        }
        //build and fill in passes to see what char should do
        compiler.compile();
    }
    td.update();
    ci::app::console() << "input size: " << compiler.input.size() << "\n";
    
}
void Book::draw(int bookSize){
    if(isFound && codeMoment){
        
        float dX = dispPosDown.x-dispPosTop.x;
        float dY = dispPosDown.y-dispPosTop.y;
        
        float angleD = (atan2f(dY, dX)*180/pi)-90;
        
        ci::gl::pushMatrices();
        ci::gl::translate((dispPosTop.x+dispPosDown.x)/2-(bookSize/2), (dispPosTop.y+dispPosDown.y)/2);
        ci::gl::rotate(angleD);
        ci::gl::enableAlphaBlending();
        
        ci::gl::draw(cover, Rectf(-(bookSize/2), -(bookSize*1.5)/2, (bookSize/2), (bookSize*1.5)/2));
        if(outputting){
            //ci::gl::clear( Color(20, 20, 20));
            downloading = false;
            compiler.draw(outputting);
            if(compiler.running == false){
                outputting = false;
            }
            ci::gl::disableAlphaBlending();
            ci::gl::popMatrices();
        } else {
            ci::gl::disableAlphaBlending();
            ci::gl::popMatrices();
            gl::color(255, 255, 255);
            int scanSize =bookSize*0.375;
            int xOffset = 100;
            int yOffset = 200;
            for(int i = 0; i<8; i++){
                gl::drawStrokedRect(Rectf(i*(scanSize+10)+xOffset, getWindowHeight()-scanSize-yOffset, i*(scanSize+10)+(scanSize)+xOffset, getWindowHeight()-yOffset));
                
                if(reading){
                    Area a = Area(i*(scanSize+10)+xOffset, getWindowHeight()-scanSize-yOffset, i*(scanSize+10)+(scanSize)+xOffset, getWindowHeight()-yOffset);
                    td.getCode(a, copyWindowSurface(a));
                }
            }
            reading = false;
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
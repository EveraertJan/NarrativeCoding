//
//  Story.cpp
//  storyBlocks_v2
//
//  Created by jan everaert on 24/05/15.
//
//

#include "Story.h"


Boolean Story::loadStory(int bookId){
    ci::Surface b;
    ci::Surface s;
    Level l;
    try{
        s = cinder::loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/structure_"+ci::toString(bookId)+"_1.png"));
        b = cinder::loadImage( cinder::loadUrl("http://www.crashlab.be/storyblocks/get/background_"+ci::toString(bookId)+"_1.png"));
        ci::app::console() << "it is loaded \n";
        l.setLevel(s, b);
        levels.push_back(l);
        return true;
    } catch ( ... ){
        ci::app::console() << "can't load level \n";
        return false;
    }

}
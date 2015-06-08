//
//  User.cpp
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

#include "User.h"


void User::setup(int userX, int userY, int userW, int userH){
    state = -1;
    userXCenter = userX;
    userYCenter = userY;
    userWidth = userW;
    userHeight = userH;
    
    track.setup();
    
    tagSize = 40;
    showCam = false;
    
}
void User::update(){
    track.update();
}
void User::draw(){
    if(track.cam.started == false){
        state = -1;
    }
        switch(state){
        {case -1:
            //ui show settigns;
            ui.showSettings();
            track.cam.showBounds();
            
            break;
        }
        {case 0:
            //scan book
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            ci::gl::color(255, 255, 255);
            ci::gl::drawStringCentered("show bookscan", ci::Vec2i(ci::app::getWindowCenter().x, 200));
            int tracked = track.trackTag(ar, true);
            if( story.exists(tracked)){
                story.loadStory(tracked);
                state++;
            }
            ui.showScanner(ar);
            break;
        }
        {case 1:
            //reading
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            int tagId = track.trackTag(ar, false);
            if(story.cmExists(tagId)){
                state++;
            }
            ui.showCodeMomentScanner(ar);
            break;
        }
        {case 2:
            //tutorial w/ greencard
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            if(track.trackGreen(ar)){
                state++;
            }
            ui.showGreenScanner(ar);
            
            break;
        }
        {case 3:
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            std::vector<Area> scans = ui.scanArs;
            for(int i = 0; i<scans.size(); i++){
                if(i<scans.size()-1){
                    track.trackTag(scans.at(i), false);
                } else {
                    if(track.trackGreen(scans.at(scans.size()-1))){
                        state++;
                    }
                }
            }
            
            ui.showCodeMoment(story.cm.at(0), ar);
            //Add cards
            break;
        }
        {case 4:
            //compile (green card scanned
            break;
        }
        {case 5:
            //output (animation)
            break;
        }
        {case 6:
            //results
            break;
        }
    }
    
}
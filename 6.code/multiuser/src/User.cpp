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
    timing.UpdateTimer();
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
            
            if(!compiler.isset){
                compiler.setup();
                track.tags = compiler.exists;
            }
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
            if(story.cm.at(0).tags.size() == 0){
                story.cm.at(0).push();
            }
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            
            track.draw(showCam);
            
            
            
            std::vector<Area> scans = ui.scanArs;
            //scanars being determined based on the num scanned currently
            for(int i = 0; i<scans.size(); i++){
                if(i<scans.size()-1){
                    //check if tags has been set
                    if(story.cm.at(0).tags.at(i).tag == 0){
                        int tag = track.trackTag(scans.at(i), false);
                        gl::color(255, 255, 255);
                        gl::drawStringCentered(compiler.translate(tag), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                        if(track.checkExistance(tag)){
                            story.cm.at(0).tags.at(i).tag = tag;
                            story.cm.at(0).tags.at(i).last = track.returnSurf(scans.at(i));
                            story.cm.at(0).tags.at(i).val = 1;
                            if(compiler.levelSet){
                                if(compiler.checkSpecial(tag)){
                                    console() << "scanned \n";
                                    story.cm.at(0).tags.at(i).val= 0;
                                } else {
                                    story.cm.at(0).push();
                                }
                            }
                            
                            
                        }
                    } else if(story.cm.at(0).tags.at(i).val == 0){
                        int tag = track.trackTag(scans.at(i), false);
                        if(tag<10 && tag!=0){
                            story.cm.at(0).tags.at(i).val = tag;
                            story.cm.at(0).tags.at(i).last = track.returnSurf(scans.at(i));
                            story.cm.at(0).push();
                        }
                        
                        gl::drawStringCentered(toString(tag), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                    } else {
                        gl::color(255, 255, 255);
                        string trans = compiler.translate(story.cm.at(0).tags.at(i).tag);
                        gl::drawStringCentered(trans, Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                        if(story.cm.at(0).tags.at(i).val!=0 && trans != "stop"){
                            gl::drawStringCentered(toString(story.cm.at(0).tags.at(i).val), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y));
                            
                        }
                        /*ColorAT<unsigned char> col = track.c.areaAverage(scans.at(i));
                         ColorAT<unsigned char> col2 = story.cm.at(0).tags.at(i).last.areaAverage(story.cm.at(0).tags.at(i).last.getBounds());
                         if(abs(col.r-col2.r)+abs(col.g-col2.g)+abs(col.b-col2.b)>200){
                         //story.cm.at(0).tags.at(i).tag = 0;
                         }*/
                    }
                } else {
                    if(track.trackGreen(scans.at(scans.size()-1))){
                        state++;
                    }
                }
            }
            
            //if(!compiler.levelSet){
            //}
            ui.showCodeMoment(story.cm.at(0), ar, compiler.pos);
            if(!compiler.levelSet){
                compiler.loadLevel(story.cm.at(0));
            }
            //Add cards
            break;
        }
        {case 4:
            //std::vector<Area> scans = ui.scanArs;
            std::vector<int> t;
            for(int i = 0; i<story.cm.at(0).tags.size(); i++){
                if(story.cm.at(0).tags.at(i).tag != 0){
                    t.push_back(story.cm.at(0).tags.at(i).tag);
                }
            }
            compiler.compile(t, story.cm.at(0));
            timing.startTimer();
            state++;
            //compile (green card scanned
            break;
        }
        {case 5:
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            int time = timing.getTime();
            //console() << compiler.achieved << "\n";
            if(compiler.play(time, story.cm.at(0))){
                ui.showOutput(story.cm.at(0), ar, compiler.pos);
                
                console() << compiler.pos << ", " << compiler.end << "\n";
                if(compiler.pos == compiler.end){
                    console() << "been there \n";
                    state = 6;
                }
                
                
            } else {
                compiler.compiled = false;
                compiler.levelSet = false;
                state = 3;
            }
            break;
        }
        {case 6:
            //tell what to do
            break;
        }
    }
    
}
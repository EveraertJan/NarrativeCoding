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
    
    /*
     * het programma werkt via een aantal states. dit is een waarde die bepaald wat getoont moet worden
     */
    
    switch(state){
        {case -1:
            //geef de settings weer, deze zijn  nodig om het camerabeeld uit te lijnen met het geprojecteerde beeld;
            ui.showSettings();
            track.cam.showBounds();
            
            break;
        }
        {case 0:
            //scan het boek
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
            /*
             * de gebruiker is aan het lezen, een scanner om het codemoment te scannen wordt getoont
             */
            if(!compiler.isset){
                compiler.setup();
                track.tags = compiler.exists;
            }
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            int tagId = track.trackTag(ar, false);
            if(story.cmExists(tagId)){
                state++;
                story.currentCodeMoment = tagId;
            }
            ui.showCodeMomentScanner(ar);
            break;
        }
        {case 2:
            /*
             * dit is het moment om enige uitleg weer te geven. om verder te gaan kan de groene kaart gescanned worden
             */
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            if(track.trackGreen(ar)){
                state++;
            }
            //het toevoegen van tutorialinfo gebeurd via deze funtie
            ui.showGreenScanner(ar, "scan de groene kaart om verder te gaan");
            
            break;
        }
        {case 3:
            /*
             * op dit moment kan de user kaarten toevoegen. deze worden onderaan het speelveld gescanned via een dynamisch aantal kaarten.
             *
             */
            if(story.cm.at(story.currentCodeMoment).tags.size() == 0){
                story.cm.at(story.currentCodeMoment).push();
            }
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            
            track.draw(showCam);
            std::vector<Area> scans = ui.scanArs;
            //scanars being determined based on the num scanned currently
            for(int i = 0; i<scans.size(); i++){
                if(i<scans.size()-1){
                    //check if tags has been set
                    if(story.cm.at(story.currentCodeMoment).tags.at(i).tag == 0){
                        int tag = track.trackTag(scans.at(i), false);
                        gl::color(255, 255, 255);
                        gl::drawStringCentered(compiler.translate(tag), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                        if(track.checkExistance(tag)){
                            story.cm.at(story.currentCodeMoment).tags.at(i).tag = tag;
                            story.cm.at(story.currentCodeMoment).tags.at(i).last = track.returnSurf(scans.at(i));
                            story.cm.at(story.currentCodeMoment).tags.at(i).val = 1;
                            if(compiler.levelSet){
                                if(compiler.checkSpecial(tag)){
                                    console() << "scanned \n";
                                    story.cm.at(story.currentCodeMoment).tags.at(i).val= 0;
                                } else {
                                    story.cm.at(story.currentCodeMoment).push();
                                }
                            }
                            
                            
                        }
                    } else if(story.cm.at(story.currentCodeMoment).tags.at(i).val == 0){
                        int tag = track.trackTag(scans.at(i), false);
                        if(tag<10 && tag!=0){
                            story.cm.at(story.currentCodeMoment).tags.at(i).val = tag;
                            story.cm.at(story.currentCodeMoment).tags.at(i).last = track.returnSurf(scans.at(i));
                            story.cm.at(story.currentCodeMoment).push();
                        }
                        
                        gl::drawStringCentered(toString(tag), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                    } else {
                        gl::color(255, 255, 255);
                        string trans = compiler.translate(story.cm.at(story.currentCodeMoment).tags.at(i).tag);
                        gl::drawStringCentered(trans, Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y+50));
                        if(story.cm.at(story.currentCodeMoment).tags.at(i).val!=0 && trans != "stop"){
                            gl::drawStringCentered(toString(story.cm.at(story.currentCodeMoment).tags.at(i).val), Vec2i(scans.at(i).getCenter().x,scans.at(i).getCenter().y));
                            
                        }
                    }
                } else {
                    if(track.trackGreen(scans.at(scans.size()-1))){
                        state++;
                    }
                }
            }
            
            ui.showCodeMoment(story.cm.at(story.currentCodeMoment), ar, compiler.pos);
            if(!compiler.levelSet){
                compiler.loadLevel(story.cm.at(story.currentCodeMoment));
            }
            break;
        }
        {case 4:
            /*
             * de gelegde code wordt omgezet in acties om uit te voeren.
             */
            std::vector<int> t;
            for(int i = 0; i<story.cm.at(story.currentCodeMoment).tags.size(); i++){
                if(story.cm.at(story.currentCodeMoment).tags.at(i).tag != 0){
                    t.push_back(story.cm.at(story.currentCodeMoment).tags.at(i).tag);
                }
            }
            compiler.compile(t, story.cm.at(story.currentCodeMoment));
            timing.startTimer();
            state++;
            break;
        }
        {case 5:
            /*
             * de omgezette code uit vorige stap wordt hier stap voor stap uitgevoerd.
             */
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            int time = timing.getTime();
            //console() << compiler.achieved << "\n";
            if(compiler.play(time, story.cm.at(story.currentCodeMoment))){
                ui.showOutput(story.cm.at(story.currentCodeMoment), ar, compiler.pos);
                
                console() << compiler.pos << ", " << compiler.end << "\n";
                if(compiler.pos == compiler.end){
                    state = 6;
                }
                
                
            } else {
                compiler.compiled = false;
                compiler.levelSet = false;
                ui.scanArs.clear();
                state = 3;
            }
            break;
        }
        {case 6:
            
            // well done boodschap, en teruggaan naar de 2e staat (leggen van een codemoment blokje)
            // hier is het tevens mogelijk andere info weer te geven, zoals "ga naar pagina... "
            ci::Area ar = ci::Area(userXCenter-tagSize, userYCenter-tagSize, userXCenter+tagSize, userYCenter+tagSize);
            track.draw(showCam);
            if(track.trackGreen(ar)){
                state=2;
            }
            //het toevoegen van tutorialinfo gebeurd via deze funtie
            ui.showGreenScanner(ar, "goed gedaan, lees verder en scan het volgende codemoment als je dit tegenkomt (scan de groene kaart om verder te gaan");
            
            break;
        }
    }
    
}
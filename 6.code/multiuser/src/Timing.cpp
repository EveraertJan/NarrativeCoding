//
//  Timer.cpp
//  multiuser
//
//  Created by jan everaert on 09/06/15.
//
//

#include "Timing.h"


void Timing::startTimer(){
    framePassed= 0;
    timing = true;
}
void Timing::UpdateTimer(){
    if(timing){
        framePassed++;
    }
}
void Timing::stopTimer(){
    timing = false;
}
int Timing::getTime(){
    return framePassed;
}
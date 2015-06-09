//
//  Timer.h
//  multiuser
//
//  Created by jan everaert on 09/06/15.
//
//

#pragma once


class Timing{
public:
    void startTimer();
    void UpdateTimer();
    void stopTimer();
    
    int getTime();
    
    Boolean timing;
    int framePassed;
};
//
//  User.h
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//
#include "UI.h"
#include "cinder/app/AppNative.h"
#include "cinder/System.h"
#include "Track.h"
#include "Story.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class User{
public:
    void setup(int userX, int userY, int userW, int userH);
    void update();
    void draw();
    
    
    
    int state;
    UI ui;
    Track track;
    Story story;
    
    int userXCenter;
    int userYCenter;
    int userWidth;
    int userHeight;
    int tagSize;
};
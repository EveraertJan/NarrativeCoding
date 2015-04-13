//
//  Cam.h
//  captureTag
//
//  Created by jan everaert on 17/03/15.
//
//


#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/Capture.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"


using namespace ci;
using namespace ci::app;
using namespace std;


static const int WIDTH = 640, HEIGHT = 480;

class Cam{
public:
    void setup();
    void update();
    void draw();
    std::vector<CaptureRef>		mCaptures;
    vector<gl::TextureRef>	mTextures;
    
};
//
//  Cam.h
//  captureTag
//
//  Created by jan everaert on 17/03/15.
//
//


#pragma once
#include "cinder/Utilities.h"

#include "cinder/app/AppBasic.h"
#include "cinder/Capture.h"
#include "cinder/Surface.h"
#include "cinder/gl/Texture.h"


using namespace ci;
using namespace ci::app;
using namespace std;


static const int WIDTH = 1024, HEIGHT = 768;

class Cam{
public:
    void setup();
    void update();
    void draw(Vec2i ul, Vec2i ur, Vec2i dr, Vec2i dl);
    void showBounds();
    Boolean started = false;
    ci::Surface getSurf();
    std::vector<CaptureRef>		mCaptures;
    vector<gl::TextureRef>	mTextures;
    
    
    
    float xrot;
    float yrot;
    float zrot;
    float height;
    float width;
    float x;
    float y;
};
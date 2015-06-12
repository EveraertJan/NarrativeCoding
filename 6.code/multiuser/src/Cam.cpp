//
//  Cam.cpp
//  captureTag
//
//  Created by jan everaert on 17/03/15.
//
//

#include "Cam.h"

void Cam::setup(){
    started = false;
    // list out the devices
    vector<Capture::DeviceRef> devices( Capture::getDevices() );
    for( vector<Capture::DeviceRef>::const_iterator deviceIt = devices.begin(); deviceIt != devices.end(); ++deviceIt ) {
        Capture::DeviceRef device = *deviceIt;
        console() << "Found Device " << device->getName() << std::endl;
        try {
            if(device->checkAvailable() ){
                if(device->getName() == "Venus USB2.0 Camera #2" || device->getName() == "Venus USB2.0 Camera") {
                    mCaptures.push_back( Capture::create( ci::app::getWindowWidth(), ci::app::getWindowHeight(), device ) );
                    mCaptures.back()->start();
                    ci::app::console() << "got cam";
                    mTextures.push_back( gl::TextureRef() );
                }
            }
            else
                console() << "device is NOT available" << std::endl;
        }
        catch( CaptureExc & ) {
            console() << "Unable to initialize device: " << device->getName() << endl;
        }
    }
    
    width = 1903;
    height = 1444;
    xrot = 0;
    yrot = 0;
    zrot = 0;
    x = -59;
    y = 104;
}

void Cam::update(){
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        if( (*cIt)->checkNewFrame() ) {
            //ci::app::console() << (*cIt)->getSurface().getSize() << "\n";
            Surface8u surf = (*cIt)->getSurface();
            mTextures[cIt - mCaptures.begin()] = gl::Texture::create( surf );
        }
    }
    started = true;
}

void Cam::draw( Vec2i ul, Vec2i ur, Vec2i dr, Vec2i dl)
{
    gl::enableAlphaBlending();
    gl::clear( Color::black() );
    
    if( mCaptures.empty() )
        return;
    
    
    //float width = getWindowWidth() ;/// mCaptures.size();
    //float height = width / ( WIDTH / (float)HEIGHT );
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        // draw the latest frame
        gl::color( Color::white() );
        if( mTextures[cIt-mCaptures.begin()] ){
            
            //mTextures[cIt-mCaptures.begin()]->setFlipped(true);
            mTextures[cIt-mCaptures.begin()]->enableAndBind();
            
            gl::pushMatrices();
            gl::translate(x, y);
            gl::rotate(Vec3f(xrot, yrot, zrot));
            gl::drawSolidRect(Rectf(0, 0, width, height));
            gl::popMatrices();
            
            
            mTextures[cIt-mCaptures.begin()]->unbind();
            
        }
    }
    
}
void Cam::showBounds(){
    if(started){
        for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
            // draw the latest frame
            gl::color( Color::white() );
            if( mTextures[cIt-mCaptures.begin()] ){
                
                //mTextures[cIt-mCaptures.begin()]->setFlipped(true);
                mTextures[cIt-mCaptures.begin()]->enableAndBind();
                gl::pushMatrices();
                gl::translate(x, y);
                gl::rotate(Vec3f(xrot, yrot, zrot));
                gl::drawSolidRect(Rectf(0, 0, width, height));
                gl::popMatrices();
                
                mTextures[cIt-mCaptures.begin()]->unbind();
            }
        }
    } else {
        gl::color(255, 255, 255);
        gl::pushMatrices();
        gl::translate(x, y);
        gl::rotate(Vec3f(xrot, yrot, zrot));
        gl::drawSolidRect(Rectf(0, 0, width, height));
        gl::popMatrices();
    }
    
}
ci::Surface Cam::getSurf(){
    ci::Surface returnSurf;
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        // draw the latest frame
        gl::color( Color::white() );
        if( mTextures[cIt-mCaptures.begin()] ){
            
            
            //mTextures[cIt-mCaptures.begin()]->setFlipped(true);
            mTextures[cIt-mCaptures.begin()]->enableAndBind();
            
            gl::pushMatrices();
            gl::translate(x, y);
            gl::rotate(Vec3f(xrot, yrot, zrot));
            gl::drawSolidRect(Rectf(0, 0, width, height));
            gl::popMatrices();
            
            mTextures[cIt-mCaptures.begin()]->unbind();
            returnSurf = copyWindowSurface();
        }
    }
    return returnSurf;
}
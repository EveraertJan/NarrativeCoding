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
}

void Cam::update(){
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        if( (*cIt)->checkNewFrame() ) {
            //ci::app::console() << (*cIt)->getSurface().getSize() << "\n";
            Surface8u surf = (*cIt)->getSurface();
            mTextures[cIt - mCaptures.begin()] = gl::Texture::create( surf );
        }
    }
}

void Cam::draw( Vec2i ul, Vec2i dr)
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
            gl::pushMatrices();
            gl::scale(-1, -1);
            gl::translate(-getWindowWidth()-ul.x, -getWindowHeight()-ul.y);
            gl::scale(ci::app::getWindowWidth()/(dr.x-ul.x*1.0), ci::app::getWindowHeight()/(dr.y-ul.y*1.0));
            ci::app::console() << ci::app::getWindowWidth()/(dr.x-ul.x*1.0) << "\n";
            gl::draw( mTextures[cIt-mCaptures.begin()], Rectf( 0, 0, getWindowWidth(),getWindowHeight() ) );
            gl::popMatrices();
            
            started = true;
        }
    }
    
}
ci::Surface Cam::getSurf(){
    ci::Surface returnSurf;
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        // draw the latest frame
        gl::color( Color::white() );
        if( mTextures[cIt-mCaptures.begin()] ){
            gl::draw(mTextures[cIt-mCaptures.begin()]);
            returnSurf = copyWindowSurface();
        }
    }
    return returnSurf;
}
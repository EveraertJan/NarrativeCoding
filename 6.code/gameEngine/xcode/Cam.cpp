//
//  Cam.cpp
//  captureTag
//
//  Created by jan everaert on 17/03/15.
//
//

#include "Cam.h"


void Cam::setup(){
    // list out the devices
    vector<Capture::DeviceRef> devices( Capture::getDevices() );
    for( vector<Capture::DeviceRef>::const_iterator deviceIt = devices.begin(); deviceIt != devices.end(); ++deviceIt ) {
        Capture::DeviceRef device = *deviceIt;
        console() << "Found Device " << device->getName() << std::endl;
        try {
            if( device->checkAvailable() && mCaptures.size()<1) {
                mCaptures.push_back( Capture::create( ci::app::getWindowWidth(), ci::app::getWindowHeight(), device ) );
                mCaptures.back()->start();
                mTextures.push_back( gl::TextureRef() );
                
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
            Surface8u surf = (*cIt)->getSurface();
            mTextures[cIt - mCaptures.begin()] = gl::Texture::create( surf );
        }
    }
}

void Cam::draw()
{
    gl::enableAlphaBlending();
    gl::clear( Color::black() );
    
    if( mCaptures.empty() )
        return;
    
    float width = getWindowWidth() ;/// mCaptures.size();
    float height = width / ( WIDTH / (float)HEIGHT );
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        // draw the latest frame
        gl::color( Color::white() );
        if( mTextures[cIt-mCaptures.begin()] )
            gl::draw( mTextures[cIt-mCaptures.begin()], Rectf( 0, 0, width, height ) );
    }
}
ci::Surface Cam::getSurf(){
    gl::enableAlphaBlending();
    gl::clear( Color::black() );
    float width = getWindowWidth() ;/// mCaptures.size();
    float height = width / ( WIDTH / (float)HEIGHT );
    for( vector<CaptureRef>::iterator cIt = mCaptures.begin(); cIt != mCaptures.end(); ++cIt ) {
        // draw the latest frame
        gl::color( Color::white() );
        try{
            if( mTextures[cIt-mCaptures.begin()] ){
                gl::draw( mTextures[cIt-mCaptures.begin()], Rectf( 0, 0, width, height ) );
            }
        } catch ( ... ){
            ci::app::console() << "issue detected";
        }
    }
    return copyWindowSurface();
}

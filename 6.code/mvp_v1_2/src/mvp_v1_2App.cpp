#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Book.h"
#include "Track.h"
#include "Interface.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class mvp_v1_2App : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    Book book;
    Track track;
    Interface ui;
    
};

void mvp_v1_2App::setup()
{
    app::setWindowSize(1440, 900);
    app::setWindowPos(0, 0);
    ui.setup(2);
    track.setup();
}


void mvp_v1_2App::update()
{
    track.update();
    if(book.isset){
        book.topPos = track.updateCorner(book.topPos);
        book.downPos = track.updateCorner(book.downPos);
    }
    ui.updateBookPos(book.topPos, book.downPos);
}

void mvp_v1_2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    track.draw();
    
    if(book.isset){
        //console() << "init" << "\n";
        //track book corner and colorcode;
        int pageCode = track.getPageCode(book.topPos, book.downPos);
        if(pageCode == 1){
            console() << "codemoment \n";
            //draw codeMoment;
            //track code written on page
            int levCode = 0;
            book.drawCode(levCode, track.greenCard(ui.greenCard));
            ui.drawCodeMoment(0);
            
        } else if(pageCode == 2){
            
            ui.drawGreenCard();
            //draw Green card
            
        } else if(pageCode == 3){
            
            ui.drawFinal();
            //draw stats
            
        } else if(pageCode == -1){
            
            ci::app::console() << "problem \n";
            
        } else if(pageCode == 0){
            
            //no issue, normal page;
            
        }
    } else {
        ui.drawBookScan();
        int code = track.getTagId(ui.scanAreas.at(0), true);
        if(book.Exists(code)){
            book.setup(code);
            
            //start scanning for different pages
            book.topPos = Vec2i(ui.bookArea.x1, ui.bookArea.y2);
            book.downPos = Vec2i(ui.bookArea.x2, ui.bookArea.y2);
            console() << book.topPos << "\n";
            
        }
    }
    
}

CINDER_APP_NATIVE( mvp_v1_2App, RendererGl )

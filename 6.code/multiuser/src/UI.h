//
//  UI.h
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//
#include "CodeMoment.h"
#include "cinder/Utilities.h"
#include "cinder/gl/Texture.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class UI{
    public:
    void showSettings();
    void showScanner(ci::Area ar);
    void showCodeMomentScanner(ci::Area ar);
    void showGreenScanner(ci::Area ar);
    void showCodeMoment(CodeMoment cm, ci::Area ar);
    
    Boolean settingsVis = true;
    
    
    std::vector<Area> scanArs;
};
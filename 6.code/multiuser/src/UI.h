//
//  UI.h
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

class UI{
    public:
    void showSettings();
    void showScanner(ci::Area ar);
    void showCodeMomentScanner(ci::Area ar);
    void showGreenScanner(ci::Area ar);
    
    
    Boolean settingsVis = true;
};
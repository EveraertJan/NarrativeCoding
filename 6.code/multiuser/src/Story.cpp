//
//  Story.cpp
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

#include "Story.h"



Boolean Story::exists(int bookID){
    //in een verdere ontwikkeling is het hier mogelijk online een bestand uit te lezen waarin alle id's van elk boek uitgeschreven staan, waardoor de applicatie de bestaande boeken kan herkennen
    if(bookID == 1552){
        return true;
    } else {
        return false;
    }
}

void Story::loadStory(int bookId){
    ci::XmlTree doc( ci::app::loadAsset("book1552.xml" ) );
    ci::XmlTree bookxml = doc.getChild( "story" );
    
    
    /*
     * in deze stap worden alle codemomenten opgeslagen in een corresponderende klasse
     */
    for( XmlTree::Iter codeMoment = bookxml.begin(); codeMoment != bookxml.end(); ++codeMoment ){
        CodeMoment cmpush;
        for( XmlTree::Iter tag = codeMoment->begin(); tag != codeMoment->end(); ++tag ){
            if(tag->getTag() == "id"){
                cmpush.id=tag->getValue<int>();
                //app::console()<< tag->getValue<int>() << "\n";
            } else if(tag->getTag() == "background"){
                cmpush.backgroundurl=tag->getValue();
                //console() << cmpush.backgroundurl << "\n";
            } else if(tag->getTag() == "placement"){
                cmpush.placementurl=tag->getValue();
                //console() << cmpush.placementurl << "\n";
            } else if(tag->getTag() == "numCards"){
                cmpush.maxCards=tag->getValue<int>();
                //console() << cmpush.numcards << "\n";
            }
        }
        cmpush.curCards = 2;
        cm.push_back(cmpush);
    
    }
    currentCodeMoment = 0;
}

Boolean Story::cmExists(int codeMID){
    int result = 0;
    for(int i = 0; i<cm.size(); i++){
        if(codeMID == cm.at(i).id){
            result++;
        }
    }
    if(result != 0){
        return true;
    } else {
        return false;
    }
}


//
//  Story.h
//  multiuser
//
//  Created by jan everaert on 07/06/15.
//
//

#pragma once
#include "cinder/Xml.h"
#include "CodeMoment.h"
#include "cinder/Utilities.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Story{
public:
    Boolean exists(int bookID);
    void loadStory(int bookId);
    Boolean cmExists(int codeMID);

    std::vector<CodeMoment> cm;
};
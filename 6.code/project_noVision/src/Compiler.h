//
//  Compiler.h
//  project_noVision
//
//  Created by jan everaert on 21/04/15.
//
//

#include "cinder/app/AppBasic.h"
#include "Subject.h"
#include "CMovement.h"

class Compiler{
public:
    void setup();
    void update();
    void draw();
    Boolean checkCode(std::vector<int> input);
    
    
    Subject s;
    
    std::vector<CMovement> moves;
};
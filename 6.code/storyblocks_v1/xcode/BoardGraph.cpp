//
//  Board.cpp
//  CinderProject
//
//  Created by jan everaert on 21/03/15.
//
//

#include "BoardGraph.h"


void Board::setup(){
    
}
void Board::setup(std::vector<ci::Vec2f> p){
    points = p;
}
void Board::draw(){
    ci::gl::color(255, 0, 0);
    for(int i  =0; i<points.size(); i++){
        ci::gl::drawStrokedCircle(points[i], i+2);
    }
    avgP.push_back(points[0]);
    if(avgP.size()>10){
        avgP.erase (avgP.begin());
    }
    ci::Vec2f avgPoint = ci::Vec2f(0, 0);
    for(int i = 0; i<avgP.size(); i++){
        avgPoint +=avgP[i];
    }
    ci::gl::pushMatrices();
    if(rotation.size()>3){
        rotation.erase (rotation.begin());
    }
    float avgR = 0;
    for(int i = 0; i<rotation.size(); i++){
        avgR+=rotation[i];
    }
    if(curRot<avgR/rotation.size()){
        curRot+=abs((avgR/rotation.size())-curRot)/2;
    } else if(curRot>avgR/rotation.size()){
        curRot-=abs((avgR/rotation.size())-curRot)/2;
    }
    if(curPoint.x<avgPoint.x/avgP.size()){
        curPoint.x+=abs((avgPoint.x/avgP.size())-curPoint.x)/2;
    } else if(curPoint.x>avgPoint.x/avgP.size()){
        curPoint.x-=abs((avgPoint.x/avgP.size())-curPoint.x)/2;
    }
    if(curPoint.y<avgPoint.y/avgP.size()){
        curPoint.y+=abs((avgPoint.y/avgP.size())-curPoint.y)/2;
    } else if(curPoint.y>avgPoint.y/avgP.size()){
        curPoint.y-=abs((avgPoint.y/avgP.size())-curPoint.y)/2;
    }
    ci::gl::translate(avgPoint/avgP.size());
    ci::gl::rotate(curRot);
    ci::gl::drawSolidRect(ci::Rectf(0, 0, 200, 100));
    
    ci::gl::popMatrices();

}
void Board::draw(int x, int y){
    ci::gl::color(255, 0, 0);
    for(int i = 0; i<points.size(); i++){
        ci::Vec2f p = ci::Vec2f(points[i].x+x, points[i].y+y);
        ci::gl::drawStrokedCircle(p, i+2);
    }
    ci::gl::pushMatrices();
    ci::gl::drawSolidRect(ci::Rectf(points[3].x,points[3].y, points[3].x+300, points[3].y+100));
    float avgR = 0;
    for(int i = 0; i<rotation.size(); i++){
        avgR+=rotation[i];
    }
    
    ci::gl::rotate(floor(avgR/rotation.size()));
    ci::gl::popMatrices();
}
void Board::update(){
    
}
//
//  Flower.cpp
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-19.
//

#include <stdio.h>
#include "Flower.h"
#include <vector>
#include <iostream>

Flower::Flower(int numPetals, int radius, int index)
    : numPetals_(numPetals)
    ,radius_(radius)
    ,index_(index)
{}

void Flower::setup() {
    int xBounds = ofGetWindowWidth()/2;
    int yBounds = ofGetWindowHeight()/2;
    int randomX = ofRandom(-(xBounds), xBounds);
    int randomY = ofRandom(-(yBounds), yBounds);
    int randomZ = ofRandom(-ofGetWindowWidth(),0);
    this->setPosition(ofVec3f(randomX,randomY,randomZ));

    for (unsigned i = 0; i < numPetals_; ++i) {
        float theta = TWO_PI / numPetals_;
        float angle = theta * i;
        petals_.push_back(Petal(cos(angle) * radius_,  sin(angle) * radius_, 0, angle, *this, i));
    }
    for (unsigned i=0; i < petals_.size(); ++i) {
        petals_[i].setParent(*this);
        petals_[i].setup();
    }
    sphere_.setParent(*this);
    sphere_.setScale(2, 2, 1);
    sphere_.set(radius_,200);
    stems_.push_back(Stem(*this, index_));
    stems_[0].setParent(*this);
    stems_[0].setup();
}

void Flower::update() {}

void Flower::draw() {
    this->panDeg(sin(this->getZ() * radius_));
    stems_[0].draw();
    ofPushMatrix();
    float time = ofGetElapsedTimef();
   // ofSetColor(106 * this->getY(),30 * this->getY(), 30 * this->getX(), 100);
    ofSetColor(204 + 50*cos(time + index_ * 0.14),
               204 + 50*cos(time + index_ * 0.1),
               204 + 50*cos(time + index_ * 0.12));

    //ofSetColor(0,105,180, 50);
    sphere_.draw();
    //Should be defined in the class or?
    std::string infoRadius = "FLOWER RADIUS_: "+ofToString(radius_, 2);
    ofDrawBitmapString(infoRadius, this->getX(),this->getY(), this->getZ());
    std::string infoNumPetals = "FLOWER NUMPETALS_: "+ofToString(numPetals_, 2);
    ofDrawBitmapString(infoNumPetals, this->getX(),this->getY() + 20, this->getZ());
    std::string infoPanDeg = "ROTATION AROUND X-AXIS: "+ofToString(this->getXAxis());
    ofDrawBitmapString(infoPanDeg, this->getX(),this->getY() + 40, this->getZ());
    ofPopMatrix();
    for(unsigned i=0; i < petals_.size(); ++i) {
        petals_[i].draw();
    }
}

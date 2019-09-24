//
//  Petal.cpp
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-20.
//

#include <stdio.h>
#include "Petal.h"
#include <vector>
#include <iostream>

Petal::Petal(float posx, float posy, float posz, float rotationAngle, ofNode parent, int index)
    : posx_(posx)
    , posy_(posy)
    , posz_(posz)
    , rotationAngle_(rotationAngle)
    , parent_(parent)
    , index_(index)
{}

void Petal::setup() {
    this->setPosition(posx_,posy_,posz_);
    this->move(posx_,posy_,posz_);
    this->rotateRad(rotationAngle_,0,0,1);
    sphere_.setParent(*this);
    sphere_.setScale(3, 1, 1);
}

void Petal::update() {}

void Petal::draw() {
    ofPushMatrix();
    float time = ofGetElapsedTimef();
    //ofSetColor(190 * abs(sin(time)),30,30, 100);
    //ofSetColor(249,102,0, 50);
    ofSetColor(204 + 50*sin(time + index_ * 0.14),
               204 + 50*sin(time + index_ * 0.1),
               204 + 50*sin(time + index_ * 0.12));
    sphere_.draw();
    ofPopMatrix();
}

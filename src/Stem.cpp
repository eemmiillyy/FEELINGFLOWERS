//
//  Stem.cpp
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-21.
//

#include <stdio.h>
#include "Stem.h"

Stem::Stem(ofNode parent, int index)
    : parent_(parent)
    , index_(index)
{}

void Stem::setup() {
    cylinder_.setParent(*this);
    cylinder_.set(index_ * 1.5, ofGetWindowHeight() );
    cylinder_.setPosition(0, 0 - 300, 0);
}

void Stem::update(){}

void Stem::draw(){
    //cylinder_.rotate(1, 0, 1.0, 0.0);
    cylinder_.draw();
}

#include "Stem.h"

Stem::Stem(){}

void Stem::setup(int radius) {
    cylinder_.setParent(*this);
    cylinder_.set(radius * 0.5, ofGetWindowHeight());
    cylinder_.setPosition(0, 0 - 300, 0);
}

void Stem::draw(){
    cylinder_.draw();
}

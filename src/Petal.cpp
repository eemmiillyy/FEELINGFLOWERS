#include "Petal.h"

Petal::Petal(ofNode parent, int index)
    : parent_(parent)
    , index_(index)
{}

void Petal::setup() {
    sphere_.setParent(*this);
    sphere_.setScale(3, 1, 1);
}

void Petal::draw() {
    ofPushMatrix();
    float time = ofGetElapsedTimef();
    ofSetColor(204 + 50*sin(time + index_ * 0.14),
               204 + 50*sin(time + index_ * 0.1),
               204 + 50*sin(time + index_ * 0.12));
    sphere_.draw();
    ofPopMatrix();
}

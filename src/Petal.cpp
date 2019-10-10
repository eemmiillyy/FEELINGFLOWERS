#include "Petal.h"

Petal::Petal(int index)
    : index_(index)
{}

void Petal::setup() {
    sphere_.setParent(*this);
    sphere_.setScale(4, 1, 1);
}

void Petal::draw() {
    ofPushMatrix();
    float time = ofGetElapsedTimef();
    ofSetColor(204 + 50*sin(time + index_ % 20 * 0.64),
               204 + 50*sin(time + index_  % 20  * 0.46),
               204 + 50*sin(time + index_  % 20 * 0.68)
               );
    sphere_.draw();
    ofPopMatrix();
}


#include "Petal.h"

Petal::Petal(int index)
    : index_(index)
{}

void Petal::setup() {
    sphere_.setParent(*this);
    sphere_.setScale(0, 0, 0);
}

void Petal::update(float smileDegree) {
    if (grown) {
        return;
    }
    if (sphere_.getScale().x == 4) {
        sphere_.setScale(4, 1, 1);
        grown = true;
    }
    else if (!grown) {
        sphere_.setScale(smileDegree * 4, smileDegree, smileDegree);
    }
}

void Petal::draw() {
    float time = ofGetElapsedTimef();
    ofSetColor(204 + 50*sin(time + index_ % 20 * 0.64),
               204 + 50*sin(time + index_  % 20  * 0.46),
               204 + 50*sin(time + index_  % 20 * 0.68)
               );
    sphere_.draw();
}


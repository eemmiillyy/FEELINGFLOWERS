#include "Center.h"

Center::Center(){}

void Center::setup(float radius) {
    radius_ = radius;
    sphere_.setParent(*this);
    sphere_.setScale(0, 0, 0);
    sphere_.set(radius_,200);
    grown = false;
}

void Center::update(float smileDegree) {
    if (grown) {
        return;
    }
    if (sphere_.getRadius() == radius_) {
        sphere_.setScale(2, 2, 1);
        grown = true;
    }
    else if (!grown) {
        sphere_.setScale(smileDegree * 2, smileDegree * 2, smileDegree);
    }
}

void Center::draw() {
    sphere_.draw();
}

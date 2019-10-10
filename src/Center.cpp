#include "Center.h"

Center::Center(){}

void Center::setup(float radius) {
    sphere_.setParent(*this);
    sphere_.setScale(2, 2, 1);
    sphere_.set(radius,200);
}

void Center::draw() {
    sphere_.draw();
}

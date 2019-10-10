#include "Stem.h"

Stem::Stem(){}

void Stem::setup(float radius, float height) {
    radius_ = radius;
    height_ = height;
    cylinder_.setParent(*this);
    cylinder_.setRadius(radius_);
    cylinder_.setPosition(0,-height_,0);
}

//pass in end Y from parent?
//callback to flower saying stem is complete
void Stem::update(float smileDegree) {
    //*this->getParent()->updateCenter();
    bool grownFlag = false;
    cylinder_.setHeight(height_ * smileDegree);
    float startingPos = -height_;
    float currentPosY = cylinder_.getY();
    float endPosition = 0;
    
    if (currentPosY < 0) {
        startingPos = startingPos + (height_ * smileDegree/2);
        cylinder_.setPosition(0,startingPos,0);
    }
}

void Stem::draw() {
    cylinder_.draw();
}

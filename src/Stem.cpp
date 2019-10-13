#include "Stem.h"

Stem::Stem(){}

void Stem::setup(float radius, float height) {
    height_ = height;
    cylinder_.setParent(*this);
    cylinder_.setRadius(radius);
    cylinder_.setPosition(0,-height,0);
    grown = false;
}

void Stem::update(float smileDegree) {
    if (grown) {
        return;
    }
    float startHeight = -height_;
    float endHeight = -height_/2;
    float currentPosY = cylinder_.getY();
    if (currentPosY == endHeight) { //Stem tip has reached point of center node
        float fullHeight = startHeight + (height_ / 2);
        cylinder_.setPosition(0, fullHeight,0);
        grown = true;
    }
    else if (!grown) {
        float fullHeightSmileAdjusted = startHeight + (height_ / 2 * smileDegree);
        cylinder_.setHeight(height_ * smileDegree);
        cylinder_.setPosition(0,fullHeightSmileAdjusted,0);
    }

}

void Stem::draw() {
    cylinder_.draw();
}

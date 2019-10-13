#include <iostream>
#include "Flower.h"

Flower::Flower(int numPetals)
    : numPetals_(numPetals)
{}

void Flower::setup() {
    growthPolicy_.setup(10);
    std::cout << growthPolicy_.getCalculatedStemSpeed() << std::endl;
    
    center_.setParent(*this);
    center_.setup(numPetals_);
    
    stem_.setParent(*this);
    stem_.setup(numPetals_, 600);
    
    petals_.reserve(numPetals_);
    for (unsigned i = 0; i < numPetals_; ++i) {
        petals_.push_back(Petal(i));
    }
    float theta = TWO_PI / numPetals_;
    int i = 0;
    for (auto& petal : petals_) {
        ++i;
        petal.setParent(*this);
        petal.setup();
        float angle = theta * i;
        float posx_ = cos(angle) * numPetals_;
        float posy_ = sin(angle) * numPetals_;
        float posz_ = 0;
        petal.setPosition(ofVec3f(posx_,posy_,posz_));
        petal.move(ofVec3f(posx_,posy_,posz_));
        petal.rotateRad(angle,0,0,1);
    }
}

void Flower::draw() {
    stem_.draw();
    center_.draw();
    for(auto& petal : petals_) {
        petal.draw();
    }
}

void Flower::grow(float smileDegree) {
    stem_.update(smileDegree);
    if (stem_.grown) {
        center_.update(smileDegree);
        if (center_.grown) {
            for(auto& petal : petals_) {
                petal.update(smileDegree);
            }
        }
    }
}


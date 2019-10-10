#include "Flower.h"

Flower::Flower(int numPetals)
    : numPetals_(numPetals)
{}

void Flower::setup() {
    center_.setParent(*this);
    center_.setup(numPetals_);
    
    stem_.setParent(*this);
    stem_.setup(numPetals_, 600);
    
    petals_.reserve(numPetals_);
    float theta = TWO_PI / numPetals_;

    for (unsigned i = 0; i < numPetals_; ++i) {
        Petal petal_ = Petal(i);
        petals_.push_back(petal_);
        
        petals_[i].setParent(*this);
        petals_[i].setup();
        float angle = theta * i;
        float posx_ = cos(angle) * numPetals_;
        float posy_ = sin(angle) * numPetals_;
        float posz_ = 0;
        petals_[i].setPosition(ofVec3f(posx_,posy_,posz_));
        petals_[i].move(ofVec3f(posx_,posy_,posz_));
        petals_[i].rotateRad(angle,0,0,1);
    }
}

void Flower::draw() {
    stem_.draw();
    center_.draw();
    for(auto& petal : petals_) {
        petal.draw();
    }
}

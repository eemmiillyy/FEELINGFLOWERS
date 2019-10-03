#include "Flower.h"

Flower::Flower(int numPetals, int radius)
    : numPetals_(numPetals)
    ,radius_(radius)
{}

void Flower::setup() {
    petals_.reserve(numPetals_);
    float theta = TWO_PI / numPetals_;

    for (unsigned i = 0; i < numPetals_; ++i) {
        Petal petal_ = Petal(*this, i);
        petals_.push_back(petal_);
        
        petals_[i].setParent(*this);
        petals_[i].setup();
        float angle = theta * i;
        float posx_ = cos(angle) * radius_;
        float posy_ = sin(angle) * radius_;
        float posz_ = 0;
        petals_[i].setPosition(ofVec3f(posx_,posy_,posz_));
        petals_[i].move(ofVec3f(posx_,posy_,posz_));
        petals_[i].rotateRad(angle,0,0,1);
    }
    
    sphere_.setParent(*this);
    sphere_.setScale(2, 2, 1);
    sphere_.set(radius_,200);
    
    stem_.setParent(*this);
    stem_.setup(radius_);
}

void Flower::draw() {
    stem_.draw();
    sphere_.draw();
 
    for(auto& petal : petals_) {
        petal.draw();
    }
}

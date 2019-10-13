#include "GrowthPolicy.h"

GrowthPolicy::GrowthPolicy(){}

void GrowthPolicy::setup(float stemGrowthSpeed){
    stemGrowthSpeed_ = stemGrowthSpeed;
    computeStemSpeed();
}

void GrowthPolicy::computeStemSpeed(){
    stemGrowthSpeed_ += 20;
}

float GrowthPolicy::getCalculatedStemSpeed() {
    return stemGrowthSpeed_;
}




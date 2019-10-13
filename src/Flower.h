#ifndef Flower_h
#define Flower_h

#include "Center.h"
#include "Petal.h"
#include "Stem.h"
#include "GrowthPolicy.h"

class Flower : public ofNode {
    public:
        Flower(int numPetals);
        void setup();
        void draw();
        void grow(float smileDegree);
        int numPetals_;
        std::vector < Petal > petals_;
        Stem stem_;
        Center center_;
        GrowthPolicy growthPolicy_;
};

#endif /* Flower_h */

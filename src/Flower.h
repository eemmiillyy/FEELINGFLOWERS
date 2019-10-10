#ifndef Flower_h
#define Flower_h

#include "Center.h"
#include "Petal.h"
#include "Stem.h"

class Flower : public ofNode {
    public:
        Flower(int numPetals);
        void setup();
        void draw();
    private:
        int numPetals_;
        std::vector < Petal > petals_;
        Stem stem_;
        Center center_;
};

#endif /* Flower_h */

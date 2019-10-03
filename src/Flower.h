#ifndef Flower_h
#define Flower_h

#include "Petal.h"
#include "Stem.h"

class Flower : public ofNode {
    public:
        Flower(int numPetals, int radius);
        void setup();
        void draw();
    private:
        int numPetals_;
        int radius_;
        std::vector < Petal > petals_;
        ofSpherePrimitive sphere_;
        Stem stem_;
};

#endif /* Flower_h */

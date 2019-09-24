//
//  Flower.h
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-19.
//

#ifndef Flower_h
#define Flower_h
#include "Stem.h"
#include "Petal.h"
#include "ofNode.h"
#include "ofVec3f.h"
#include "of3dPrimitives.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"
#include "of3dUtils.h"
#include <vector>

class Flower : public ofNode {
    public:
        Flower(int numPetals, int radius, int index);
        void setup();
        void draw();
        void update();
    private:
        ofSpherePrimitive sphere_;
        ofVec3f position_;
        int numPetals_;
        int radius_;
        int index_;
        std::vector < Stem > stems_;
        std::vector < Petal > petals_;
};

#endif /* Flower_h */

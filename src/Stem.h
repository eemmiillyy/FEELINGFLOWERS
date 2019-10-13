#ifndef Stem_h
#define Stem_h

#include "of3dGraphics.h"

class Stem : public ofNode {
    public:
        Stem();
        void setup(float radius, float height);
        void draw();
        void update(float smileDegree);
        ofCylinderPrimitive cylinder_;
        float height_;
        bool grown;
};

#endif /* Stem_h */

#ifndef Stem_h
#define Stem_h

#include "of3dGraphics.h"

class Stem : public ofNode {
    public:
        Stem();
        void setup(float radius, float height);
        void draw();
        void update(float smileDegree);
    private:
        float radius_;
        float height_;
        ofCylinderPrimitive cylinder_;
};

#endif /* Stem_h */

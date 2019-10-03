#ifndef Stem_h
#define Stem_h

#include "of3dGraphics.h"

class Stem : public ofNode {
    public:
        Stem();
        void setup(int index);
        void draw();
    private:
        ofCylinderPrimitive cylinder_;
};

#endif /* Stem_h */

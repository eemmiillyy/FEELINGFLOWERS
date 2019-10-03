#ifndef Petal_h
#define Petal_h

#include "of3dGraphics.h"
#include "ofGraphics.h"

class Petal : public ofNode {
    public:
        Petal(ofNode parent, int index);
        void setup();
        void draw();
    private:
        ofNode parent_;
        ofSpherePrimitive sphere_;
        int index_;
};

#endif /* Petal_h */

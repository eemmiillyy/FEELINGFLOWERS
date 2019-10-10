#ifndef Petal_h
#define Petal_h

#include "of3dGraphics.h"
#include "ofGraphics.h"

class Petal : public ofNode {
    public:
        Petal(int index);
        void setup();
        void draw();
    private:
        ofSpherePrimitive sphere_;
        int index_;
};

#endif /* Petal_h */

#ifndef Center_h
#define Center_h

#include "of3dGraphics.h"

class Center : public ofNode {
    public:
        Center();
        void setup(float radius);
        void draw();
    private:
        ofSpherePrimitive sphere_;
};

#endif /* Center_h */

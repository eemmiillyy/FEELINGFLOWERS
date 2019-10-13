#ifndef Center_h
#define Center_h

#include "of3dGraphics.h"

class Center : public ofNode {
    public:
        Center();
        void setup(float radius);
        void draw();
        void update(float smileDegree);
        ofSpherePrimitive sphere_;
        float radius_;
        bool grown;
};

#endif /* Center_h */

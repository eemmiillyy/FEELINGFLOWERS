//
//  Petal.h
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-20.
//

#ifndef Petal_h
#define Petal_h
#include <stdio.h>
#include "ofNode.h"
#include "of3dPrimitives.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"
#include "of3dUtils.h"

class Petal : public ofNode {
    public:
        Petal(float posx, float posy, float posz, float rotationAngle, ofNode parent, int index);
        void setup();
        void update();
        void draw();
    private:
        ofNode parent_;
        ofSpherePrimitive sphere_;
        float posx_;
        float posy_;
        float posz_;
        float rotationAngle_;
        float index_;
};

#endif /* Petal_h */

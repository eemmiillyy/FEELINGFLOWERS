//
//  Stem.hpp
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-21.
//

#ifndef Stem_h
#define Stem_h
#include <stdio.h>
#include "Petal.h"
#include "ofNode.h"
#include "ofVec3f.h"
#include "of3dPrimitives.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"
#include "of3dUtils.h"
#include <vector>

class Stem :  public ofNode {
    public:
        Stem(ofNode parent, int index);
        void setup();
        void update();
        void draw();
    private:
        ofNode parent_;
        ofCylinderPrimitive cylinder_;
        float index_;
};

#endif /* Stem_h */

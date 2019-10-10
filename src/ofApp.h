#pragma once

#include "SmileDetector.h"
#include "ofMain.h"
#include "Flower.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
        void update();
		void draw();
    
        std::vector < Flower > flowers;
        ofMesh mesh;
        ofLight light;
        ofEasyCam scenecam;
        ofPlanePrimitive plane;
        ofMaterial roadMaterial;

        ofVideoGrabber cam;
        SmileDetector smile;
    
        ofColor currentBgColor;
        float smileDegree;
        int flowerCount;
};

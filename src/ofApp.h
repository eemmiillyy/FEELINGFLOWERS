#pragma once

#include "SmileDetector.h"
#include "ofxGui.h"
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
    
        //GUI stuff for later
        ofxPanel gui;
        ofxIntSlider intSlider;
        ofxFloatSlider floatSlider;
        ofxButton button;
    
        ofVideoGrabber cam;
        SmileDetector smile;
};

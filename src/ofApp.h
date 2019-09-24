#pragma once

#include "ofxGui.h"
#include "ofxCv.h" 
#include "ofMain.h"
#include "Flower.h"
#include <vector>
#include <iostream>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector < Flower > flowers;
        ofMesh mesh;
        ofLight light;
        ofEasyCam cam;
        ofPlanePrimitive plane;
        ofMaterial roadMaterial;
    
        //GUI stuff for later
        ofxPanel gui;
        ofxIntSlider intSlider;
        ofxFloatSlider floatSlider;
        ofxButton button;
};

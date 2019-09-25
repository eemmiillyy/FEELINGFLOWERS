#pragma once

#include "SmileDetector.h"
#include "ofxGui.h"
#include "ofMain.h"
#include "Flower.h"
#include <vector>
#include <iostream>

//
//  SmileDetector.cpp
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-25.
//

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

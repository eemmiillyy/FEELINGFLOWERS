#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    cam.setup(640, 480);
    smile.setup();
    ofBackground(0,0,0);
    ofEnableDepthTest();
    scenecam.setGlobalPosition(0, 0, 0);
    light.setParent(scenecam);
    light.setAreaLight(600, 600);
    flowerCount = 20;
    
    for(int i = 0; i < flowerCount; ++i) {
        flowers.push_back(Flower(i * 3));
    }
    
    int i = 0;
    for(auto& flower : flowers) {
        ++i;
        flower.setup();
        int xBounds = ofGetWindowWidth()/2;
        int yBounds = ofGetWindowHeight()/2;
        int randomX = sin(TWO_PI / flowerCount * i)  * 800;
        int randomY = ofRandom(-(yBounds), yBounds);
        int randomZ = cos(TWO_PI / flowerCount * i)  * 800;
        flower.setPosition(ofVec3f(randomX,randomY,randomZ));
    }
    ofColor currentBgColor = ofGetBackgroundColor();
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()){
        smile.update(cam);
        if(smile.getFaceFound()) {
            //for (int i = 0; i < smile.getSmileAmount(); ++i) {
                //float cur = smile.getSmileAmount();
            // }
            smileDegree = smile.getSmileAmount();

            float r = 128 * smileDegree;
            float g = 128 * smileDegree;
            float b = 128 * smileDegree;
            
            float current_r = currentBgColor[0];
            float current_g = currentBgColor[1];
            float current_b = currentBgColor[2];
            
            float combo_r = ofLerp(r, current_r, smileDegree);
            float combo_g = ofLerp(g, current_g, 0.5);
            float combo_b = ofLerp(b, current_b, 0.5);
            
            ofColor bgCol = ofColor(
                               combo_r,
                                128,
                                128);
        }
    }
}

void ofApp::draw(){
    scenecam.begin();
    light.enable();
    for(auto& flower : flowers) {
        flower.draw();
        flower.grow(ofNormalize(smileDegree, 0, 200));
    }
    scenecam.end();
}


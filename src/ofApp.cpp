#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

void ofApp::setup(){
    //SMILE DETECTION
    ofSetVerticalSync(true);
    ofSetFrameRate(120);
    cam.setup(640, 480);
    smile.setup();
    ofBackground(254,254,254);
    ofEnableDepthTest();
    light.setPosition(-100, 200,0);
    light.setSpotlight(85.0, 0.8);
    
    for(int i = 0; i < 10; ++i) {
        flowers.push_back(Flower(i * 8, i * 5));
    }
    
    for(auto& flower : flowers) {
        flower.setup();
        int xBounds = ofGetWindowWidth()/2;
        int yBounds = ofGetWindowHeight()/2;
        int randomX = ofRandom(-(xBounds), xBounds);
        int randomY = ofRandom(-(yBounds), yBounds);
        int randomZ = ofRandom(-ofGetWindowWidth(),0);
        flower.setPosition(ofVec3f(randomX,randomY,randomZ));
    }
    //gui.setup();
    //gui.add(intSlider.setup("int slider", 0,0,300));
}

void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()){
        smile.update(cam);
        if(smile.getFaceFound()) {
            float cur = smile.getSmileAmount();
            ofLog() << ofNormalize(smile.getSmileAmount(), 0, 200);
        }
    }
}

void ofApp::draw(){
    //gui.draw();
    ofSetColor(255);
    cam.draw(0,0);
    smile.draw();
    scenecam.begin();
    light.draw();
    light.enable();
    for(auto& flower : flowers) {
        flower.panDeg(sin(flower.getZ()));
        flower.draw();
    }
    scenecam.end();
}


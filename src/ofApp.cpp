#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(255,82,86);
    ofBackground(254,254,254);
    ofEnableDepthTest();
    light.setPosition(-100, 200,0);
    light.setSpotlight(85.0, 0.8);
    for(int i=0; i < 10; ++i) {
        flowers.push_back(Flower(i*8, i * 5, i));
    }
    std::cout << flowers.size() << "  created. \n";
    for(unsigned i=0; i < flowers.size(); ++i) {
        flowers[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
//    light.draw();
    light.enable();
    for(unsigned i=0; i < flowers.size(); ++i) {
        flowers[i].draw();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//N Equidistant Points on a Sphere
//no algorithm to space any number of points equally on a sphere.


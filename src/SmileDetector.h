//
//  SmileDetector.h
//  FEELINGFLOWERS
//
//  Created by emily morgan on 2019-09-25.
//

#ifndef SmileDetector_h
#define SmileDetector_h
#include <vector>
#include <iostream>
#include "ofxCv.h"
#include "ofRectangle.h"
#include "ofxCv/Utilities.h"
#include "of3dGraphics.h"
#include "ofGraphics.h"
#include "of3dUtils.h"

class SmileDetector {
public:
    ofxCv::ObjectFinder faceFinder;
    ofxCv::ObjectFinder smileFinder;
    void setup(){
        faceFinder.setup("haarcascade_frontalface_default.xml");
        faceFinder.setPreset(ofxCv::ObjectFinder::Accurate);
        faceFinder.setFindBiggestObject(true);
        smileFinder.setup("smiled_05.xml");
        smileFinder.setPreset(ofxCv::ObjectFinder::Sensitive);
        smileFinder.setMinNeighbors(0);
    }
    
    template <class T>
    void update(T& img){
        update(ofxCv::toCv(img));
    }
    
    void update(const cv::Mat& mat) {
        faceFinder.update(mat);
        if(faceFinder.size()) {
            //for (unsigned i = 0; i < faceFinder.size(); ++i) {
                //roi = faceFinder.getObject(i);
                roi = faceFinder.getObject(0);
                float lowerRatio = .35;
                roi.y += roi.height * (1 - lowerRatio);
                roi.height *= lowerRatio;
                cv::Mat faceMat(mat, ofxCv::toCv(roi));
                smileFinder.update(faceMat);
           // }
        }
    }
    void draw() const {}
    bool getFaceFound() const {
        return faceFinder.size();
    }
    ofRectangle getFace() const {
        return faceFinder.getObject(0);
    }
    int getSmileAmount() const {
        if(faceFinder.size()) {
            return smileFinder.size();
        } else {
            return 0;
        }
    }
protected:
    ofRectangle roi;
};

#endif /* SmileDetector_h */

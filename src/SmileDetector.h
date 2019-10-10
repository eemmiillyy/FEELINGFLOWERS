#ifndef SmileDetector_h
#define SmileDetector_h

#include "ofxCv.h"

class SmileDetector {
    public:
        ofxCv::ObjectFinder faceFinder;
        ofxCv::ObjectFinder smileFinder;
        void setup(){
            faceFinder.setup("haarcascade_frontalface_default.xml");
            faceFinder.setPreset(ofxCv::ObjectFinder::Accurate);
            faceFinder.setFindBiggestObject(false);
            faceFinder.setRescale(0.15);
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
                for (unsigned i = 0; i < faceFinder.size(); ++i) {
                    roi = faceFinder.getObject(i);
                    float lowerRatio = .35;
                    roi.y += roi.height * (1 - lowerRatio);
                    roi.height *= lowerRatio;
                    cv::Mat faceMat(mat, ofxCv::toCv(roi));
                    smileFinder.update(faceMat);
//                    for (unsigned i = 0; i < smileFinder.size(); ++i) {
//                        roi = smileFinder.getObject(i);
//                        float lowerRatio = .35;
//                        roi.y += roi.height * (1 - lowerRatio);
//                        roi.height *= lowerRatio;
//                    }
                }
            }
        }
        bool getFaceFound() const {
            return faceFinder.size();
        }
        ofRectangle getFace(int i) const {
            return faceFinder.getObject(i);
        }

        int getSmileAmount() const {
            return smileFinder.size();
        }
    
        ofRectangle getSmile(int i) const {
            return smileFinder.getObject(i);
        }

    protected:
        ofRectangle roi;
};

#endif /* SmileDetector_h */

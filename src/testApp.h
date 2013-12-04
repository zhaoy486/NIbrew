#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#import "ofxSpacebrew.h"

class testApp : public ofBaseApp{
    
public:
    
	void setup();
	void update();
	void draw();
    void exit();
    
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
    
    void userEvent(ofxOpenNIUserEvent & event);
    
	ofxOpenNI openNIDevice;
    
    ofTrueTypeFont verdana;
    
    // create your spacebrew object
    Spacebrew::Connection spacebrew;
    
    
    //joints vector---yuanjin
    void onMessage( Spacebrew::Message & m );
    ofVec2f torso;
    ofVec2f neck;
    ofVec2f head;
    
    ofVec2f leftShoulder;
    ofVec2f leftElbow;
    ofVec2f leftHand;
    ofVec2f rightShoulder;
    ofVec2f rightElbow;
    ofVec2f rightHand;
    
    ofVec2f leftHip;
    ofVec2f leftKnee;
    ofVec2f leftFoot;
    
    ofVec2f rightHip;
    ofVec2f rightKnee;
    ofVec2f rightFoot;
    
    ofVec2f centerHand;
    
    float squareDistance;
    deque<ofVec2f> pointsOnLine;
    //joints int
    int torsoX;
    int torsoY;
    int neckX;
    int neckY;
    int headX;
    int headY;
    
    int leftShoulderX;
    int leftShoulderY;
    int leftElbowX;
    int leftElbowY;
    int leftHandX;
    int leftHandY;
    
    int rightShoulderX;
    int rightShoulderY;
    int rightElbowX;
    int rightElbowY;
    int rightHandX;
    int rightHandY;
    
    int leftHipX;
    int leftHipY;
    int leftKneeX;
    int leftKneeY;
    int leftFootX;
    int leftFootY;
    
    int rightHipX;
    int rightHipY;
    int rightKneeX;
    int rightKneeY;
    int rightFootX;
    int rightFootY;
    
    
};

#endif

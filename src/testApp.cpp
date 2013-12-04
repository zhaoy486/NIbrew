#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
    // init spacebrew
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "of-noise-example";
    string description = "Super complex joints sender";
    
    
    //--------------yuanjin edit---------------
    //------------send signal-----------
    spacebrew.addPublish("torsoX", "range");
    spacebrew.addPublish("torsoY", "range");
    spacebrew.addPublish("neckX", "range");
    spacebrew.addPublish("neckY", "range");
    spacebrew.addPublish("headX", "range");
    spacebrew.addPublish("headY", "range");
    
    spacebrew.addPublish("leftShoulderX", "range");
    spacebrew.addPublish("leftShoulderY", "range");
    spacebrew.addPublish("leftElbowX", "range");
    spacebrew.addPublish("leftElbowY", "range");
    spacebrew.addPublish("leftHandX", "range");
    spacebrew.addPublish("leftHandY", "range");
    
    spacebrew.addPublish("rightShoulderX", "range");
    spacebrew.addPublish("rightShoulderY", "range");
    spacebrew.addPublish("rightElbowX", "range");
    spacebrew.addPublish("rightElbowY", "range");
    spacebrew.addPublish("rightHandX", "range");
    spacebrew.addPublish("rightHandY", "range");
    
    spacebrew.addPublish("leftHipX", "range");
    spacebrew.addPublish("leftHipY", "range");
    spacebrew.addPublish("leftKneeX", "range");
    spacebrew.addPublish("leftKneeY", "range");
    spacebrew.addPublish("leftFootX", "range");
    spacebrew.addPublish("leftFootY", "range");
    
    spacebrew.addPublish("rightHipX", "range");
    spacebrew.addPublish("rightHipY", "range");
    spacebrew.addPublish("rightKneeX", "range");
    spacebrew.addPublish("rightKneeY", "range");
    spacebrew.addPublish("rightFootX", "range");
    spacebrew.addPublish("rightFootY", "range");
    
    //------------receive---------------------
 
    spacebrew.addSubscribe("torsoX", "range");
    spacebrew.addSubscribe("torsoY", "range");
    spacebrew.addSubscribe("neckX", "range");
    spacebrew.addSubscribe("neckY", "range");
    spacebrew.addSubscribe("headX", "range");
    spacebrew.addSubscribe("headY", "range");
    
    spacebrew.addSubscribe("leftShoulderX", "range");
    spacebrew.addSubscribe("leftShoulderY", "range");
    spacebrew.addSubscribe("leftElbowX", "range");
    spacebrew.addSubscribe("leftElbowY", "range");
    spacebrew.addSubscribe("leftHandX", "range");
    spacebrew.addSubscribe("leftHandY", "range");
    
    spacebrew.addSubscribe("rightShoulderX", "range");
    spacebrew.addSubscribe("rightShoulderY", "range");
    spacebrew.addSubscribe("rightElbowX", "range");
    spacebrew.addSubscribe("rightElbowY", "range");
    spacebrew.addSubscribe("rightHandX", "range");
    spacebrew.addSubscribe("rightHandY", "range");
    
    spacebrew.addSubscribe("leftHipX", "range");
    spacebrew.addSubscribe("leftHipY", "range");
    spacebrew.addSubscribe("leftKneeX", "range");
    spacebrew.addSubscribe("leftKneeY", "range");
    spacebrew.addSubscribe("leftFootX", "range");
    spacebrew.addSubscribe("leftFootY", "range");
    
    spacebrew.addSubscribe("rightHipX", "range");
    spacebrew.addSubscribe("rightHipY", "range");
    spacebrew.addSubscribe("rightKneeX", "range");
    spacebrew.addSubscribe("rightKneeY", "range");
    spacebrew.addSubscribe("rightFootX", "range");
    spacebrew.addSubscribe("rightFootY", "range");
    
    torsoX=0;
    torsoY=0;
    neckX=0;
    neckY=0;
    headX=0;
    headY=0;
    
    leftShoulderX=0;
    leftShoulderY=0;
    leftElbowX=0;
    leftElbowY=0;
    leftHandX=0;
    leftHandY=0;
    
    rightShoulderX=0;
    rightShoulderY=0;
    rightElbowX=0;
    rightElbowY=0;
    rightHandX=0;
    rightHandY=0;
    
    leftHipX=0;
    leftHipY=0;
    leftKneeX=0;
    leftKneeY=0;
    leftFootX=0;
    leftFootY=0;
    
    rightHipX=0;
    rightHipY=0;
    rightKneeX=0;
    rightKneeY=0;
    rightFootX=0;
    rightFootY=0;


    spacebrew.connect( host, name, description );
    
    // init OPENNI
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setMaxNumUsers(2);
    openNIDevice.start();
    
    // set properties for all user masks and point clouds
    //openNIDevice.setUseMaskPixelsAllUsers(true); // if you just want pixels, use this set to true
    openNIDevice.setUseMaskTextureAllUsers(true); // this turns on mask pixels internally AND creates mask textures efficiently
    openNIDevice.setUsePointCloudsAllUsers(true);
    openNIDevice.setPointCloudDrawSizeAllUsers(2); // size of each 'point' in the point cloud
    openNIDevice.setPointCloudResolutionAllUsers(2); // resolution of the mesh created for the point cloud eg., this will use every second depth pixel
    
    // you can alternatively create a 'base' user class
    //    ofxOpenNIUser user;
    //    user.setUseMaskTexture(true);
    //    user.setUsePointCloud(true);
    //    user.setPointCloudDrawSize(2);
    //    user.setPointCloudResolution(2);
    //    openNIDevice.setBaseUserClass(user);
    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
}

//--------------------------------------------------------------
void testApp::update(){
    // update spacebrew
    if ( spacebrew.isConnected() ){
//        float noiseFast = ofNoise(ofGetElapsedTimeMillis() * .1) * 1024.0f;
//        float noiseSlow = ofNoise(ofGetElapsedTimef() * .1) * 1024.0f;
//        spacebrew.sendRange("noiseFast", (noiseFast) );
//        spacebrew.sendRange("noiseSlow", (noiseSlow) );
        
        //yuanjin--------------
        spacebrew.sendRange("torsoX", (torso.x) );
        spacebrew.sendRange("torsoY", (torso.y) );
        spacebrew.sendRange("neckX", (neck.x) );
        spacebrew.sendRange("neckY", (neck.y) );
        spacebrew.sendRange("headX", (head.x) );
        spacebrew.sendRange("headY", (head.y) );
        
        spacebrew.sendRange("leftShoulderX", (leftShoulder.x) );
        spacebrew.sendRange("leftShoulderY", (leftShoulder.y) );
        spacebrew.sendRange("leftElbowX", (leftElbow.x) );
        spacebrew.sendRange("leftElbowY", (leftElbow.y) );
        spacebrew.sendRange("leftHandX", (leftHand.x) );
        spacebrew.sendRange("leftHandY", (leftHand.y) );
        
        spacebrew.sendRange("rightShoulderX", (rightShoulder.x) );
        spacebrew.sendRange("rightShoulderY", (rightShoulder.y) );
        spacebrew.sendRange("rightElbowX", (rightElbow.x) );
        spacebrew.sendRange("rightElbowY", (rightElbow.y) );
        spacebrew.sendRange("rightHandX", (rightHand.x) );
        spacebrew.sendRange("rightHandY", (rightHand.y) );
        
        spacebrew.sendRange("leftHipX", (leftHip.x) );
        spacebrew.sendRange("leftHipY", (leftHip.y) );
        spacebrew.sendRange("leftKneeX", (leftKnee.x) );
        spacebrew.sendRange("leftKneeY", (leftKnee.y) );
        spacebrew.sendRange("leftFootX", (leftFoot.x) );
        spacebrew.sendRange("leftFootY", (leftFoot.y) );
        
        spacebrew.sendRange("rightHipX", (rightHip.x) );
        spacebrew.sendRange("rightHipY", (rightHip.y) );
        spacebrew.sendRange("rightKneeX", (rightKnee.x) );
        spacebrew.sendRange("rightKneeY", (rightKnee.y) );
        spacebrew.sendRange("rightFootX", (rightFoot.x) );
        spacebrew.sendRange("rightFootY", (rightFoot.y) );
    }
    
    openNIDevice.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    // draw debug (ie., image, depth, skeleton)
    openNIDevice.drawDebug();
    ofPopMatrix();
    
    ofPushMatrix();
    // use a blend mode so we can see 'through' the mask(s)
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    // get number of current users
    int numUsers = openNIDevice.getNumTrackedUsers();
    
    // iterate through users
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
        
        // draw the mask texture for this user
        user.drawMask();
        
        // you can also access the pixel and texture references individually:
        
        // TEXTURE REFERENCE
        //ofTexture & tex = user.getMaskTextureReference();
        // do something with texture...
        
        // PIXEL REFERENCE
        //ofPixels & pix = user.getMaskPixels();
        // do something with the pixels...
        
        // and point clouds:
        
        
        //joints--yuanjin
        //nori edit
        // if you want x-coordinate leftHand.x
        ofPushMatrix();
        ofScale(1.6,1.6,1); //super hacky by michael.
        
        torso = user.getJoint(JOINT_TORSO).getProjectivePosition();
        neck = user.getJoint(JOINT_NECK).getProjectivePosition();
        head = user.getJoint(JOINT_HEAD).getProjectivePosition();
        
        leftShoulder = user.getJoint(JOINT_LEFT_SHOULDER).getProjectivePosition();
        leftElbow = user.getJoint(JOINT_LEFT_ELBOW).getProjectivePosition();
        leftHand = user.getJoint(JOINT_LEFT_HAND).getProjectivePosition();
        rightShoulder = user.getJoint(JOINT_RIGHT_SHOULDER).getProjectivePosition();
        rightElbow = user.getJoint(JOINT_RIGHT_ELBOW).getProjectivePosition();
        rightHand = user.getJoint(JOINT_RIGHT_HAND).getProjectivePosition();
        
        leftHip = user.getJoint(JOINT_LEFT_HIP).getProjectivePosition();
        leftKnee = user.getJoint(JOINT_LEFT_KNEE).getProjectivePosition();
        leftFoot = user.getJoint(JOINT_LEFT_FOOT).getProjectivePosition();
        
        rightHip = user.getJoint(JOINT_RIGHT_HIP).getProjectivePosition();
        rightKnee = user.getJoint(JOINT_RIGHT_KNEE).getProjectivePosition();
        rightFoot = user.getJoint(JOINT_RIGHT_FOOT).getProjectivePosition();
        
        centerHand = (leftHand + rightHand) /2;
        ofSetColor(0,150,255);
        ofCircle(leftHand.x, leftHand.y, 10);
        
        ofSetColor(255,0,150);
        ofCircle(rightHand.x, rightHand.y, 10);
        //        openNIDevice.drawSkeletons(0, 0, ofGetWidth(), ofGetHeight());
        openNIDevice.drawSkeletons();
        
        //---------------------second skeleton-------------------------
        ofCircle(torsoX, torsoY, 10);
        ofCircle(neckX, neckY, 10);
        ofCircle(headX, headY, 10);
        ofCircle(leftShoulderX, leftShoulderY, 10);
        ofCircle(leftElbowX, leftElbowY, 10);
        ofCircle(leftHandX, leftHandY, 10);
        ofCircle(rightShoulderX, rightShoulderY, 10);
        ofCircle(rightElbowX, rightElbowY, 10);
        ofCircle(rightHandX, rightHandY, 10);
        ofCircle(leftHipX, leftHipY, 10);
        ofCircle(leftKneeX, leftKneeY, 10);
        ofCircle(leftFootX, leftFootY, 10);
        ofCircle(rightHipX, rightHipY, 10);
        ofCircle(rightKneeX, rightKneeY, 10);
        ofCircle(rightFootX, rightFootY, 10);
        
        
        ofPushMatrix();
        // move it a bit more central
        ofTranslate(320, 240, 10);
        user.drawPointCloud();
        
        // you can also access the mesh:
        
        // MESH REFERENCE
        //ofMesh & mesh = user.getPointCloud();
        // do something with the point cloud mesh
        
        ofPopMatrix();
        
    }
    
    ofDisableBlendMode();
    ofPopMatrix();
    
    // draw some info regarding frame counts etc
	ofSetColor(0, 255, 0);
	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate()) + " Device FPS: " + ofToString(openNIDevice.getFrameRate());
    
	verdana.drawString(msg, 20, openNIDevice.getNumDevices() * 480 - 20);
}

//--------------------------------------------------------------
void testApp::userEvent(ofxOpenNIUserEvent & event){
    // show user event messages in the console
    ofLogNotice() << getUserStatusAsString(event.userStatus) << "for user" << event.id << "from device" << event.deviceID;
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
   //----------------------------
    if (m.name=="torsoX") {
        torsoX=m.valueRange();
    }
    if (m.name=="torsoY") {
        torsoY=m.valueRange();
    }
    if (m.name=="neckX") {
        neckX=m.valueRange();
    }
    if (m.name=="neckY") {
        neckY=m.valueRange();
    }
    if (m.name=="headX") {
        headX=m.valueRange();
    }
    if (m.name=="headY") {
        headY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftShoulderX") {
        leftShoulderX=m.valueRange();
    }
    if (m.name=="leftShoulderY") {
        leftShoulderY=m.valueRange();
    }
    if (m.name=="leftElbowX") {
        leftElbowX=m.valueRange();
    }
    if (m.name=="leftElbowY") {
        leftElbowY=m.valueRange();
    }
    if (m.name=="leftHandX") {
        leftHandX=m.valueRange();
    }
    if (m.name=="leftHandY") {
        leftHandY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightShoulderX") {
        rightShoulderX=m.valueRange();
    }
    if (m.name=="rightShoulderY") {
        rightShoulderY=m.valueRange();
    }
    if (m.name=="rightElbowX") {
        rightElbowX=m.valueRange();
    }
    if (m.name=="rightElbowY") {
        rightElbowY=m.valueRange();
    }
    if (m.name=="rightHandX") {
        rightHandX=m.valueRange();
    }
    if (m.name=="rightHandY") {
        rightHandY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="leftHipX") {
        leftHipX=m.valueRange();
    }
    if (m.name=="leftHipY") {
        leftHipY=m.valueRange();
    }
    if (m.name=="leftKneeX") {
        leftKneeX=m.valueRange();
    }
    if (m.name=="leftKneeY") {
        leftKneeY=m.valueRange();
    }
    if (m.name=="leftFootX") {
        leftFootX=m.valueRange();
    }
    if (m.name=="leftFootY") {
        leftFootY=m.valueRange();
    }
    
    
    //----------------------------
    if (m.name=="rightHipX") {
        rightHipX=m.valueRange();
    }
    if (m.name=="rightHipY") {
        rightHipY=m.valueRange();
    }
    if (m.name=="rightKneeX") {
        rightKneeX=m.valueRange();
    }
    if (m.name=="rightKneeY") {
        rightKneeY=m.valueRange();
    }
    if (m.name=="rightFootX") {
        rightFootX=m.valueRange();
    }
    if (m.name=="rightFootY") {
        rightFootY=m.valueRange();
    }
 
    
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}


//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto rotate_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
	for (float z = 30; z < 300; z += 2) {

		ofPushMatrix();

		ofRotateZ(ofMap(ofNoise(rotate_seed.z, z * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, -30, 30));
		ofRotateY(ofMap(ofNoise(rotate_seed.y, z * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, -30, 30));
		ofRotateX(ofMap(ofNoise(rotate_seed.x, z * 0.0035 + ofGetFrameNum() * 0.03), 0, 1, -30, 30));

		ofFill();
		ofSetColor(255, ofMap(z, 300, 30, 255, 55));

		ofDrawRectangle(0, 0, z, 35, 35);

		ofNoFill();
		ofSetColor(0, ofMap(z, 300, 30, 255, 55));

		ofDrawRectangle(0, 0, z, 35, 35);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
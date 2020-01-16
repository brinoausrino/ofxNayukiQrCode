#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(20);

	// set url for QR code
	string url = "https://github.com/brinoausrino/ofxNayukiQrCode";

	// simple use
	qrCode.allocate(512, 512, OF_IMAGE_COLOR_ALPHA);
	ofxNayukiQrCode::getQrCode(qrCode, url, QrCodeSettings());
	
	// customize the creation options
	QrCodeSettings settings;
	settings.setBorder(50, 50);
	settings.colorActivePixel = ofColor(30);
	settings.colorInactivePixel = ofColor::orange;
	settings.colorBorder = ofColor(128);
	
	qrCodeCustom.allocate(512, 512, OF_IMAGE_COLOR_ALPHA);
	ofxNayukiQrCode::getQrCode(qrCodeCustom, url, settings);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	qrCode.draw(30, 30);
	qrCodeCustom.draw(560, 30);
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

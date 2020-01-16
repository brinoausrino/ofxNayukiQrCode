#ifndef _ofxNayukiQrCode
#define _ofxNayukiQrCode

#include "ofMain.h"
#include "QrCode.hpp"

struct QrCodeSettings {
	void setBorder(int left, int right, int top, int bottom) {
		borderLeft = left;
		borderRight = right;
		borderTop = top;
		borderBottom = bottom;
	}

	void setBorder(int horizontal, int vertical) {
		borderLeft = horizontal;
		borderRight = horizontal;
		borderTop = vertical;
		borderBottom = vertical;
	}

	qrcodegen::QrCode::Ecc correctionLevel = qrcodegen::QrCode::Ecc::MEDIUM;
	ofColor colorActivePixel = ofColor(255);
	ofColor colorInactivePixel = ofColor(0);
	ofColor colorBorder = ofColor(0, 0);
	int borderLeft = 0;
	int borderRight = 0;
	int borderTop = 0;
	int borderBottom = 0;
};
	
	class ofxNayukiQrCode{

	public:
		static void getQrCode(ofImage& img, string url, QrCodeSettings settings);
		static void getQrCode(ofTexture& tex, string url, QrCodeSettings settings);
		static ofFbo getQrCode(ofFbo& fbo, string url, QrCodeSettings settings);
	};
#endif
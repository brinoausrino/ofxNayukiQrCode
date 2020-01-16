#include "ofxNayukiQrCode.h"

void ofxNayukiQrCode::getQrCode(ofImage & img, string url, QrCodeSettings settings) {
	ofFbo fbo;
	fbo.allocate(img.getWidth(), img.getHeight());
	getQrCode(fbo, url, settings);
	ofPixels p; 
	fbo.readToPixels(p);
	img.setFromPixels(p);
}

void ofxNayukiQrCode::getQrCode(ofTexture & tex, string url, QrCodeSettings settings) {
	ofFbo fbo;
	fbo.allocate(tex.getWidth(), tex.getHeight());
	getQrCode(fbo, url, settings);
	tex = fbo.getTexture();
}

ofFbo ofxNayukiQrCode::getQrCode(ofFbo & fbo, string url, QrCodeSettings settings) {
	qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(url.c_str(), settings.correctionLevel);

	float wPixel =  min (fbo.getWidth() - settings.borderLeft - settings.borderRight, fbo.getHeight() - settings.borderTop - settings.borderBottom) / qr.getSize();

	ofPushStyle();
	fbo.begin();
	ofClear(0, 0);
	
	// draw bg
	ofSetColor(settings.colorBorder);
	ofDrawRectangle(0, 0, fbo.getWidth(), fbo.getHeight());

	// draw pixels 
	for (int y = 0; y < qr.getSize(); y++) {
		for (int x = 0; x < qr.getSize(); x++) {
			qr.getModule(x, y) == true ? ofSetColor(settings.colorActivePixel) : ofSetColor(settings.colorInactivePixel);
			ofDrawRectangle(x*wPixel + settings.borderLeft, y*wPixel + settings.borderTop, wPixel, wPixel);
		}
	}
	fbo.end();
	ofPopStyle();

	return fbo;
}

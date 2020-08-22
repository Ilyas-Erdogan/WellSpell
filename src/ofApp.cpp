#include "ofApp.h"
#include <iostream>
#include <array>
#include <string>
#include <typeinfo>
//--------------------------------------------------------------
void ofApp::setup(){
	titleFont.load("Berka-Light.ttf",70);
	titleText = "WellSpell";
	overTitleFont.load("Berka-Light.ttf", 20);
	overTitleText = "Welcome to";
	titleFont.load("Berka-Light.ttf", 50);
	startText = "START";
	image.load(location[index]);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {

	// Check if on title screen
	if (displayTitleScreen) {
		ofBackground(72, 209, 204);
		//Title text
		ofSetColor(255);
		titleFont.drawString(titleText, ofGetWidth() / 2 - titleFont.stringWidth(titleText) / 2, ofGetHeight() / 2 - 200);
		ofSetColor(255);
		overTitleFont.drawString(overTitleText, ofGetWidth() / 2 - overTitleFont.stringWidth(overTitleText) / 2, ofGetHeight() / 2 - 300);

		// Display start button
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofRectangle startButton;
		startButton.x = ofGetWidth() / 2;
		startButton.y = ofGetHeight() / 2 + 100;
		startButton.width = 200;
		startButton.height = 100;
		ofDrawRectRounded(startButton, 10);
		// text for Start Button
		ofSetColor(0);
		titleFont.drawString(startText, ofGetWidth() / 2 - 90, ofGetHeight() / 2 + 120);

	}
	else if (gameScreen) {
		ofSetColor(255);
		// Activate session so that location doesn't change
			// Draw image according to name using index
		int i{0}
		index = i;
		image.draw(ofGetWidth() / 2, ofGetHeight() / 2 - 200);
		image.resize(400, 266);

		correctWord = words[i];

		// Draw squares for input
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofRectangle boxOne, boxTwo, boxThree, boxFour, boxFive;
		boxOne.width = boxTwo.width = boxThree.width = boxFour.width = boxFive.width = 40, boxOne.height = boxTwo.height = boxThree.height = boxFour.height = boxFive.height = 40;
		boxOne.y = boxTwo.y = boxThree.y = boxFour.y = boxFive.y = ofGetHeight() / 2 + 60;

		// Check number of letters in word;
		if (words[i].length() == 3) {
			// Draw three squares
			boxOne.x = ofGetWidth() / 2 - 50, boxTwo.x = ofGetWidth() / 2, boxThree.x = ofGetWidth() / 2 + 50;
			ofDrawRectRounded(boxOne, 10);
			ofDrawRectRounded(boxTwo, 10);
			ofDrawRectRounded(boxThree, 10);

			// Draw the correct letters as well as random letters
			ofSetColor(255, 255, 255);
			titleFont.drawString(words[index].substr(1, 1), ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 200); // Real Letter
			titleFont.drawString(rand1, ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(0, 1), ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand2, ofGetWidth() / 2, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(2, 1), ofGetWidth() / 2 + 50, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand3, ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 200); //Fake Letter

		}
		else if (words[i].length() == 4) {
			// Draw four squares
			boxOne.x = ofGetWidth() / 2 - 100, boxTwo.x = ofGetWidth() / 2 - 50, boxThree.x = ofGetWidth() / 2, boxFour.x = ofGetWidth() / 2 + 50;
			ofDrawRectRounded(boxOne, 10);
			ofDrawRectRounded(boxTwo, 10);
			ofDrawRectRounded(boxThree, 10);
			ofDrawRectRounded(boxFour, 10);

			// Draw the correct letters as well as random letters
			ofSetColor(255, 255, 255);
			titleFont.drawString(words[index].substr(1, 1), ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 200); // Real Letter
			titleFont.drawString(rand1, ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(0, 1), ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand2, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(3, 1), ofGetWidth() / 2, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand3, ofGetWidth() / 2 + 50, ofGetHeight() / 2 + 200); //Fake Letter
			titleFont.drawString(words[index].substr(2, 1), ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand4, ofGetWidth() / 2 + 150, ofGetHeight() / 2 + 200); // Fake Leter

		}
		else if (words[i].length() == 5) {
			// Draw five squares
			boxOne.x = ofGetWidth() / 2 - 100, boxTwo.x = ofGetWidth() / 2 - 50, boxThree.x = ofGetWidth() / 2, boxFour.x = ofGetWidth() / 2 + 50, boxFive.x = ofGetWidth() / 2 + 100;
			ofDrawRectRounded(boxOne, 10);
			ofDrawRectRounded(boxTwo, 10);
			ofDrawRectRounded(boxThree, 10);
			ofDrawRectRounded(boxFour, 10);
			ofDrawRectRounded(boxFive, 10);

			// Draw the correct letters as well as random letters
			ofSetColor(255, 255, 255);
			titleFont.drawString(words[index].substr(0, 1), ofGetWidth() / 2 - 250, ofGetHeight() / 2 + 200); // Real Letter
			titleFont.drawString(rand1, ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(3, 1), ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand2, ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(2, 1), ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand3, ofGetWidth() / 2, ofGetHeight() / 2 + 200); //Fake Letter
			titleFont.drawString(words[index].substr(1, 1), ofGetWidth() / 2 + 50, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand4, ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 200); // Fake Leter
			titleFont.drawString(words[index].substr(4, 1), ofGetWidth() / 2 + 150, ofGetHeight() / 2 + 200);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (displayTitleScreen) {
		// Check if mouseis in button area
		if ((x >= ofGetWidth() / 2 - 100 && x <= ofGetWidth() / 2 + 100) && (y >= (ofGetHeight() / 2 + 100) - 50 && y <= (ofGetHeight() / 2 + 100) + 50)) {
			displayTitleScreen = false;
			gameScreen = true;
		}
	}
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

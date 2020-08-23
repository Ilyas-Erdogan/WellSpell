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
	instructText = "INSTRUCTIONS";
	settingsText = "SETTINGS";
	checkmark.load(status[0]);
	checkmark.resize(45, 45);
	xmark.load(status[1]);
	xmark.resize(45, 45);
	wrongSound.load("incorrect_sound.wav");
	correctSound.load("correct_sound.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	// Check if on title screen
	if (displayTitleScreen) {
		ofBackground(26, 65, 46);
		// Draw border of chalkboard
		ofSetColor(221, 166, 74);
		// Left and Right bar
		ofDrawRectangle(0, 0, 40, ofGetHeight() * 2);
		ofDrawRectangle(ofGetWidth(), 0, 40, ofGetHeight() * 2);
		// Top and bottom bar
		ofDrawRectangle(0, 0, ofGetWidth() * 2, 40);
		ofDrawRectangle(0, ofGetHeight(), ofGetWidth() * 2, 40);

		ofSetColor(255, 250, 215);
		//Title text
		ofSetColor(255);
		titleFont.drawString(titleText, ofGetWidth() / 2 - titleFont.stringWidth(titleText) / 2, ofGetHeight() / 2 - 200);
		ofSetColor(255);
		overTitleFont.drawString(overTitleText, ofGetWidth() / 2 - overTitleFont.stringWidth(overTitleText) / 2, ofGetHeight() / 2 - 300);

		// Display start button
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofRectangle startButton;
		startButton.x = ofGetWidth() / 2 - 150;
		startButton.y = ofGetHeight() / 2 + 80;
		startButton.width = 200;
		startButton.height = 100;
		ofDrawRectRounded(startButton, 10);
		// text for Start Button
		ofSetColor(0);
		titleFont.drawString(startText, ofGetWidth() / 2 - 240, ofGetHeight() / 2 + 100);

		// Display instruction button
		ofRectangle instructButton;
		ofSetColor(255);
		instructButton.x = ofGetWidth() / 2 + 150;
		instructButton.y = ofGetHeight() / 2 + 80;
		instructButton.width = 200;
		instructButton.height = 100;
		ofDrawRectRounded(instructButton, 10);
		ofSetColor(0);
		titleFont.load("Berka-Light.ttf", 20);
		titleFont.drawString(instructText, ofGetWidth() / 2 + 62, ofGetHeight() / 2 + 90);

		// Display settings button
		ofRectangle settingsButton;
		ofSetColor(255);
		settingsButton.x = ofGetWidth() / 2;
		settingsButton.y = ofGetHeight() / 2 + 180;
		settingsButton.width = 400;
		settingsButton.height = 40;
		ofDrawRectRounded(settingsButton, 10);
		ofSetColor(0);
		titleFont.load("Berka-Light.ttf", 14);
		titleFont.drawString(settingsText, ofGetWidth() / 2 - 40, ofGetHeight() / 2 + 184);

		titleFont.load("Berka-Light.ttf", 50);

	}
	else if (gameScreen) {
		index = i;
		ofBackground(26,65,46);
		// Draw border of chalkboard
		ofSetColor(221,166,74);
		// Left and Right bar
		ofDrawRectangle(0,0,40,ofGetHeight() * 2);
		ofDrawRectangle(ofGetWidth(),0,40,ofGetHeight() * 2);
		// Top and bottom bar
		ofDrawRectangle(0,0,ofGetWidth() * 2,40);
		ofDrawRectangle(0,ofGetHeight(),ofGetWidth() * 2,40);

		ofSetColor(255, 250, 215);
		// Draw frame behind photo
		ofRectangle frame;
		frame.x = ofGetWidth() / 2;
		frame.y = ofGetHeight() / 2 - 170;
		frame.width = 420;
		frame.height = 280;
		ofDrawRectRounded(frame, 10);

		ofSetColor(255);
		// Draw image according to name using index
		image.load(location[index]);
		image.resize(400, 266);
		image.draw(ofGetWidth() / 2, ofGetHeight() / 2 - 170);
		

		//Set correct word
		correctWord = words[i];

		// Check if word that was attemtped is correct or not
		if (correctWord == attemptedWord) {
			correctSound.play();
			//Reset input 
			attemptedWord = "";
			//Draw checkmark beside word (based on number of letters)
			if (correctWord.length() == 3) {
				checkmark.draw(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 60);
			}
			else if (correctWord.length() == 4) {
				checkmark.draw(ofGetWidth() / 2 + 150, ofGetHeight() / 2 + 60);
			}
			else if (correctWord.length() == 5) {
				checkmark.draw(ofGetWidth() / 2 + 200, ofGetHeight() / 2 + 60);
			}
			score++;
			++i; // Move on to next picture
		}
		else if (attemptedWord.length() == correctWord.length() && attemptedWord != correctWord) {
			wrongSound.play();
			attemptedWord = "";
			//Draw xmark beside word (based on number of letters)
			if (correctWord.length() == 3) {
				xmark.draw(ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 60);
				tries++;
			}
			else if (correctWord.length() == 4) {
				xmark.draw(ofGetWidth() / 2 + 150, ofGetHeight() / 2 + 60);
				tries++;
			}
			else if (correctWord.length() == 5) {
				xmark.draw(ofGetWidth() / 2 + 200, ofGetHeight() / 2 + 60);
				tries++;
			}
		}

		// Draw squares for input
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofRectangle boxOne, boxTwo, boxThree, boxFour, boxFive;
		boxOne.width = boxTwo.width = boxThree.width = boxFour.width = boxFive.width = 40, boxOne.height = boxTwo.height = boxThree.height = boxFour.height = boxFive.height = 40;
		boxOne.y = boxTwo.y = boxThree.y = boxFour.y = boxFive.y = ofGetHeight() / 2 + 60;

		// Check number of letters in word;
		//For three letter words
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
		//For four letter words
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
		//For five letter words
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
			titleFont.drawString(words[index].substr(0, 1), ofGetWidth() / 2 - 200, ofGetHeight() / 2 + 200); // Real Letter
			titleFont.drawString(rand1, ofGetWidth() / 2 - 150, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(3, 1), ofGetWidth() / 2 - 100, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand2, ofGetWidth() / 2 - 50, ofGetHeight() / 2 + 200); // Fake letter
			titleFont.drawString(words[index].substr(2, 1), ofGetWidth() / 2 , ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand3, ofGetWidth() / 2 + 50, ofGetHeight() / 2 + 200); //Fake Letter
			titleFont.drawString(words[index].substr(1, 1), ofGetWidth() / 2 + 100, ofGetHeight() / 2 + 200); // Real letter
			titleFont.drawString(rand4, ofGetWidth() / 2 + 150, ofGetHeight() / 2 + 200); // Fake Leter
			titleFont.drawString(words[index].substr(4, 1), ofGetWidth() / 2 + 200, ofGetHeight() / 2 + 200); //Real letter
		}

		//Display each letter individually after each click
		if (correctWord.length() == 3) {
			if (attemptedWord.length() == 1) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 2) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 3) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
		}
		else if (correctWord.length() == 4) {
			if (attemptedWord.length() == 1) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 2) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 3) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 4) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(3, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
		}
		else if (correctWord.length() == 5) {
			if (attemptedWord.length() == 1) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 2) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 3) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 4) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(3, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
			else if (attemptedWord.length() == 5) {
				titleFont.load("Berka-Light.ttf", 30);
				ofSetColor(0);
				titleFont.drawString(attemptedWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(3, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
				titleFont.drawString(attemptedWord.substr(4, 1), ofGetWidth() / 2 + 90, ofGetHeight() / 2 + 65);
				ofSetColor(255);
				titleFont.load("Berka-Light.ttf", 50);
			}
		}
		
	}
	else if (displaySettScreen) {
	ofBackground(26, 65, 46);
	// Draw border of chalkboard
	ofSetColor(221, 166, 74);
	// Left and Right bar
	ofDrawRectangle(0, 0, 40, ofGetHeight() * 2);
	ofDrawRectangle(ofGetWidth(), 0, 40, ofGetHeight() * 2);
	// Top and bottom bar
	ofDrawRectangle(0, 0, ofGetWidth() * 2, 40);
	ofDrawRectangle(0, ofGetHeight(), ofGetWidth() * 2, 40);

	ofSetColor(255, 250, 215);
	
	// Settings menu
	titleFont.drawString("Press SPACE to turn sound ON/OFF", ofGetWidth() / 2 - 480, ofGetHeight() / 2);
	titleFont.load("Berka-Light.ttf", 30);
	titleFont.drawString("Press Q to exit settings", ofGetWidth() / 2 - 480, ofGetHeight() / 2 - 100);
	titleFont.load("Berka-Light.ttf", 50);
	// Disables/enables sound
	if (soundOn == true) {
		titleFont.drawString("Sound is currently: ON", ofGetWidth() / 2 - 480, ofGetHeight() / 2 - 50);
	}
	else {
		titleFont.drawString("Sound is currently: OFF", ofGetWidth() / 2 - 480, ofGetHeight() / 2 - 50);
	}
	
}
	else if (displayInstructScreen) {
	ofBackground(26, 65, 46);
	// Draw border of chalkboard
	ofSetColor(221, 166, 74);
	// Left and Right bar
	ofDrawRectangle(0, 0, 40, ofGetHeight() * 2);
	ofDrawRectangle(ofGetWidth(), 0, 40, ofGetHeight() * 2);
	// Top and bottom bar
	ofDrawRectangle(0, 0, ofGetWidth() * 2, 40);
	ofDrawRectangle(0, ofGetHeight(), ofGetWidth() * 2, 40);

	titleFont.load("Berka-Light.ttf", 35);
	ofSetColor(255);
	titleFont.drawString("Instructions:",45,55);
	titleFont.load("Berka-Light.ttf", 40);
	titleFont.drawString("1. Look at the picture\n2. Guess what the photo is\n3. Click on letters to spell word\n(Press Q to return to menu)",45,95);

	ofSetColor(255, 250, 215);
}	
	else if (finalScreen) {
		ofBackground(26, 65, 46);
		// Draw border of chalkboard
		ofSetColor(221, 166, 74);
		// Left and Right bar
		ofDrawRectangle(0, 0, 40, ofGetHeight() * 2);
		ofDrawRectangle(ofGetWidth(), 0, 40, ofGetHeight() * 2);
		// Top and bottom bar
		ofDrawRectangle(0, 0, ofGetWidth() * 2, 40);
		ofDrawRectangle(0, ofGetHeight(), ofGetWidth() * 2, 40);

		ofSetColor(255, 250, 215);
		titleFont.drawString("Your score is:", ofGetWidth() / 2 - 190, ofGetHeight() / 2);
		titleFont.drawString(to_string(score), ofGetWidth() / 2, ofGetHeight() / 2 + 50);
}
	// Check if failed three times
	if (tries == 10) {
		tries = 0;
		attemptedWord = "";
		//DISPLAY CORRECT WORD
		if (correctWord.length() == 3) {
			titleFont.load("Berka-Light.ttf", 30);
			ofSetColor(0);
			titleFont.drawString(correctWord.substr(0, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(1, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(2, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
			ofSetColor(255);
			titleFont.load("Berka-Light.ttf", 50);
		}
		else if (correctWord.length() == 4) {
			titleFont.load("Berka-Light.ttf", 30);
			ofSetColor(0);
			titleFont.drawString(correctWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(3, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
			ofSetColor(255);
			titleFont.load("Berka-Light.ttf", 50);
		} 
		else if (correctWord.length() == 5) {
			titleFont.load("Berka-Light.ttf", 30);
			ofSetColor(0);
			titleFont.drawString(correctWord.substr(0, 1), ofGetWidth() / 2 - 110, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(1, 1), ofGetWidth() / 2 - 60, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(2, 1), ofGetWidth() / 2 - 10, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(3, 1), ofGetWidth() / 2 + 40, ofGetHeight() / 2 + 65);
			titleFont.drawString(correctWord.substr(4, 1), ofGetWidth() / 2 + 90, ofGetHeight() / 2 + 65);
			ofSetColor(255);
			titleFont.load("Berka-Light.ttf", 50);
		}
		i++;
	}
	if (i == 10) {
		gameScreen = false;
		finalScreen = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (displaySettScreen) {
		if (key == ' ') {
			if (soundOn == true) {
				soundOn = false;
				wrongSound.setVolume(0.0);
				correctSound.setVolume(0.0);
			}
			else if (soundOn == false) {
				soundOn = true;
				wrongSound.setVolume(1.0);
				correctSound.setVolume(1.0);
			}
		}
		else if (key == 'q') {
			displaySettScreen = false;
			displayTitleScreen = true;
		}
	}
	else if (displayInstructScreen) {
		if (key == 'q') {
			displayInstructScreen = false;
			displayTitleScreen = true;
		}
	}
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
		if ((x >= (ofGetWidth() / 2 - 250) && x <= (ofGetWidth() / 2 - 50)) && (y >= (ofGetHeight() / 2 + 30) && y <= (ofGetHeight() / 2 + 130))) {
			displayTitleScreen = false;
			gameScreen = true;
		}
		else if ((x >= (ofGetWidth() / 2 + 50) && x <= (ofGetWidth() / 2 + 250)) && (y >= (ofGetHeight() / 2 + 30) && y <= (ofGetHeight() / 2 + 130))) {
			displayTitleScreen = false;
			displayInstructScreen = true;
		}
		else if ((x >= (ofGetWidth() / 2 - 200) && x <= (ofGetWidth() / 2 + 200)) && (y >= (ofGetHeight() / 2 + 160) && y <= (ofGetHeight() / 2 + 200))) {
			displayTitleScreen = false;
			displaySettScreen = true;
		}
	}
	else if (gameScreen) {
		if (correctWord.length() == 3) {
			if (y >= ofGetHeight() / 2 + 150 && y <= ofGetHeight() / 2 + 200) {
				if (x >= ofGetWidth() / 2 - 150 && x <= ofGetWidth() / 2  - 100) {
					attemptedWord += words[index].substr(1, 1);
				}
				else if (x >= ofGetWidth() / 2 - 100 && x <= ofGetWidth() / 2 - 50) {
					attemptedWord += rand1;
				}
				else if (x >= ofGetWidth() / 2 - 50 && x <= ofGetWidth() / 2) {
					attemptedWord += words[index].substr(0, 1);
				}
				else if (x >= ofGetWidth() / 2 && x <= ofGetWidth() / 2 + 50) {
					attemptedWord += rand2;
				}
				else if (x >= ofGetWidth() / 2 + 50 && x <= ofGetWidth() / 2 + 100) {
					attemptedWord += words[index].substr(2, 1);
				}
				else if (x >= ofGetWidth() / 2 + 100 && x <= ofGetWidth() / 2 + 150) {
					attemptedWord += rand3;
				}
			}
		}
		else if (correctWord.length() == 4) {
			if (y >= ofGetHeight() / 2 + 150 && y <= ofGetHeight() / 2 + 200) {
				if (x >= ofGetWidth() / 2 - 200 && x <= ofGetWidth() / 2 - 150) {
					attemptedWord += words[index].substr(1, 1);
				}
				else if (x >= ofGetWidth() / 2 - 150 && x <= ofGetWidth() / 2 - 100) {
					attemptedWord += rand1;
				}
				else if (x >= ofGetWidth() / 2 - 100 && x <= ofGetWidth() / 2 - 50) {
					attemptedWord += words[index].substr(0, 1);
				}
				else if (x >= ofGetWidth() / 2 - 50 && x <= ofGetWidth() / 2) {
					attemptedWord += rand2;
				}
				else if (x >= ofGetWidth() / 2 && x <= ofGetWidth() / 2 + 50) {
					attemptedWord += words[index].substr(3, 1);
				}
				else if (x >= ofGetWidth() / 2 + 50 && x <= ofGetWidth() / 2 + 100) {
					attemptedWord += rand3;
				}
				else if (x >= ofGetWidth() / 2 + 100 && x <= ofGetWidth() / 2 + 150) {
					attemptedWord += words[index].substr(2,1);
				} 
				else if (x >= ofGetWidth() / 2 + 150 && x <= ofGetWidth() / 2 + 200) {
					attemptedWord += rand4;
				}
			}
		}
		else if (correctWord.length() == 5) {
			if (y >= ofGetHeight() / 2 + 150 && y <= ofGetHeight() / 2 + 200) {
				if (x >= ofGetWidth() / 2 - 200 && x <= ofGetWidth() / 2 - 150) {
					attemptedWord += words[index].substr(0, 1);
				}
				else if (x >= ofGetWidth() / 2 - 150 && x <= ofGetWidth() / 2 - 100) {
					attemptedWord += rand1;
				}
				else if (x >= ofGetWidth() / 2 - 100 && x <= ofGetWidth() / 2 - 50) {
					attemptedWord += words[index].substr(3, 1);
				}
				else if (x >= ofGetWidth() / 2 - 50 && x <= ofGetWidth() / 2) {
					attemptedWord += rand2;
				}
				else if (x >= ofGetWidth() / 2 && x <= ofGetWidth() / 2 + 50) {
					attemptedWord += words[index].substr(2, 1);
				}
				else if (x >= ofGetWidth() / 2 + 50 && x <= ofGetWidth() / 2 + 100) {
					attemptedWord += rand3;
				}
				else if (x >= ofGetWidth() / 2 + 100 && x <= ofGetWidth() / 2 + 150) {
					attemptedWord += words[index].substr(1, 1);
				}
				else if (x >= ofGetWidth() / 2 + 150 && x <= ofGetWidth() / 2 + 200) {
					attemptedWord += rand4;
				}
				else if (x >= ofGetWidth() / 2 + 200 && x <= ofGetWidth() / 2 + 250) {
					attemptedWord += words[index].substr(4,1);
				}
			}
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

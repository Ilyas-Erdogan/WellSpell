#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	//Display variables
		bool displayTitleScreen{ true }, gameScreen{ false }, displayInstructScreen{ false }, displaySettScreen{ false };
	
	// Title Screen variable
	string titleText, overTitleText, startText, instructText, settingsText;
	ofTrueTypeFont titleFont, overTitleFont;

	//Game-related variables 
	std::string words[10]{ "cow","dog","car","sea", "bird", "tree", "bear", "panda", "apple", "watch" };
	std::string location[10]{ "cow_photo.jpg", "dog_photo.jpg","car_photo.jpg","sea_photo.jpg", "bird_photo.jpg", "tree_photo.jpg", "bear_photo.jpg", "panda_photo.jpg", "apple_photo.jpg", "watch_photo.jpg"};
	std::string status[2]{"checkmark.png", "xmark.png"};
	std::string sounds[10]{ "Cow-sound.wav", "Dog-sound.wav", "Car-sound.wav", "Sea-sound.wav", "Bird-sound.wav", "Tree-sound.wav", "Bear-sound.wav", "Panda-sound.wav", "Apple-sound.wav", "Watch-sound.wav" };
	int index{};
	bool active{ true };
	ofImage image, checkmark, xmark;
	std::string correctWord{ "" };
	std::string attemptedWord{ "" };
	int i{ 0 };
	int score{ 0 };
	int tries{ 0 };
	bool soundOn{ true };

	// Generates random letters for "extras"
	char const temp1 = 'a' + rand() % 26, const temp2 = 'a' + rand() % 26, const temp3 = 'a' + rand() % 26, const temp4 = 'a' + rand() % 26, const temp5 = 'a' + rand(), const temp6 = 'a' + rand() % 6;
	const std::string rand1{ temp1 }, rand2{ temp2 }, rand3{ temp3 }, rand4{ temp4 }, rand5{ temp5 }, rand6{ temp6 };
	
	ofSoundPlayer wrongSound, correctSound;
	ofSoundPlayer wordEnunc;
};

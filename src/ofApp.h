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
	bool displayTitleScreen{ true }, gameScreen{ true };
	
	// Title Screen variable
	string titleText, overTitleText, startText;
	ofTrueTypeFont titleFont, overTitleFont;

	//Game-related variables 
	std::string words[2]{ "cow","dog" };
	std::string location[2]{ "cow_photo.jpg", "dog_photo.jpg" };
	int index{};
	bool active{ true };
	ofImage image;
	std::string correctWord{ "" };
	// Generates random letters for "extras"
	char const temp1 = 'a' + rand() % 26, const temp2 = 'a' + rand() % 26, const temp3 = 'a' + rand() % 26, const temp4 = 'a' + rand() % 26, const temp5 = 'a' + rand(), const temp6 = 'a' + rand() % 6;
	const std::string rand1{ temp1 }, rand2{ temp2 }, rand3{ temp3 }, rand4{ temp4 }, rand5{ temp5 }, rand6{ temp6 };
};

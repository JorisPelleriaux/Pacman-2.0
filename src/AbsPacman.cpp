#include "AbsPacman.h"
#include "AbstractFactory.h"
#include <iostream>

using namespace std;

//Constructor sets required parameters
AbsPacman::AbsPacman(AbstractFactory* factory, int lives, int x, int y,
		int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	inputHandler = factory->GetInputhandler();
	this->lives = lives;
	this->box.left = x;
	this->box.top = y;
	this->movespeed = movespeed;

}

AbsPacman::~AbsPacman() {
}

/*void AbsPacman::Move(RECT box) {

 //Define how pacman should move
 }*/

//Handle the input
void AbsPacman::handleEvent(InputType dir) {
	//Adjust the velocity
	switch (dir) {
	case UUp:
		YVEL += PAC_VEL;
		break;
	case UDown:
		YVEL -= PAC_VEL;
		break;
	case ULeft:
		XVEL += PAC_VEL;
		break;
	case URight:
		XVEL -= PAC_VEL;
		break;
	case DUp:
		YVEL -= PAC_VEL;
		sAngle = 270;
		break;
	case DDown:
		YVEL += PAC_VEL;
		sAngle = 90;
		break;
	case DLeft:
		XVEL -= PAC_VEL;
		sAngle = 180;
		break;
	case DRight:
		XVEL += PAC_VEL;
		sAngle = 0;
		break;
	default:
		return;
	}
}
int AbsPacman::GetLives() {
	return lives;
}

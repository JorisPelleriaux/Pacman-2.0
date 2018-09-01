#include "AbsPacman.h"
#include "AbstractFactory.h"
#include <iostream>

using namespace std;

//Constructor sets required parameters
AbsPacman::AbsPacman(AbstractFactory* factory, Context* context, int lives,
		int x, int y, int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	inputHandler = factory->GetInputhandler();
	this->lives = lives;
	this->Pbox.left = x;
	this->Pbox.top = y;
	this->Pbox.right = x + 30;
	this->Pbox.bottom = y + 30;
	this->movespeed = movespeed;
	this->context = context;

}

AbsPacman::~AbsPacman() {
}

/*void AbsPacman::Move(RECT box) {
 //Define how pacman should move

 Pbox.left += XVEL;	//Move the Pacman left or right

 //If the Pac touched a wall
 if (context->touchesWall(Pbox)) {
 //move back
 //cout<<"wall"<<endl;
 Pbox.left -= XVEL;	//Stop
 }

 Pbox.top += YVEL;	//Move the Pacman up or down
 if (context->touchesWall(Pbox)) {
 Pbox.top -= YVEL;
 }

 }
*/
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

bool AbsPacman::CheckCollision() {
	for (int i = 0; i < 4; i++) {
		if (context->checkcollision(context->Ghosts[i], Pbox)) {
			return true;
			break;
		}
	}
	return false;
}

int AbsPacman::GetLives() {
	return lives;
}
int AbsPacman::GetScore() {
	return score;
}
void AbsPacman::TakeLive() {
	lives -= 1;
}

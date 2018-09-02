#include "AbsPacman.h"
#include "AbstractFactory.h"
#include <iostream>

namespace PACMAN {
//Constructor sets required parameters
AbsPacman::AbsPacman(AbstractFactory* factory, Context* context, int lives,
		int x, int y, int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	inputHandler = factory->GetInputhandler();
	this->lives = lives;

	this->mBox.left = this->x = x;
	this->mBox.top = this->y =  y;
	this->mBox.right = x + PAC_WIDTH;
	this->mBox.bottom = y + PAC_HEIGHT;
	this->movespeed = movespeed;
	this->context = context;

}

AbsPacman::~AbsPacman() {
}

void AbsPacman::move() {
	mBox.left += xVel;	//Move the Pacman left or right
	mBox.right = mBox.left + PAC_WIDTH;

	//pass right exit
	if (mBox.left + PAC_WIDTH > context->sWidth) {
		mBox.left = 0;
	}
	//pass left exit
	if (mBox.left < 0) {
		mBox.left = context->sWidth - PAC_WIDTH;
	}
	//If the Pac touched a wall
	if (context->touchesWall(mBox, true)) {
		mBox.left -= xVel;	//Stop
	}

	mBox.top += yVel;	//Move the Pacman up or down
	mBox.bottom = mBox.top + PAC_HEIGHT;
	//If the Pac went too far up or down or touched a wall
	if ((mBox.top < 0) || (mBox.top + PAC_HEIGHT > context->sHeight)
			|| context->touchesWall(mBox, true)) {
		mBox.top -= yVel;	//Stop
	}
}

//Handle the input
void AbsPacman::handleEvent(InputType dir) {
	//Adjust the velocity
	switch (dir) {
	case UUp:
		yVel += PAC_VEL;
		break;
	case UDown:
		yVel -= PAC_VEL;
		break;
	case ULeft:
		xVel += PAC_VEL;
		break;
	case URight:
		xVel -= PAC_VEL;
		break;
	case DUp:
		yVel -= PAC_VEL;
		sAngle = 270;
		break;
	case DDown:
		yVel += PAC_VEL;
		sAngle = 90;
		break;
	case DLeft:
		xVel -= PAC_VEL;
		sAngle = 180;
		break;
	case DRight:
		xVel += PAC_VEL;
		sAngle = 0;
		break;
	default:
		return;
	}
}
void AbsPacman::setStartPosition() {
	mBox.left = x;
	mBox.top = y;
	xVel = yVel = sAngle = 0;
}

bool AbsPacman::checkCollision() {
	for (int i = 0; i < 4; i++) {
		if (context->checkcollision(context->ghosts[i], mBox)) {
			return true;
			break;
		}
	}
	return false;
}

int AbsPacman::getLives() {
	return lives;
}
int AbsPacman::getScore() {
	return score;
}
int AbsPacman::getAngle(){
	return sAngle;
}
void AbsPacman::takeLive() {
	lives -= 1;
}
RECT AbsPacman::getBox(){
	return mBox;
}
}

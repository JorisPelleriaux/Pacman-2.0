/*
 * AbsPacman.cpp
 *
 *  Created on: 5 mrt. 2018
 *      Author: joris
 */

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
	this->x = x;
	this->y = y;
	this->movespeed = movespeed;
	this->mVelX = 0;
	this->mVelY = 0;
}

AbsPacman::~AbsPacman() {

}

void AbsPacman::Update() {

}

void AbsPacman::Move(InputType dir) {

	mVelX = 0;
	mVelY = 0;
	switch (dir) {
	case Left:
		mVelX -= PAC_VEL;
		break;
	case Right:
		mVelX += PAC_VEL;
		break;
	case Up:
		mVelY -= PAC_VEL;
		break;
	case Down:
		mVelY += PAC_VEL;
		break;
	default:
		return;
	}

	//Move the dot left or right
	x += mVelX;

	//Move the dot up or down
	y += mVelY;

}

int AbsPacman::GetLives() {
	return lives;
}

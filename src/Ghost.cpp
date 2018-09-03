#include "Ghost.h"
#include "AbstractFactory.h"
#include <iostream>

namespace PACMAN {

Ghost::Ghost(AbstractFactory* factory, Context* context, int x, int y,
		int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	mBox.left = x;
	mBox.top = y;
	mBox.right = mBox.left + GHOST_WIDTH;
	mBox.bottom = mBox.top + GHOST_HEIGHT;
	ghost_VEL = movespeed;
	this->context = context;
}
Ghost::~Ghost() {
}

void Ghost::defaultPosition(int Ghost) {
	mBox.left = 300 - (Ghost * 40);
	mBox.top = 245 + (4 * Ghost);
	mBox.right = mBox.left + GHOST_WIDTH;
	mBox.bottom = mBox.top + GHOST_HEIGHT;
}

void Ghost::move() {
	//Update the right and bottom value of the collision box
	mBox.right = mBox.left + GHOST_WIDTH;
	mBox.bottom = mBox.top + GHOST_HEIGHT;

	//Pass the current position of the ghost to the pacman
	context->ghosts[context->currGhost].left = mBox.left;
	context->ghosts[context->currGhost].top = mBox.top;
	context->ghosts[context->currGhost].right = mBox.left + GHOST_WIDTH;
	context->ghosts[context->currGhost].bottom = mBox.top + GHOST_HEIGHT;

	tempPosX[context->currGhost] = mBox.left;
	tempPosY[context->currGhost] = mBox.top;

	switch (num[context->currGhost]) {
	case 0:
		mBox.left += ghost_VEL;
		break;
	case 1:
		mBox.left -= ghost_VEL;
		break;
	case 2:
		mBox.top += ghost_VEL;
		break;
	case 3:
		mBox.top -= ghost_VEL;
		break;
	}

	if (context->touchesWall(mBox, false) || (mBox.top <= 0) || (mBox.left < 0)
			|| (mBox.top + GHOST_HEIGHT > context->sHeight)
			|| (mBox.left + GHOST_WIDTH > context->sWidth)) {
		mBox.left = tempPosX[context->currGhost];
		mBox.top = tempPosY[context->currGhost];
		switch (num[context->currGhost]) {
		case 0:
			mBox.left -= ghost_VEL;
			break;
		case 1:
			mBox.left += ghost_VEL;
			break;
		case 2:
			mBox.top -= ghost_VEL;
			break;
		case 3:
			mBox.top += ghost_VEL;
			break;
		}
		num[context->currGhost] = rand() % 4;
	} else {
		prevNum[context->currGhost] = num[context->currGhost];
	}

	context->currGhost++;

	if (context->currGhost == 4) {
		context->currGhost = 0;
	}
}

RECT Ghost::getBox() {
	return (mBox);
}

void Ghost::startMove() {
	//Update the right and bottom value of the collision box
	mBox.right = mBox.left + GHOST_WIDTH;
	mBox.bottom = mBox.top + GHOST_HEIGHT;

	//Pass the current position of the ghost to the pacman
	context->ghosts[context->currGhost].left = mBox.left;
	context->ghosts[context->currGhost].top = mBox.top;
	context->ghosts[context->currGhost].right = mBox.left + GHOST_WIDTH;
	context->ghosts[context->currGhost].bottom = mBox.top + GHOST_HEIGHT;

	if (mBox.left < (context->sWidth / 2) - (GHOST_WIDTH / 2)) {//Ghost left from center -> move right
		mBox.left += ghost_VEL;
	}
	if (mBox.left > (context->sWidth / 2) - (GHOST_WIDTH / 2)) {//Ghost right from center -> move left
		mBox.left -= ghost_VEL;
	}
	if (context->touchesWall(mBox, false)) {	//Ghosts left <=> right
		mBox.top += ghost_VEL;
		num[0] = num[2] = 0;
		num[1] = num[3] = 1;
		start = true;
	}
	if (start == false
			&& mBox.left == ((context->sWidth / 2) - (GHOST_WIDTH / 2)) - 1) {//Ghost in center position -> move up
		mBox.top -= ghost_VEL;
	}

	context->currGhost++;

	if (context->currGhost == 4) {
		context->currGhost = 0;
	}
}
}

#include "Ghost.h"
#include "AbstractFactory.h"
#include <iostream>

using namespace std;

namespace PACMAN {
//Constructor sets required parameters
Ghost::Ghost(AbstractFactory* factory, Context* context, int x, int y,
		int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	this->Box.left = x;
	this->Box.top = y;
	this->Box.right = Box.left + Ghost_WIDTH;
	this->Box.bottom = Box.top + Ghost_HEIGHT;
	this->Ghost_VEL = movespeed;
	this->context = context;
}
Ghost::~Ghost() {
}

void Ghost::Default(int Ghost) {
	Box.left = 300 - (Ghost * 40);
	this->Box.top = 245 + (4 * Ghost);
	this->Box.right = Box.left + Ghost_WIDTH;
	this->Box.bottom = Box.top + Ghost_HEIGHT;
}

void Ghost::Move() {
	//Update the right and bottom value of the collision box
	Box.right = Box.left + Ghost_WIDTH;
	Box.bottom = Box.top + Ghost_HEIGHT;

	//Pass the current position of the ghost to the pacman
	context->Ghosts[context->CurrGhost].left = Box.left;
	context->Ghosts[context->CurrGhost].top = Box.top;
	context->Ghosts[context->CurrGhost].right = Box.left + Ghost_WIDTH;
	context->Ghosts[context->CurrGhost].bottom = Box.top + Ghost_HEIGHT;

//Define how the ghost should move
	tempPosX[context->CurrGhost] = Box.left;
	tempPosY[context->CurrGhost] = Box.top;

	switch (Num[context->CurrGhost]) {
	case 0:
		Box.left += Ghost_VEL;
		break;
	case 1:
		Box.left -= Ghost_VEL;
		break;
	case 2:
		Box.top += Ghost_VEL;
		break;
	case 3:
		Box.top -= Ghost_VEL;
		break;
	}

	if (context->touchesWall(Box) || (Box.top <= 0) || (Box.left < 0)
			|| (Box.top + Ghost_HEIGHT > 665)
			|| (Box.left + Ghost_WIDTH > 525)) {
		Box.left = tempPosX[context->CurrGhost];
		Box.top = tempPosY[context->CurrGhost];
		switch (Num[context->CurrGhost]) {
		case 0:
			Box.left -= Ghost_VEL;
			break;
		case 1:
			Box.left += Ghost_VEL;
			break;
		case 2:
			Box.top -= Ghost_VEL;
			break;
		case 3:
			Box.top += Ghost_VEL;
			break;
		}
		Num[context->CurrGhost] = rand() % 4;
	} else {
		PrevNum[context->CurrGhost] = Num[context->CurrGhost];
	}

	//Ready for next ghost
	context->CurrGhost++;

	//All ghosts done -> first ghost
	if (context->CurrGhost == 4) {
		context->CurrGhost = 0;
	}
}

void Ghost::StartMove(int Ghost) {
	//Update the right and bottom value of the collision box
	Box.right = Box.left + Ghost_WIDTH;
	Box.bottom = Box.top + Ghost_HEIGHT;

	//Pass the current position of the ghost to the pacman
	context->Ghosts[context->CurrGhost].left = Box.left;
	context->Ghosts[context->CurrGhost].top = Box.top;
	context->Ghosts[context->CurrGhost].right = Box.left + Ghost_WIDTH;
	context->Ghosts[context->CurrGhost].bottom = Box.top + Ghost_HEIGHT;

	if (Box.left < (525 / 2) - (Ghost_WIDTH / 2)) {	//Ghost left from center -> move right
		Box.left += Ghost_VEL;
	}
	if (Box.left > (525 / 2) - (Ghost_WIDTH / 2)) {	//Ghost right from center -> move left
		Box.left -= Ghost_VEL;
	}
	if (context->touchesWall(Box)) {	//Ghosts left <=> right
		Box.top += Ghost_VEL;
		Num[0] = Num[2] = 0;
		Num[1] = Num[3] = 1;
		Start = true;
	}
	if (Start == false && Box.left == ((525 / 2) - (Ghost_WIDTH / 2)) - 1) {//Ghost in center position -> move up
		Box.top -= Ghost_VEL;
	}
	//Ready for next ghost
	context->CurrGhost++;

	//All ghosts done -> first ghost
	if (context->CurrGhost == 4) {
		context->CurrGhost = 0;
	}

}
}

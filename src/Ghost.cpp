#include "Ghost.h"
#include "AbstractFactory.h"
#include <iostream>

using namespace std;

//Constructor sets required parameters
Ghost::Ghost(AbstractFactory* factory, Context* context, int x, int y,
		int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	this->Box.left = x;
	this->Box.top = y;
	this->Box.right = Box.left + Ghost_WIDTH;
	this->Box.bottom = Box.top + Ghost_HEIGHT;
	this->Ghost_VEL = 2;
	this->context = context;
	this->XVEL = 2;
	this->YVEL = 0;

}
Ghost::~Ghost() {
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

	//Ready for next ghost
	context->CurrGhost++;

	//All ghosts done -> first ghost
	if (context->CurrGhost == 4) {
		context->CurrGhost = 0;
	}

//Define how the ghost should move
	int tempPosX = Box.left;
	int tempPosY = Box.top;

	if (counter >= 10) {
		counter = 0;
		Num = rand() % 4;
	}
	counter++;

	switch (Num) {
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

	if (context->touchesWall(Box)) {
		Box.left = tempPosX;
		Box.top = tempPosY;
		cout << "Wall" << endl;
		switch (PrevNum) {
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
		if (context->touchesWall(Box)) {
			Box.left = tempPosX;
			Box.top = tempPosY;
			Num = rand() % (4) + 1; //if stuck, change direction
		}
	} else {
		PrevNum = Num;
	}
}

#include "Ghost.h"
#include "AbstractFactory.h"

#include <iostream>

using namespace std;

//Constructor sets required parameters
Ghost::Ghost(AbstractFactory* factory, int x, int y, int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	this->Box.left = x;
	this->Box.top = y;
	this->Box.right = x + Ghost_WIDTH;
	this->Box.bottom = y + Ghost_HEIGHT;
	this->Ghost_VEL = movespeed;

}
Ghost::~Ghost() {
}

/*void Ghost::Move() {
//Define how the ghost should move
}*/

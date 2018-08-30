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
void handleEvent(InputType dir){
//Handle the input
}
int AbsPacman::GetLives() {
	return lives;
}

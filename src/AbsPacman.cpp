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

}

AbsPacman::~AbsPacman() {

}

void AbsPacman::Update() {

}

void AbsPacman::Move() {



}
void handleEvent(InputType dir){

}
int AbsPacman::GetLives() {
	return lives;
}

/*
 * Ghost.cpp
 *
 *  Created on: 29 aug. 2018
 *      Author: joris
 */

#include "Ghost.h"
#include "AbstractFactory.h"

#include <iostream>

using namespace std;

//Constructor sets required parameters
Ghost::Ghost(AbstractFactory* factory, int x, int y, int movespeed) : Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	this->x = x;
	this->y = y;
	this->movespeed = movespeed;

}
Ghost::~Ghost() {

}

void Ghost::Update() {

}

void Ghost::Move() {



}
int Ghost::GetLives() {
	return 0;
}

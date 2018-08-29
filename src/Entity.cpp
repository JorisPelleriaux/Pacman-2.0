/*
 * Entity.cpp
 *
 *  Created on: 5 mrt. 2018
 *      Author: joris
 */

#include <iostream>
#include "Entity.h"
using namespace std;

//Constructor sets required parameters
Entity::Entity(int x, int y, int width, int height, int movespeed) {
	this->movespeed = movespeed;

}

Entity::~Entity() {

}
void Entity::Move(){

}


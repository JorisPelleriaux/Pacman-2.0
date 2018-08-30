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
rect.left = 20;
}

Entity::~Entity() {

}
void Entity::Move(RECT box){

}

bool Entity::CheckCollisions(RECT a, RECT b){

	return false;
}

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

//Moves entity depending on input
void Entity::Move() {
	/*switch (dir) {
	case Left:
		cout << "links"  << endl;
		break;
	case Right:
		cout << "rechts"  << endl;
		break;
	case Up:
		cout << "boven"  << endl;
		break;
	case Down:
		cout << "onder"  << endl;
		break;
	default:
		return;
	}*/
}

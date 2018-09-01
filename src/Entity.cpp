#include <iostream>
#include "Entity.h"
using namespace std;

namespace PACMAN {
//Constructor sets required parameters
Entity::Entity(int x, int y, int width, int height, int movespeed) {
	this->movespeed = movespeed;
	rect.left = 20;
}

Entity::~Entity() {

}
}

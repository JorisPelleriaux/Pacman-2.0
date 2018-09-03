#include <iostream>
#include "Entity.h"
using namespace std;

namespace PACMAN {

Entity::Entity(int x, int y, int width, int height, int movespeed) {
	this->movespeed = movespeed;
}
Entity::~Entity() {
}
}

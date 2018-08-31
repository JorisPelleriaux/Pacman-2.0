#include <iostream>
#include "Context.h"
using namespace std;
Context::Context() {

}

Context::~Context() {

}

bool Context::touchesWall(RECT box) {
	//Go through the tiles
	for (int i = 0; i < 285; ++i) {
		//If the tile is a wall type tile
		if ((tileSet[i]->getType() < 15) //TODO tile path dynamic
		&& (tileSet[i]->getType() >= 0)) {
			//If the collision box touches the wall tile
			if (checkcollision(box, tileSet[i]->getBox())) {
				return true;
			}
		}
	}

	//If no wall tiles were touched
	return false;
}

bool Context::checkcollision(RECT a, RECT b) {

	//If any of the sides from A are outside of B
	if (a.bottom <= b.top) {
		return false;
	}

	if (a.top >= b.bottom) {
		return false;
	}

	if (a.right <= b.left) {
		return false;
	}

	if (a.left >= b.right) {
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

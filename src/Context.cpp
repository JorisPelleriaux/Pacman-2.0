#include <iostream>
#include "Context.h"
using namespace std;

namespace PACMAN {
Context::Context() {
}
Context::~Context() {

}

bool Context::touchesWall(RECT box, bool pacman) {
	//Go through the tiles
	for (int i = 0; i < 285; ++i) {
		//If the tile is food
		if (tileSet[i]->getType() > 14) { //14: path tile
			if (checkcollision(box, tileSet[i]->getBox()) && pacman) {
				tileSet[i]->setType(14);
				this->score += 5;	//add 5 to the score
			}
		}

		//If the tile is a wall type tile
		if ((tileSet[i]->getType() < 14) && (tileSet[i]->getType() >= 0)) {
			if (checkcollision(box, tileSet[i]->getBox())) {
				return true;
			}
		}
	}
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
}

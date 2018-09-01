#include <iostream>
#include "Context.h"
using namespace std;

namespace PACMAN {
Context::Context() {
	//Current Ghost
	CurrGhost = 0;
}

Context::~Context() {

}

bool Context::touchesWall(RECT box) {
	//Go through the tiles
	for (int i = 0; i < 285; ++i) {
		//If the tile is a wall type tile
		if ((tileSet[i]->getType() < 15) && (tileSet[i]->getType() >= 0)) {
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

	//check where the hit was
	/*if (a.bottom >= b.top && a.bottom <= b.bottom) {
	 if (a.left <= b.right && a.left >= b.left) {
	 cout << "links geraakt" << endl;
	 }
	 if (a.right >= b.left && a.right >= b.right) {
	 cout << "Rechts geraakt" << endl;
	 }
	 }
	 if (a.left <= b.right && a.left >= b.left) {
	 if (a.bottom >= b.top && a.bottom <= b.bottom) {
	 cout << "onder geraakt" << endl;
	 }
	 if (a.top >= b.top && a.top <= b.bottom) {
	 cout << "boven geraakt" << endl;
	 }
	 }*/

	//If none of the sides from A are outside B
	return true;
}
}

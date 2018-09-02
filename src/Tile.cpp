#include <iostream>
#include "Tile.h"

using namespace std;

namespace PACMAN_SDL {
class SDLBackground;
Tile::Tile(int x, int y, int tileType) :
		AbsTile(x, y, tileType) {

	//Get the tile type
	mType = tileType;
}

int Tile::getType() {
	return mType;
}

void Tile::setType(int type) {
	mType = type;
}
}

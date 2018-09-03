#include "Tile.h"

namespace PACMAN_SDL {
class SDLBackground;
Tile::Tile(int x, int y, int tileType) :
		AbsTile(x, y, tileType) {

	mType = tileType;
}

int Tile::getType() {
	return mType;
}

void Tile::setType(int type) {
	mType = type;
}
}

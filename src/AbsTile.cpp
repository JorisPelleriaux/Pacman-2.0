#include <iostream>
#include "AbsTile.h"

namespace PACMAN {
AbsTile::AbsTile(int x, int y, int tileType) {
	mType = tileType;
	mBox.left = x;
	mBox.top = y;
	mBox.right = x + TILE_WIDTH;
	mBox.bottom = y + TILE_HEIGHT;
}
int AbsTile::getType() {
	return mType;
}

void AbsTile::setType(int type) {
	mType = type;
}

RECT AbsTile::getBox() {
	return mBox;
}
}

/*
 * AbsTile.cpp
 *
 *  Created on: 30 aug. 2018
 *      Author: joris
 */
#include <iostream>
#include "AbsTile.h"

using namespace std;

AbsTile::AbsTile(int x, int y, int tileType) {
	mType = tileType;
	mBox.left = x;
	mBox.top = y;
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

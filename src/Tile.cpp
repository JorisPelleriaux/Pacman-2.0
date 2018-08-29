/*
 * Tile.cpp
 *
 *  Created on: 28 aug. 2018
 *      Author: joris
 */

#include <iostream>
#include "Tile.h"

class SDLBackground;
using namespace std;

Tile::Tile(int x, int y, int tileType) {
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = TILE_WIDTH;
	mBox.h = TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}

void Tile::render(SDLContext* context, SDL_Texture* image) {
//TODO check collision

//Show the tile
	context->Draw(mBox.x, mBox.y, image, &context->gTileClips[mType] ,0.0);
}


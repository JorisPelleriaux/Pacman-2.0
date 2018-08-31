#include <iostream>
#include "Tile.h"

class SDLBackground;
using namespace std;

Tile::Tile(int x, int y, int tileType) : AbsTile(x,  y, tileType) {
	//Get the offsets
	mBox.x = x;
	mBox.y = y;

	//Set the collision box
	mBox.w = this->TILE_WIDTH;
	mBox.h = this->TILE_HEIGHT;

	//Get the tile type
	mType = tileType;
}

int Tile::getType(){
	return mType;
}

void Tile::setType(int type){
	mType = type;
}

SDL_Rect Tile::getBox(){
	return mBox;
}


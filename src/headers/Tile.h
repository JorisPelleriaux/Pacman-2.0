/*
 * Tile.h
 *
 *  Created on: 28 aug. 2018
 *      Author: joris
 */
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "SDLContext.h"
#include "AbsTile.h"
#ifndef HEADERS_TILE_H_
#define HEADERS_TILE_H_

class Tile : public AbsTile {
public:

	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Shows the tile
	void render(SDLContext* context, SDL_Texture* image);

	//Get the tile type
	int getType();

	//Set the tile type
	void setType(int type);

	//Get the collision box
	SDL_Rect getBox();


	//Scene textures
	/*SDLContext gDotTexture;
	 SDLContext gTileTexture;
	 SDL_Rect gTileClips[ 12 ];*/

private:
	//The attributes of the tile
	SDL_Rect mBox;

	//The tile type
	int mType;

};
#endif /* HEADERS_TILE_H_ */

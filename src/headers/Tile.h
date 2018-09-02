#ifndef HEADERS_TILE_H_
#define HEADERS_TILE_H_
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "SDLContext.h"
#include "AbsTile.h"

using namespace PACMAN;

namespace PACMAN_SDL {
class Tile: public AbsTile {
public:
	//Initializes position and type
	Tile(int x, int y, int tileType);

	//Get the tile type
	int getType();

	//Set the tile type
	void setType(int type);

private:
	//The tile type
	int mType = 0;
};
}
#endif /* HEADERS_TILE_H_ */

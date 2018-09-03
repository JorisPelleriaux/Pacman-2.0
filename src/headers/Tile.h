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
	Tile(int x, int y, int tileType);

	int getType();
	void setType(int type);

private:
	int mType = 0;
};
}
#endif /* HEADERS_TILE_H_ */

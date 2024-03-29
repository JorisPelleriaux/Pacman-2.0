#ifndef SDLBACKGROUND_H_
#define SDLBACKGROUND_H_
#include "Background.h"
#include "SDLContext.h"

using namespace PACMAN;

namespace PACMAN_SDL {
class SDLBackground: public Background {
public:
	SDLBackground(SDLContext* context);
	~SDLBackground();
	void visualise(int State) override;
	void startScreen() override;
	bool setTiles();

private:
	const int TILE_WIDTH = 35;
	const int TILE_HEIGHT = 35;
	const int TOTAL_TILES = 285;
	static const int TOTAL_TILE_SPRITES = 18;

	//Scene texture
	SDL_Texture* image;
	SDLContext* context;
	SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

	//The different tile sprites
	const int TILE_HORIZONTAL = 0;
	const int TILE_LEFT = 1;
	const int TILE_RIGHT = 2;
	const int TILE_TOPRIGHT = 3;
	const int TILE_CENTERDOWN = 4;
	const int TILE_TOPLEFT = 5;
	const int TILE_TOP = 6;
	const int TILE_BOTTOMRIGHT = 7;
	const int TILE_CENTERUP = 8;
	const int TILE_BOTTOMLEFT = 9;
	const int TILE_VERTICAL = 10;
	const int TILE_BOTTOM = 11;
	const int TILE_CENTERLEFT = 12;
	const int TILE_CENTERRIGHT = 13;//14
	const int TILE_PATH = 14;//15
	const int TILE_FOOD1 = 15;//16
	const int TILE_FOOD2 = 16;//17
	const int TILE_FOOD3 = 17;//13
};
}
#endif /* SDLBACKGROUND_H_ */

#ifndef SDLBACKGROUND_H_
#define SDLBACKGROUND_H_
#include "Background.h"
#include "SDLContext.h"
class Tile;
using namespace PACMAN;

namespace PACMAN_SDL {
class SDLBackground: public Background {
public:
	SDLBackground(SDLContext* context);
	~SDLBackground();
	void Visualise(int State) override;
	void Move() override;
	void StartScreen() override;
	bool SetTiles();
	void Close();
	SDLContext* GetContext();

protected:
	//Tile constants
	const int TILE_WIDTH = 35;
	const int TILE_HEIGHT = 35;

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
	const int TILE_CENTER = 13;
	const int TILE_CENTERRIGHT = 14;
	const int TILE_PATH = 15;
	const int TILE_FOOD1 = 16;
	const int TILE_FOOD2 = 17;

protected:

private:

	SDL_Texture* image;
	SDLContext* context;

};
}
#endif /* SDLBACKGROUND_H_ */

#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <iostream>
#include "SDLWindow.h"
#include "Context.h"
using namespace std;
class Tile;
class SDLWindow;
class SDLContext: public Context {
public:
	//Initializes variables
	SDLContext(SDLWindow* window);

	//Deallocates memory
	~SDLContext();

	//Loads image at specified path
	SDL_Texture* loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void Draw(int x, int y, SDL_Texture* texture, SDL_Rect* clip, double angle);

	void CreatePacSprites();

	void CreateGhostSprites(int number);

	void ClearScreen();

	void UpdateScreen();

	bool touchesWall(SDL_Rect box, Tile* tiles[], bool pacman);

	bool checkCollision(SDL_Rect a, SDL_Rect b);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//Tile constants
	static const int TOTAL_TILES = 285;
	static const int TOTAL_TILE_SPRITES = 18;

	SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

	//Walking animation Pacman
	const int ANIMATION_FRAMES = 4;
	SDL_Rect gSpriteClips[4];

	//Walking animation Ghost
	const int ANIMATION_FRAMES_Ghost = 2;
	SDL_Rect gSpriteClips_Ghost[2];

	//The level tiles
	Tile* tileSet[TOTAL_TILES];

	//Screen dimensions
	int sWidth;
	int sHeight;

protected:

private:
	//The window
	SDLWindow* window;

	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	//Current animation frame
	int frame;
};

#endif /* SDLCONTEXT_H_ */

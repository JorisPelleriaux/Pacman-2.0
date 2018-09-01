#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <iostream>
#include "SDLWindow.h"
#include "Context.h"
using namespace PACMAN;

namespace PACMAN_SDL {
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

	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor,
			int size);

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void Draw(int x, int y, SDL_Texture* texture = NULL, SDL_Rect* clip = NULL,
			double angle = 0.0);

	void CreatePacSprites();

	void CreateGhostSprites(int number);

	void ClearScreen();

	void UpdateScreen();

	bool touchesWall(SDL_Rect box, AbsTile* tiles[], bool pacman);

	bool checkCollision(SDL_Rect a, RECT b);

	//Tile constants
	static const int TOTAL_TILES = 285;
	static const int TOTAL_TILE_SPRITES = 18;

	//Type tiles
	SDL_Rect gTileClips[TOTAL_TILE_SPRITES];

	//Walking animation Pacman
	int ANIMATION_FRAMES = 4;
	SDL_Rect gSpriteClips[16];

	//Walking animation Ghost
	const int ANIMATION_FRAMES_Ghost = 2;
	SDL_Rect gSpriteClips_Ghost[4][2];	//MAX 4 ghosts with 2 sprites

	//Screen dimensions
	int sWidth, sHeight;

	//Text dimensions
	int tWidth, tHeight;

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//The actual hardware texture
	SDL_Texture* mTexture;

protected:

private:
	//The window
	SDLWindow* window;

	//Image dimensions
	int mWidth;
	int mHeight;

	//Current animation frame
	int frame;
};
}
#endif /* SDLCONTEXT_H_ */

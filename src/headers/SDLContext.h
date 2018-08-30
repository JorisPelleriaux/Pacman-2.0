#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_

#include <iostream>
#include "SDLWindow.h"
#include "Context.h"
using namespace std;
class Tile;
class SDLWindow;
class SDLContext : public Context {
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

	int touchesWall(SDL_Rect box, Tile* tiles[]);

	bool checkCollision(SDL_Rect a, SDL_Rect b);

	//Gets image dimensions
	int getWidth();
	int getHeight();
	SDL_Rect gTileClips[16];

	//Walking animation Pacman
	const int ANIMATION_FRAMES = 4;
	SDL_Rect gSpriteClips[4];

	//Walking animation Ghost
	const int ANIMATION_FRAMES_Ghost = 2;
	SDL_Rect gSpriteClips_Ghost[2];

	//The level tiles
	Tile* tileSet[285];

protected:

private:
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

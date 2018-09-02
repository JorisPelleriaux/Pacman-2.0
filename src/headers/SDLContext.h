#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_
#include "SDLWindow.h"
#include "Context.h"
using namespace PACMAN;

namespace PACMAN_SDL {
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
	void draw(int x, int y, SDL_Texture* texture = nullptr, SDL_Rect* clip = nullptr,
			double angle = 0.0);

	void createPacSprites();
	void createGhostSprites(int number);
	void clearScreen();
	void updateScreen();

	//Spriteclips pacman
	SDL_Rect gSpriteClips[16];

	//Spriteclips ghosts
	SDL_Rect gSpriteClips_Ghost[4][2];	//MAX 4 ghosts with 2 sprites

	//Gets image dimensions
	int getWidth();
	int getHeight();

	//The actual hardware texture
	SDL_Texture* mTexture;

private:
	//The window
	SDLWindow* window;

	//Image dimensions
	int mWidth;
	int mHeight;
};
}
#endif /* SDLCONTEXT_H_ */

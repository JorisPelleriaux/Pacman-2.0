#ifndef SDLCONTEXT_H_
#define SDLCONTEXT_H_
#include "SDLWindow.h"
#include "Context.h"
using namespace PACMAN;

namespace PACMAN_SDL {
class SDLWindow;
class SDLContext: public Context {
public:
	SDLContext(SDLWindow* window);
	~SDLContext();

	SDL_Texture* loadFromFile(std::string path);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor,
			int size);

	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void clearScreen();
	void updateScreen();
	void draw(int x, int y, SDL_Texture* texture = nullptr, SDL_Rect* clip =
			nullptr, double angle = 0.0);

	int getWidth();
	int getHeight();

private:
	SDLWindow* window;

	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};
}
#endif /* SDLCONTEXT_H_ */

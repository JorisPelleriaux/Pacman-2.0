#ifndef HEADERS_SDLGHOST_H_
#define HEADERS_SDLGHOST_H_
#include "Ghost.h"
#include "SDLContext.h"

using namespace PACMAN;

namespace PACMAN_SDL {
class SDLGhost: public Ghost {
public:
	SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y,
			int movespeed, int number);
	~SDLGhost();
	void visualise(int State) override;	//State 0: normal ; State 1: smart ; State 2: can be eaten
	void createSprites(int number);

private:
	SDL_Texture* image;
	SDLContext* context;
	SDL_Rect gSpriteClips[2];

	//Current animation frame
	int frame;

	const int ANIMATION_FRAMES_GHOST = 2;
};
}
#endif /* HEADERS_SDLGHOST_H_ */

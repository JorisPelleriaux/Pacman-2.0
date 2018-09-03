#ifndef HEADERS_SDLPACMAN_H_
#define HEADERS_SDLPACMAN_H_
#include "AbsPacman.h"
#include "SDLContext.h"

using namespace PACMAN;

namespace PACMAN_SDL {
class SDLPacman: public AbsPacman {
public:
	SDLPacman(SDLContext* context, AbstractFactory* factory, int lives, int x,
			int y, int movespeed);
	~SDLPacman();
	void visualise(int State) override;	//state 0: Normal ; state 1: Power ; state 2: Dead
	void showText() override;
	void gameOver() override;
	void createSprites();

private:
	SDL_Texture* image;
	SDLContext* context;
	SDL_Rect gSpriteClips[16];

	int frame;
	int ANIMATION_FRAMES = 4;
};
}
#endif /* HEADERS_SDLPACMAN_H_ */

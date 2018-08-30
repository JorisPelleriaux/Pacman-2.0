#ifndef HEADERS_SDLPACMAN_H_
#define HEADERS_SDLPACMAN_H_
#include "AbsPacman.h"
#include "SDLContext.h"

using namespace std;

class SDLPacman: public AbsPacman {
public:
	SDLPacman(SDLContext* context, SDLContext* Tcontext, SDLContext* Gcontext, AbstractFactory* factory, int lives, int x,
			int y, int movespeed);
	~SDLPacman();
	void Visualise(double angle) override;
	void Move(RECT box) override;
	void handleEvent(InputType dir) override;

private:
	SDL_Texture* image;
	SDLContext* context;
	SDLContext* Tcontext;
	SDLContext* Gcontext;

	//The velocity of the Pacman
	int mVelX, mVelY;

	//Collision box of the Pacman
	SDL_Rect mBox;

	//Current animation frame
	int frame;
	RECT pbox;

};

#endif /* HEADERS_SDLPACMAN_H_ */

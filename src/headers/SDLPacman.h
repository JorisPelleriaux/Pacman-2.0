#ifndef HEADERS_SDLPACMAN_H_
#define HEADERS_SDLPACMAN_H_
#include "AbsPacman.h"
#include "SDLContext.h"

using namespace std;

class SDLPacman: public AbsPacman {
public:
	SDLPacman(SDLContext* context, AbstractFactory* factory, int lives, int x,
			int y, int movespeed);
	~SDLPacman();
	void Visualise(int State) override;	//state 0: Normal ; state 1: Power ; state 2: Dead
	void Move(RECT box) override;

private:
	SDL_Texture* imageN;	//Image of normal pacman
	SDL_Texture* imageD;	//Image of pacman die
	SDLContext* context;

	//Collision box of the Pacman
	SDL_Rect mBox;

	//Current animation frame
	int frame;
	RECT pbox;

};

#endif /* HEADERS_SDLPACMAN_H_ */

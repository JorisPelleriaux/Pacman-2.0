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
	void Visualise(double angle) override;

private:
	SDL_Texture* image;
	SDLContext* context;



};

#endif /* HEADERS_SDLPACMAN_H_ */

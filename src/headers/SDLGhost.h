#ifndef HEADERS_SDLGHOST_H_
#define HEADERS_SDLGHOST_H_
#include "Ghost.h"
#include "SDLContext.h"

using namespace std;

class SDLGhost: public Ghost {
public:
	SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y, int movespeed, int number);
	~SDLGhost();
	void Visualise(int State) override;	//State 0: normal ; State 1: smart ; State 2: can be eaten

private:
	SDL_Texture* image;
	SDLContext* context;	//Game context

	//Current animation frame
	int frame;
};

#endif /* HEADERS_SDLGHOST_H_ */

/*
 * SDLGhost.h
 *
 *  Created on: 29 aug. 2018
 *      Author: joris
 */

#ifndef HEADERS_SDLGHOST_H_
#define HEADERS_SDLGHOST_H_
#include "Ghost.h"
#include "SDLContext.h"

using namespace std;

class SDLGhost: public Ghost {
public:
	SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y,
			int movespeed, int number);
	~SDLGhost();
	void Visualise(double angle) override;
	void Move() override;

private:
	SDL_Texture* image;
	SDLContext* context;

	//The velocity of the Ghost
	int mVelX, mVelY;
	//Collision box of the Ghost
	SDL_Rect mBox;

	//Current animation frame
	int frame;

};

#endif /* HEADERS_SDLGHOST_H_ */

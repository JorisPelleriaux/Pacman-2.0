/*
 * SDLGhost.cpp
 *
 *  Created on: 29 aug. 2018
 *      Author: joris
 */

#include <iostream>
#include "SDLGhost.h"

using namespace std;

SDLGhost::SDLGhost(SDLContext* context, SDLContext* Tcontext, AbstractFactory* factory, int x, int y,
		int movespeed, int number) :
		Ghost(factory, x, y, movespeed) {
	this->context = context;
	this->Tcontext = Tcontext;
	image = context->loadFromFile("Media/spritesheet1.png");

	if (image == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreateGhostSprites(number);

	}
	mVelX = movespeed;
	mVelY = 0;
	mBox.x = x;
	mBox.y = y;
	mBox.w = Ghost_WIDTH;
	mBox.h = Ghost_HEIGHT;

	frame = 0;
}

SDLGhost::~SDLGhost() {
	//Free loaded images
	context->free();
}

void SDLGhost::Visualise(double angle) {
	//Render current frame
	SDL_Rect* currentClip = &context->gSpriteClips_Ghost[frame / 4];

	context->Draw(mBox.x, mBox.y, image, currentClip, angle);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= context->ANIMATION_FRAMES_Ghost) {
		frame = 0;
	}
}

void SDLGhost::Move() {
	mBox.x += mVelX;
	//cout<<mBox.x<<endl;
//TODO ghost bewegen



	//If the dot went too far to the left or right or touched a wall
	if ((mBox.x < 0) || (mBox.x + Ghost_WIDTH > 525) || context->touchesWall( mBox, Tcontext->tileSet) ) {	//TODO dynamic breedte
		//move back
		 mVelX = mVelX * (-1);

	}

	//Move the dot up or down
	//mBox.y += mVelY;

	//If the dot went too far up or down or touched a wall
	/*if ((mBox.y < 0) || (mBox.y + Ghost_HEIGHT > 644)) {// || context->touchesWall( mBox)) { //TODO dynamic hoogte
		//move back
		mBox.y -= mVelY;
	}*/

}

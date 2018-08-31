/*
 * SDLGhost.cpp
 *
 *  Created on: 29 aug. 2018
 *      Author: joris
 */

#include <iostream>
#include "SDLGhost.h"

using namespace std;

SDLGhost::SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y,
		int movespeed, int number) :
		Ghost(factory, context, x, y, movespeed) {
	this->context = context;
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

void SDLGhost::Visualise(int State) {
	Box.right = Box.left + Ghost_WIDTH;
	Box.bottom = Box.top + Ghost_HEIGHT;
	context->Ghosts[context->CurrGhost].left = Box.left;
	context->Ghosts[context->CurrGhost].top = Box.top;
	context->Ghosts[context->CurrGhost].right = Box.left + Ghost_WIDTH;
	context->Ghosts[context->CurrGhost].bottom = Box.top + Ghost_HEIGHT;

	//Render current frame
	SDL_Rect* currentClip = &context->gSpriteClips_Ghost[context->CurrGhost][frame / 4];

	context->Draw(Box.left, Box.top, image, currentClip, 0.0);

	context->CurrGhost++;

	if(context->CurrGhost == 4){
		context->CurrGhost = 0;
	}
	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= context->ANIMATION_FRAMES_Ghost) {
		frame = 0;
	}
}

/*void SDLGhost::Move(RECT box) {

 }*/
/*
 //Give position to AbsGhost
 this->Box.left +=mVelX;
 this->Box.top +=mVelY;
 this->Box.right = this->Box.left + this->Ghost_WIDTH;
 this->Box.bottom = this->Box.top + this->Ghost_HEIGHT;

 //TODO ghost bewegen



 //If the dot went too far to the left or right or touched a wall
 if (context->touchesWall( mBox, Tcontext->tileSet, false) ) {
 mVelX = mVelX * (-1);
 }
 /*//*/move back
 int j =rand()%4;

 switch(j){
 case 0:
 //move right
 mBox.x += mVelX;
 break;
 case 1:
 //move left
 mBox.x -= mVelX;
 break;
 case 2:
 //move down
 mBox.y += mVelY;
 break;
 case 3:
 //move up
 mBox.y -= mVelY;
 break;
 default:
 //move down
 mBox.y += mVelY;
 break;
 }
 mVelX = mVelX * (-1);

 }*/

//Move the dot up or down
//mBox.y += mVelY;
//If the dot went too far up or down or touched a wall
/*if ((mBox.y < 0) || (mBox.y + Ghost_HEIGHT > context->sHeight)) {// || context->touchesWall( mBox)) {
 //move back
 mBox.y -= mVelY;
 }*/

//}

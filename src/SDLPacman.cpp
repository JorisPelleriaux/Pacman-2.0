#include <iostream>
#include "SDLPacman.h"

using namespace std;

SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives,
		int x, int y, int movespeed) :
		AbsPacman(factory, lives, x, y, movespeed) {
	this->context = context;
	image = context->loadFromFile("Media/Pacman_sprite.png");

	if (image == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreatePacSprites();

	}
	mVelX = 0;
	mVelY = 0;
	mBox.x = x;
	mBox.y = y;
	mBox.w = PAC_WIDTH;
	mBox.h = PAC_HEIGHT;

	//Current animation frame
	frame = 0;
}

SDLPacman::~SDLPacman() {
	//Free loaded images
	context->free();
}

void SDLPacman::Visualise(double angle) {
	//cout << PAC_VEL << endl;

	//Render current frame
	SDL_Rect* currentClip = &context->gSpriteClips[frame / 8];

	context->Draw(mBox.x, mBox.y, image, currentClip, angle);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 8 >= context->ANIMATION_FRAMES) {
		frame = 0;
	}

}

void SDLPacman::handleEvent(InputType dir) {
	//Adjust the velocity
	switch (dir) {
	case UUp:
		mVelY += PAC_VEL;
		break;
	case UDown:
		mVelY -= PAC_VEL;
		break;
	case ULeft:
		mVelX += PAC_VEL;
		break;
	case URight:
		mVelX -= PAC_VEL;
		break;
	case DUp:
		mVelY -= PAC_VEL;
		break;
	case DDown:
		mVelY += PAC_VEL;
		break;
	case DLeft:
		mVelX -= PAC_VEL;
		break;
	case DRight:
		mVelX += PAC_VEL;
		break;
	default:
		return;
	}
}

void SDLPacman::Move() {
	//mVelX = 0;
	//mVelY = 0;

	//cout << "pac move" << endl;
	//Move the dot left or right
	mBox.x += mVelX;

	//Move the dot up or down
	//mBox.y += mVelY;

	//Move the dot left or right
	//mBox.x += mVelX;

	//If the dot went too far to the left or right or touched a wall
	if ((mBox.x < 0) || (mBox.x + PAC_WIDTH > 525)) {// || context->touchesWall( mBox) ) {	//TODO dynamic breedte
		//move back
		cout << "links rechts" << endl;
		mBox.x -= mVelX;
	}

	//Move the dot up or down
	mBox.y += mVelY;

	//If the dot went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + PAC_HEIGHT > 644)) {// || context->touchesWall( mBox)) { //TODO dynamic hoogte
		//move back
		mBox.y -= mVelY;
	}
}

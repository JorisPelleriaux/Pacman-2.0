#include <iostream>
#include "SDLPacman.h"

using namespace std;

SDLPacman::SDLPacman(SDLContext* context, SDLContext* Tcontext,
		SDLContext* Gcontext, AbstractFactory* factory, int lives, int x, int y,
		int movespeed) :
		AbsPacman(factory, lives, x, y, movespeed) {
	this->context = context;
	this->Tcontext = Tcontext;
	this->Gcontext = Gcontext;
	image = context->loadFromFile("Media/Pacman_sprite.png");

	if (image == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreatePacSprites();

	}
	mVelX = 0;
	mVelY = 0;
	mBox.x = pbox.left = x;
	mBox.y = pbox.top = y;
	mBox.w = PAC_WIDTH;
	mBox.h = PAC_HEIGHT;
	pbox.right = x + PAC_WIDTH;
	pbox.bottom = y + PAC_HEIGHT;

	//Current animation frame
	frame = 0;
}

SDLPacman::~SDLPacman() {
	//Free loaded images
	context->free();
}

void SDLPacman::Visualise(double angle) {

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

void SDLPacman::Move(RECT box) {
	this->box.left += mVelX;
	this->box.top += mVelY;
	this->box.right = this->box.left + this->PAC_WIDTH;
	this->box.bottom = this->box.top + this->PAC_HEIGHT;

	mBox.x += mVelX;	//Move the Pacman left or right

	if (this->context->checkcollision(box, pbox)) {
		cout << "ghost geraakt" << endl;
	}

	//pass right exit
	if (mBox.x + PAC_WIDTH > context->sWidth) {
		mBox.x = 0;
	}
	//pass left exit
	if (mBox.x < 0) {
		mBox.x = context->sWidth - PAC_WIDTH;
	}

	//If the Pac touched a wall
	if (context->touchesWall(mBox, Tcontext->tileSet, true)) {
		//move back
		mBox.x -= mVelX;	//Stop
	}

	mBox.y += mVelY;	//Move the Pacman up or down

	//If the Pac went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + PAC_HEIGHT > context->sHeight)
			|| context->touchesWall(mBox, Tcontext->tileSet, true)) {
		mBox.y -= mVelY;	//Stop
	}
}

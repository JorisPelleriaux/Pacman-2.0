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
	context->free();	//Free loaded images
}

void SDLPacman::Visualise(int angle) {

	SDL_Rect* currentClip = &context->gSpriteClips[frame / 8];//Render current frame
	context->Draw(mBox.x, mBox.y, image, currentClip, sAngle);

	++frame;	//Go to next frame

	//Cycle animation
	if (frame / 8 >= context->ANIMATION_FRAMES) {
		frame = 0;
	}
}

void SDLPacman::Move(RECT box) {

	this->box.left = mBox.x;
	this->box.top = mBox.y;
	this->box.right = this->box.left + this->PAC_WIDTH;
	this->box.bottom = this->box.top + this->PAC_HEIGHT;

	mBox.x += XVEL;	//Move the Pacman left or right
//cout<<mBox.x<<endl;

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
		mBox.x -= XVEL;	//Stop
	}

	mBox.y += YVEL;	//Move the Pacman up or down

	//If the Pac went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + PAC_HEIGHT > context->sHeight)
			|| context->touchesWall(mBox, Tcontext->tileSet, true)) {
		mBox.y -= YVEL;	//Stop
	}
}

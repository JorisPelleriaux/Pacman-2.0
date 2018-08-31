#include <iostream>
#include "SDLPacman.h"

using namespace std;

SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives, int x, int y,
		int movespeed) :
		AbsPacman(factory, context, lives, x, y, movespeed) {
	this->context = context;
	imageN = context->loadFromFile("Media/Pacman_sprite.png");
	imageD = context->loadFromFile("Media/Pacman_sprite.png");

	if (imageN == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreatePacSprites();

	}

	mBox.x = pbox.left = x;
	mBox.y = pbox.top = y;
	mBox.w = PAC_WIDTH;
	mBox.h = PAC_HEIGHT;
	Pbox.left = x;
	Pbox.top = y;
	//Current animation frame
	frame = 0;

}

SDLPacman::~SDLPacman() {
	context->free();	//Free loaded images
}

void SDLPacman::Visualise(int State) {
	Pbox.right = Pbox.left + 25;
	Pbox.bottom = Pbox.top + 25;

	SDL_Rect* currentClip = &context->gSpriteClips[frame / 8];//Render current frame
	context->Draw(mBox.x, mBox.y, imageN, currentClip, sAngle);

	++frame;	//Go to next frame

	//Cycle animation
	if (frame / 8 >= context->ANIMATION_FRAMES) {
		frame = 0;
	}
}

void SDLPacman::Move(RECT box) {


	this->Pbox.left = mBox.x;
	this->Pbox.top = mBox.y;
	this->Pbox.right = this->Pbox.left + this->PAC_WIDTH;
	this->Pbox.bottom = this->Pbox.top + this->PAC_HEIGHT;

	mBox.x += XVEL;	//Move the Pacman left or right

	//pass right exit
	if (mBox.x + PAC_WIDTH > context->sWidth) {
		mBox.x = 0;
	}
	//pass left exit
	if (mBox.x < 0) {
		mBox.x = context->sWidth - PAC_WIDTH;
	}
	//If the Pac touched a wall
	if (context->touchesWall(mBox, context->tileSet, true)) {
		//move back
		cout<<"wall"<<endl;
		mBox.x -= XVEL;	//Stop
	}

	mBox.y += YVEL;	//Move the Pacman up or down

	//If the Pac went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + PAC_HEIGHT > context->sHeight)
			|| context->touchesWall(mBox, context->tileSet, true)) {
		mBox.y -= YVEL;	//Stop
	}

}

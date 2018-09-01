#include <iostream>
#include "SDLPacman.h"

using namespace std;

SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives,
		int x, int y, int movespeed) :
		AbsPacman(factory, context, lives, x, y, movespeed) {
	this->context = context;
	imageN = context->loadFromFile("Media/Pacman_sprite.png");
	imageD = context->loadFromFile("Media/PacmanDie.png");

	if (imageN == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreatePacSprites();

	}

	this->x = x;
	this->y = y;
	mBox.x = x;
	mBox.y = y;
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

	if (State == 0) {	//Normal Pacman
		SDL_Rect* currentClip = &context->gSpriteClips[frame / 8];//Render current frame
		context->Draw(mBox.x, mBox.y, imageN, currentClip, sAngle);
		context->ANIMATION_FRAMES = 4;
	}

	if (State == 2) {	//Dead Pacman
		SDL_Rect* currentClip = &context->gSpriteClips[frame / 8 + 4];//Render current frame
		context->Draw(mBox.x, mBox.y, imageD, currentClip, 0);
		context->ANIMATION_FRAMES = 12;
	}

	++frame;	//Go to next frame

	//Cycle animation
	if (frame / 8 >= context->ANIMATION_FRAMES) {
		if (context->ANIMATION_FRAMES == 4) {
			frame = 0;
		} else {
			this->SetStartPosition();
			this->IsDead = true;
		}

	}
}

void SDLPacman::SetStartPosition() {
	mBox.x = x;
	mBox.y = y;
	XVEL = 0;
	YVEL = 0;
	sAngle = 0;
}

void SDLPacman::ShowText() {
	//Render text
	std::string Text = "Score: " + std::to_string(context->score);
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 28)) {
		printf("Failed to render text texture!\n");
	}
	context->Draw(20, 5, context->mTexture);

	Text = "Lives: " + std::to_string(this->GetLives());
	if (!context->loadFromRenderedText(Text, textColor,28)) {
		printf("Failed to render text texture!\n");
	}
	context->Draw(context->sWidth - 145, 5, context->mTexture);
}

void SDLPacman::GameOver() {
	//Render text
	std::string Text = "Game Over";
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor,50)) {
		printf("Failed to render text texture!\n");
	}
	context->Draw((context->sWidth-150)/2, (context->sHeight -50) /2, context->mTexture);
}

void SDLPacman::Move() {

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
		mBox.x -= XVEL;	//Stop
	}

	mBox.y += YVEL;	//Move the Pacman up or down

	//If the Pac went too far up or down or touched a wall
	if ((mBox.y < 0) || (mBox.y + PAC_HEIGHT > context->sHeight)
			|| context->touchesWall(mBox, context->tileSet, true)) {
		mBox.y -= YVEL;	//Stop
	}
}

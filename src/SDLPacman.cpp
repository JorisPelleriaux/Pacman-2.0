#include <iostream>
#include "SDLPacman.h"

using namespace std;

namespace PACMAN_SDL {
SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives,
		int x, int y, int movespeed) :
		AbsPacman(factory, context, lives, x, y, movespeed) {
	this->context = context;
	image = context->loadFromFile("Media/Pacman.png");

	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips
		context->createPacSprites();
	}
	//Current animation frame
	frame = 0;

}

SDLPacman::~SDLPacman() {
	//Free loaded images
	context->free();
}

void SDLPacman::visualise(int State) {


	if (State == 0) {	//Normal Pacman
		SDL_Rect* currentClip = &context->gSpriteClips[frame / 8];//Render current frame
		context->draw(getBox().left, getBox().top, image, currentClip, getAngle());
		ANIMATION_FRAMES = 4;
	}

	if (State == 2) {	//Dead Pacman
		SDL_Rect* currentClip = &context->gSpriteClips[frame / 8 + 4];//Render current frame
		context->draw(getBox().left, getBox().top, image, currentClip, 0);
		ANIMATION_FRAMES = 12;
	}

	++frame;	//Go to next frame

	//Cycle animation
	if (frame / 8 >= ANIMATION_FRAMES) {
		if (ANIMATION_FRAMES == 4) {
			frame = 0;
		} else {
			this->IsDead = true;
			this->setStartPosition();

		}

	}
}

void SDLPacman::showText() {
	//Render text
	std::string Text = "Score: " + std::to_string(context->score);
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 28)) {
		printf("Failed to render text texture!\n");
	}
	context->draw(20, 5, context->mTexture);

	Text = "Lives: " + std::to_string(this->getLives());
	if (!context->loadFromRenderedText(Text, textColor, 28)) {
		printf("Failed to render text texture!\n");
	}
	context->draw(context->sWidth - 145, 5, context->mTexture);
}

void SDLPacman::gameOver() {
	//Render text
	std::string Text = "Game Over";
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 50)) {
		printf("Failed to render text texture!\n");
	}
	context->draw((context->sWidth - context->getWidth()) / 2, (context->sHeight - context->getHeight()) / 2,
			context->mTexture);
}
}

#include <iostream>
#include "SDLPacman.h"

namespace PACMAN_SDL {
SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives,
		int x, int y, int movespeed) :
		AbsPacman(factory, context, lives, x, y, movespeed) {
	this->context = context;

	image = context->loadFromFile("Media/Pacman.png");

	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	} else {
		createSprites();
	}

	frame = 0;
}
SDLPacman::~SDLPacman() {
	//Free loaded images
	context->free();
}

void SDLPacman::visualise(int State) {
	if (State == 0) {	//Normal Pacman
		SDL_Rect* currentClip = &gSpriteClips[frame / 8];//Render current frame
		context->draw(getBox().left, getBox().top, image, currentClip,
				getAngle());
		ANIMATION_FRAMES = 4;
	}

	if (State == 2) {	//Dead Pacman
		SDL_Rect* currentClip = &gSpriteClips[frame / 8 + 4];//Render current frame
		context->draw(getBox().left, getBox().top, image, currentClip, 0);
		ANIMATION_FRAMES = 12;
	}

	++frame;

	if (frame / 8 >= ANIMATION_FRAMES) {
		if (ANIMATION_FRAMES == 4) {
			frame = 0;
		} else {
			this->IsDead = true;
			this->setStartPosition();
		}
	}
}

void SDLPacman::createSprites() {
	gSpriteClips[0].x = 70;
	gSpriteClips[0].y = 35;
	gSpriteClips[0].w = 36;
	gSpriteClips[0].h = 36;

	gSpriteClips[1].x = 35;
	gSpriteClips[1].y = 35;
	gSpriteClips[1].w = 33;
	gSpriteClips[1].h = 36;

	gSpriteClips[2].x = 0;
	gSpriteClips[2].y = 35;
	gSpriteClips[2].w = 33;
	gSpriteClips[2].h = 36;

	gSpriteClips[3].x = 35;
	gSpriteClips[3].y = 35;
	gSpriteClips[3].w = 33;
	gSpriteClips[3].h = 36;

	gSpriteClips[4].x = 0;
	gSpriteClips[4].y = 0;
	gSpriteClips[4].w = 35;
	gSpriteClips[4].h = 35;

	gSpriteClips[5].x = 42;
	gSpriteClips[5].y = 0;
	gSpriteClips[5].w = 33;
	gSpriteClips[5].h = 35;

	gSpriteClips[6].x = 81;
	gSpriteClips[6].y = 0;
	gSpriteClips[6].w = 38;
	gSpriteClips[6].h = 35;

	gSpriteClips[7].x = 123;
	gSpriteClips[7].y = 0;
	gSpriteClips[7].w = 38;
	gSpriteClips[7].h = 35;

	gSpriteClips[8].x = 165;
	gSpriteClips[8].y = 0;
	gSpriteClips[8].w = 38;
	gSpriteClips[8].h = 35;

	gSpriteClips[9].x = 206;
	gSpriteClips[9].y = 0;
	gSpriteClips[9].w = 39;
	gSpriteClips[9].h = 35;

	gSpriteClips[10].x = 248;
	gSpriteClips[10].y = 0;
	gSpriteClips[10].w = 38;
	gSpriteClips[10].h = 35;

	gSpriteClips[11].x = 293;
	gSpriteClips[11].y = 0;
	gSpriteClips[11].w = 32;
	gSpriteClips[11].h = 35;

	gSpriteClips[12].x = 335;
	gSpriteClips[12].y = 0;
	gSpriteClips[12].w = 32;
	gSpriteClips[12].h = 35;

	gSpriteClips[13].x = 377;
	gSpriteClips[13].y = 0;
	gSpriteClips[13].w = 32;
	gSpriteClips[13].h = 35;

	gSpriteClips[14].x = 418;
	gSpriteClips[14].y = 0;
	gSpriteClips[14].w = 33;
	gSpriteClips[14].h = 35;

	gSpriteClips[15].x = 462;
	gSpriteClips[15].y = 0;
	gSpriteClips[15].w = 28;
	gSpriteClips[15].h = 35;
}

void SDLPacman::showText() {
	std::string Text = "Score: " + std::to_string(context->score);
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 28)) {
		printf("Failed to render text texture!\n");
	}
	context->draw(20, 5);

	Text = "Lives: " + std::to_string(this->getLives());
	if (!context->loadFromRenderedText(Text, textColor, 28)) {
		printf("Failed to render text texture!\n");
	}
	context->draw((context->sWidth - context->getWidth()) - 20, 5);
}

void SDLPacman::gameOver() {
	std::string Text = "Game Over";
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 50)) {
		printf("Failed to render text texture!\n");
	}
	context->draw((context->sWidth - context->getWidth()) / 2,
			(context->sHeight - context->getHeight()) / 2);
}
}

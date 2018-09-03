#include <iostream>
#include "SDLGhost.h"

namespace PACMAN_SDL {
SDLGhost::SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y,
		int movespeed, int number) :
		Ghost(factory, context, x, y, movespeed) {
	this->context = context;

	image = context->loadFromFile("Media/Ghosts.png");

	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	} else {
		createSprites(number);
	}

	frame = 0;
}
SDLGhost::~SDLGhost() {
	//Free loaded images
	context->free();
}

void SDLGhost::visualise(int State) {
	//Render current frame
	SDL_Rect* currentClip = &gSpriteClips[frame / 4];
	context->draw(getBox().left, getBox().top, image, currentClip, 0.0);

	++frame;

	if (frame / 4 >= ANIMATION_FRAMES_GHOST) {
		frame = 0;
	}
}

void SDLGhost::createSprites(int number) {
	//Depending on the number -> other clip
	int x1, x2, y1, y2;
	switch (number) {
	case 0:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 0;
		break;
	case 1:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 34;
		break;
	case 2:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 77;
		break;
	case 3:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 112;
		break;
	default:
		break;
	}

	gSpriteClips[0].x = x1;
	gSpriteClips[0].y = y1;
	gSpriteClips[0].w = 23;
	gSpriteClips[0].h = 25;

	gSpriteClips[1].x = x2;
	gSpriteClips[1].y = y2;
	gSpriteClips[1].w = 23;
	gSpriteClips[1].h = 25;
}
}

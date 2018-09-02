#include <iostream>
#include "SDLGhost.h"

using namespace std;

namespace PACMAN_SDL {
SDLGhost::SDLGhost(SDLContext* context, AbstractFactory* factory, int x, int y,
		int movespeed, int number) :
		Ghost(factory, context, x, y, movespeed) {
	this->context = context;
	image = context->loadFromFile("Media/Ghosts.png");

	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips
		context->createGhostSprites(number);
	}

	//Initialize
	frame = 0;
}

SDLGhost::~SDLGhost() {
	//Free loaded images
	context->free();
}

void SDLGhost::visualise(int State) {
	//Render current frame
	SDL_Rect* currentClip =
			&context->gSpriteClips_Ghost[context->currGhost][frame / 4];
	context->draw(getBox().left, getBox().top, image, currentClip, 0.0);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= ANIMATION_FRAMES_GHOST) {
		frame = 0;
	}
}
}

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

	//Initialize
	frame = 0;
}

SDLGhost::~SDLGhost() {
	//Free loaded images
	context->free();
}

void SDLGhost::Visualise(int State) {
	//Render current frame
	SDL_Rect* currentClip = &context->gSpriteClips_Ghost[context->CurrGhost][frame / 4];
	context->Draw(Box.left, Box.top, image, currentClip, 0.0);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 4 >= context->ANIMATION_FRAMES_Ghost) {
		frame = 0;
	}
}

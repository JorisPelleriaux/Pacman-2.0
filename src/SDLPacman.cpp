#include <iostream>
#include "SDLPacman.h"

using namespace std;

SDLPacman::SDLPacman(SDLContext* context, AbstractFactory* factory, int lives, int x, int y, int movespeed) : AbsPacman(factory, lives, x, y, movespeed) {
	this->context = context;
	image = context->loadFromFile("Media/Pacman_sprite.png");

	if (image == NULL) {
		printf("Failed to load texture image!\n");
	} else {
		//Set sprite clips

		context->CreateSprites();

	}
}

SDLPacman::~SDLPacman() {
	//Free loaded images
	context->free();
}

void SDLPacman::Visualise(double angle) {
	//cout << "ik ben een SDL pacman" << endl;



	//Render current frame

	context->Draw(x, y, image,NULL, angle);
	context->UpdateScreen();





}


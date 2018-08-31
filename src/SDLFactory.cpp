#include <iostream>
#include "AbsPacman.h"
#include "Ghost.h"
#include "SDLFactory.h"
using namespace std;

SDLFactory::SDLFactory() {
	Paccontext = NULL;
	Tilecontext = NULL;
	inputHandler = NULL;
	Ghostcontext = NULL;
}

SDLFactory::~SDLFactory() {
	delete Paccontext;
	delete Tilecontext;
	delete inputHandler;
	delete Ghostcontext;
}

AbsPacman* SDLFactory::CreatePacman(int lives, int x, int y, int movespeed) {
	return new SDLPacman(Paccontext, Tilecontext, Ghostcontext, this, lives, x, y, movespeed);
}



Window* SDLFactory::CreateWindow(int screen_width, int screen_height) {
	SDLWindow* window = new SDLWindow(screen_width, screen_height);
	this->Paccontext = new SDLContext(window);
	this->Tilecontext = new SDLContext(window);
	this->Ghostcontext = new SDLContext(window);
	return window;
}

Background* SDLFactory::CreateBackground() {
	return new SDLBackground(Tilecontext);
}

Input* SDLFactory::GetInputhandler() {
	if (inputHandler == NULL) {
		inputHandler = new SDLInput();
	}
	return inputHandler;
}
Ghost* SDLFactory::CreateGhost(int x, int y, int movespeed, int number) {
	return new SDLGhost(Ghostcontext, Tilecontext, this, x, y, movespeed, number);
}

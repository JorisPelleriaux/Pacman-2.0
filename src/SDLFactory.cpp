#include <iostream>
//#include "AbsPacman.h"
//#include "Ghost.h"
#include "SDLFactory.h"
using namespace std;

namespace PACMAN_SDL {
SDLFactory::SDLFactory() {
	Gamecontext = NULL;
	inputHandler = NULL;
}

SDLFactory::~SDLFactory() {
	delete Gamecontext;
	delete inputHandler;
}

AbsPacman* SDLFactory::CreatePacman(int lives, int x, int y, int movespeed) {
	return new SDLPacman(Gamecontext, this, lives, x, y, movespeed);
}

Window* SDLFactory::CreateWindow(int screen_width, int screen_height) {
	SDLWindow* window = new SDLWindow(screen_width, screen_height);
	this->Gamecontext = new SDLContext(window);
	return window;
}

Background* SDLFactory::CreateBackground() {
	return new SDLBackground(Gamecontext);
}

Input* SDLFactory::GetInputhandler() {
	if (inputHandler == NULL) {
		inputHandler = new SDLInput();
	}
	return inputHandler;
}
Ghost* SDLFactory::CreateGhost(int x, int y, int movespeed, int number) {
	return new SDLGhost(Gamecontext, this, x, y, movespeed, number);
}
}

#include "SDLFactory.h"

namespace PACMAN_SDL {
SDLFactory::SDLFactory() {
	Gamecontext = nullptr;
	inputHandler = nullptr;
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
	if (inputHandler == nullptr) {
		inputHandler = new SDLInput();
	}
	return inputHandler;
}
Ghost* SDLFactory::CreateGhost(int x, int y, int movespeed, int number) {
	return new SDLGhost(Gamecontext, this, x, y, movespeed, number);
}
}

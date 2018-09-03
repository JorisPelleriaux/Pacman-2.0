#include <sdl2/SDL.h>
#include <iostream>
#include "SDLInput.h"

using namespace std;

namespace PACMAN_SDL {
SDLInput::SDLInput() {
}
SDLInput::~SDLInput() {
}

BaseInput* SDLInput::getInput() {
	BaseInput* input = new BaseInput();
	SDL_Event e;
	SDL_PollEvent(&e);

	//If a key was pressed
	if (e.type == SDL_QUIT) {
		cout << "quit" << endl;
		input->inputVector.push_back(InputType::Quit);
	}

	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		//Get input
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			input->inputVector.push_back(InputType::DUp);
			break;
		case SDLK_DOWN:
			input->inputVector.push_back(InputType::DDown);
			break;
		case SDLK_LEFT:
			input->inputVector.push_back(InputType::DLeft);
			break;
		case SDLK_RIGHT:
			input->inputVector.push_back(InputType::DRight);
			break;
		case SDLK_ESCAPE:
			cout << "quit" << endl;
			input->inputVector.push_back(InputType::Quit);
			break;
		case SDLK_RETURN:
			input->inputVector.push_back(InputType::Enter);
			break;
		case SDLK_KP_ENTER:
			input->inputVector.push_back(InputType::Enter);
			break;

		}
	}
	//If a key was released
	if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		//Get input
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			input->inputVector.push_back(InputType::UUp);
			break;
		case SDLK_DOWN:
			input->inputVector.push_back(InputType::UDown);
			break;
		case SDLK_LEFT:
			input->inputVector.push_back(InputType::ULeft);
			break;
		case SDLK_RIGHT:
			input->inputVector.push_back(InputType::URight);
			break;
		}
	}
	return input;
}
}

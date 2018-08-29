#include "SDLInput.h"
#include "sdl2/SDL.h"
#include <iostream>
using namespace std;
SDLInput::SDLInput() {
	// TODO Auto-generated constructor stub

}

SDLInput::~SDLInput() {
	// TODO Auto-generated destructor stub
}

BaseInput* SDLInput::GetInput() {
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
				cout << "up" << endl;
				input->inputVector.push_back(InputType::DUp);
				break;
			case SDLK_DOWN:
				cout << "down" << endl;
				input->inputVector.push_back(InputType::DDown);
				break;
			case SDLK_LEFT:
				cout << "left" << endl;
				input->inputVector.push_back(InputType::DLeft);
				break;
			case SDLK_RIGHT:
				cout << "right" << endl;
				input->inputVector.push_back(InputType::DRight);
				break;
			case SDLK_ESCAPE:
				cout << "quit" << endl;
				input->inputVector.push_back(InputType::Quit);
				break;
			}
		}
		//If a key was released
				if (e.type == SDL_KEYUP && e.key.repeat == 0) {
					//Get input
					switch (e.key.keysym.sym) {
					case SDLK_UP:
						cout << "up" << endl;
						input->inputVector.push_back(InputType::UUp);
						break;
					case SDLK_DOWN:
						cout << "down" << endl;
						input->inputVector.push_back(InputType::UDown);
						break;
					case SDLK_LEFT:
						cout << "left" << endl;
						input->inputVector.push_back(InputType::ULeft);
						break;
					case SDLK_RIGHT:
						cout << "right" << endl;
						input->inputVector.push_back(InputType::URight);
						break;
					}
				}
	return input;

}

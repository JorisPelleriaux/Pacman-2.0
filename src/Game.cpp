#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"
#include "SDLWindow.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

//Constructor sets required parameters, state and default name
Game::Game(AbstractFactory* factory) {
	//make the factory (SDL factory)
	this->factory = factory;

	//Create a window
	window = factory->CreateWindow(525, 665);
	window->CreateWindow();

	//Render the background
	background = factory->CreateBackground();

	//Create Pacman
	Pac = factory->CreatePacman(3, 251, 595, 10);

	//Default state (later use)
	state = Menu;

	//Inputhandler
	inputhandler = factory->GetInputhandler();
	input = NULL;

	//Create Ghosts
	for (int i = 1; i <= 4; i++) {
		Ghosts[i] = factory->CreateGhost(300, 250 + i, 1, i);
	}

}
void Game::Start() {
	//Main loop flag
	bool quit = false;
	int angle = 0;
	while (!quit) {

		//cout<<this->Ghosts[1]->Box.bottom<<endl;

		//Get input and check for quit
		input = inputhandler->GetInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			quit = true;
		}

		//pass the input (left,right,up,down) to the pac
		for (InputType dir : input->inputVector) {
			Pac->handleEvent(dir);
		}

		//Move the pacman
		Pac->Move(this->Ghosts[1]->Box);

		//Move the ghosts
		/*for (int i = 1; i <= 4; i++) {
			Ghosts[i]->Move(this->Pac->box);
		}*/
		Ghosts[1]->Move(this->Pac->box);
		//Render Background
		background->Visualise(angle);

		//Render pacman
		Pac->Visualise(angle);

		//Render Ghosts
		/*for (int i = 1; i <= 4; i++) {
			Ghosts[i]->Visualise(i);
		}*/
		Ghosts[1]->Visualise(1);
		//Update screen
		window->Render();
	}

}

Game::~Game() {
	delete Pac;
	delete background;
	delete Ghosts[1];
	delete Ghosts[2];
	delete window;

}

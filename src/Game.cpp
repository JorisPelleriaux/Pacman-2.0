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

	//Create Ghosts
	for (int i = 0; i < 4; i++) {
		Ghosts[i] = factory->CreateGhost(300 - (i * 40), 250 + (2 * 20), 1, i);
	}

	//Create Pacman
	Pac = factory->CreatePacman(3, 251, 595, 10);

	//Default state
	state = Running;

	//Inputhandler
	inputhandler = factory->GetInputhandler();
	input = NULL;

}
void Game::Start() {
	//Main loop flag
	int angle = 0;
	while (state != QuitGame) {
		//Get input and check for quit
		input = inputhandler->GetInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			state = QuitGame;
		}

		switch (state) {
		case Menu:
			break;
		case Running: {
			//pass the input (left,right,up,down) to the pac
			for (InputType dir : input->inputVector) {
				Pac->handleEvent(dir);
			}
			Pac->Move(this->Ghosts[2]->Box);	//Move the pacman

			//Move the ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->Move(this->Pac->Pbox);
			}
			//Render Background
			background->Visualise(0);
			//Render Ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->Visualise(0);
			}
			if (Pac->CheckCollision()) {
				//Pac->TakeLive();
				//Pac->Visualise(2);
				cout<<"RAAK"<<endl;
			}
			//Render pacman
			Pac->Visualise(0);
			//Update screen
			window->Render();

		}
			break;
		case GameOver:
			break;
		case NoState:
			break;
		}

	}

}

Game::~Game() {
	delete Pac;
	delete background;
	delete Ghosts[1];
	delete Ghosts[2];
	delete window;

}

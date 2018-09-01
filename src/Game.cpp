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
	state = Menu;

	//Inputhandler
	inputhandler = factory->GetInputhandler();
	input = NULL;

}
void Game::Start() {
	//Main loop flag

	while (state != QuitGame) {
		//Get input and check for quit
		input = inputhandler->GetInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			state = QuitGame;
		}

		switch (state) {
		case Menu:
			//clear screen
			window->ClearScreen();
			//Render Background
			background->Visualise(0);
			background->StartScreen();
			//Update screen
			window->Render();

			if (find(input->inputVector.begin(), input->inputVector.end(),
					InputType::Enter) != input->inputVector.end()) {
				state = Running;
			}
			break;
		case Running: {
			//pass the input (left,right,up,down) to the pac
			for (InputType dir : input->inputVector) {
				Pac->handleEvent(dir);
			}

			//clear screen
			window->ClearScreen();

			Pac->Move();	//Move the pacman
			//Render Background
			background->Visualise(0);

			//Move and Render the ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->Move();
				Ghosts[i]->Visualise(0);
			}

			if (Pac->CheckCollision()) {	//Check collision with ghosts
				cout << "Ghost geraakt" << endl;
				if (Pac->GetLives() > 0) {
					Pac->TakeLive();
					state = LostLife;
				} else {
					state = GameOver;
				}
			}
			//Render pacman
			Pac->Visualise(0);
			Pac->ShowText();
			//Update screen
			window->Render();

		}
			break;
		case LostLife:
			//clear screen
			window->ClearScreen();

			//Render Background
			background->Visualise(0);
			//Render Ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->Move();
				Ghosts[i]->Visualise(0);
			}
			//Render pacman
			Pac->Visualise(2);
			//Update screen
			window->Render();

			if (Pac->IsDead) {
				Pac->IsDead = false;
				state = Running;
			}

			break;
		case GameOver:
			//clear screen
			window->ClearScreen();

			//Render Background
			background->Visualise(0);
			//Render Ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->Move();
				Ghosts[i]->Visualise(0);
			}
			//Render pacman
			Pac->Visualise(2);
			Pac->GameOver();
			//Update screen
			window->Render();
			break;
		case QuitGame:
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

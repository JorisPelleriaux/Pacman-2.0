#include <iostream>
#include "AbstractFactory.h"
#include "Game.h"
#include "SDLWindow.h"
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <stdio.h>
#include <algorithm>

namespace PACMAN {

Game::Game(AbstractFactory* factory) {
	//make the factory (SDL factory)
	this->factory = factory;

	//Create a window
	window = factory->CreateWindow(525, 665);
	window->createWindow();

	//Render the background
	background = factory->CreateBackground();

	//Create Ghosts
	for (int i = 0; i < 4; i++) {
		Ghosts[i] = factory->CreateGhost(300 - (i * 40), 258, 2, i);
	}

	//Create Pacman
	Pac = factory->CreatePacman(3, 246, 595, 2);

	//Default state
	state = Menu;

	//Inputhandler
	inputhandler = factory->GetInputhandler();
	input = nullptr;

}
void Game::start() {
	//Main loop flag
	while (state != QuitGame) {
		//Get input and check for quit
		input = inputhandler->getInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			state = QuitGame;
		}

		switch (state) {
		case Menu:
			//clear screen
			window->clearScreen();
			//Render Background
			background->visualise(0);
			background->startScreen();
			//Move and Render the ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->move();
				Ghosts[i]->visualise(0);
			}
			//Update screen
			window->render();

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
			window->clearScreen();

			Pac->move();	//Move the pacman
			//Render Background
			background->visualise(0);

			//Move and Render the ghosts
			for (int i = 0; i < 4; i++) {
				if (!Ghosts[i]->start) {
					Ghosts[i]->startMove();
				} else {
					Ghosts[i]->move();
				}

				Ghosts[i]->visualise(0);
			}
			if (Pac->checkCollision()) {	//Check collision with ghosts
				cout << "Ghost geraakt" << endl;
				if (Pac->getLives() > 1) {
					Pac->takeLive();
					state = LostLife;
				} else {
					state = GameOver;
				}
			}
			//Render pacman
			Pac->visualise(0);
			Pac->showText();	//Show Score, Lives
			//Update screen
			window->render();

		}
			break;
		case LostLife:
			//clear screen
			window->clearScreen();

			//Render Background
			background->visualise(0);
			//Render pacman
			Pac->visualise(2);
			//Update screen
			window->render();

			if (Pac->IsDead) {
				Pac->IsDead = false;
				for (int i = 0; i < 4; i++) {
					Ghosts[i]->start = false;
					Ghosts[i]->defaultPosition(i);
				}
				state = Running;
			}

			break;
		case GameOver:
			//clear screen
			window->clearScreen();

			//Render Background
			background->visualise(0);
			//Render Ghosts
			for (int i = 0; i < 4; i++) {
				Ghosts[i]->move();
				Ghosts[i]->visualise(0);
			}
			if (!Pac->IsDead) {
				//Render pacman
				Pac->visualise(2);
			}

			Pac->gameOver();

			//Update screen
			window->render();
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
	delete inputhandler;
	delete input;
	for (int i = 0; i < 4; i++) {
		delete Ghosts[i];
	}
	delete window;

}
}

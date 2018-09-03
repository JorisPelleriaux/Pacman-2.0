#include <iostream>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <stdio.h>
#include <algorithm>
#include "AbstractFactory.h"
#include "Game.h"
#include "SDLWindow.h"

namespace PACMAN {

Game::Game(AbstractFactory* factory) {
	//make the factory (SDL factory)
	this->factory = factory;

	window = factory->CreateWindow(525, 665);
	window->createWindow();

	background = factory->CreateBackground();

	for (int i = 0; i < 4; i++) {
		Ghosts[i] = factory->CreateGhost(300 - (i * 40), 258, 2, i);
	}

	Pac = factory->CreatePacman(3, 246, 595, 2);

	state = Menu;

	inputhandler = factory->GetInputhandler();
	input = nullptr;

}

void Game::start() {
	//Main loop
	while (state != QuitGame) {
		//Get input and check for quit
		input = inputhandler->getInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			state = QuitGame;
		}

		switch (state) {
		case Menu: {
			window->clearScreen();

			background->visualise(0);
			background->startScreen();

			for (int i = 0; i < 4; i++) {
				Ghosts[i]->move();
				Ghosts[i]->visualise(0);
			}

			window->render();

			if (find(input->inputVector.begin(), input->inputVector.end(),
					InputType::Enter) != input->inputVector.end()) {
				state = Running;
			}
		}
			break;

		case Running: {
			for (InputType dir : input->inputVector) {
				Pac->handleEvent(dir);
			}

			window->clearScreen();

			Pac->move();

			background->visualise(0);

			for (int i = 0; i < 4; i++) {
				if (!Ghosts[i]->start) {
					Ghosts[i]->startMove();
				} else {
					Ghosts[i]->move();
				}

				Ghosts[i]->visualise(0);
			}

			if (Pac->checkCollision()) {
				if (Pac->getLives() > 1) {
					Pac->takeLive();
					state = LostLife;
				} else {
					state = GameOver;
				}
			}

			Pac->visualise(0);
			Pac->showText();

			window->render();
		}
			break;

		case LostLife: {
			window->clearScreen();

			background->visualise(0);

			Pac->visualise(2);

			window->render();

			if (Pac->IsDead) {
				Pac->IsDead = false;
				for (int i = 0; i < 4; i++) {
					Ghosts[i]->start = false;
					Ghosts[i]->defaultPosition(i);
				}
				state = Running;
			}
		}
			break;

		case GameOver: {

			window->clearScreen();

			background->visualise(0);

			for (int i = 0; i < 4; i++) {
				Ghosts[i]->move();
				Ghosts[i]->visualise(0);
			}

			if (!Pac->IsDead) {
				Pac->visualise(2);
			}

			Pac->gameOver();

			window->render();
		}
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

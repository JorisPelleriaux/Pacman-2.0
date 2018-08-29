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
	window = factory->CreateWindow(230, 350);//668, 603
	window->CreateWindow();
	//window->Render();

	//Render the background
	background = factory->CreateBackground();

	//background->Visualise(0);

	//Create Pacman
	Pac = factory->CreatePacman(3, 50, 50, 10);
	//Pac->Visualise();

	lives = 3;

	//Default state
	state = Menu;

	inputhandler = factory->GetInputhandler();
	input = NULL;

}
void Game::Start() {
	//Main loop flag
	bool quit = false;

	/*for (InputType dir : input->inputVector) {
	 Pac->Move(dir);
	 }*/
	double angle = 0;
	while (!quit) {

		input = inputhandler->GetInput();

		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			quit = true;
		}

		//pass the input (left,right,up,down) to the pac
		for (InputType dir : input->inputVector) {
			Pac->Move(dir);
		}

		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Left) != input->inputVector.end()) {
			angle = 180;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Right) != input->inputVector.end()) {
			angle = 0;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Up) != input->inputVector.end()) {
			angle = 270;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Down) != input->inputVector.end()) {
			angle = 90;
		}
		else{

		//1: Clear screen
		//2: Render background
			background->Visualise(angle);
		//3: render dot
			Pac->Visualise(angle);
		//4: update screen


		//background->Visualise(0);
		//window->Render();

		delete input;
		}

	}

}

Game::~Game() {
	delete Pac;
	delete background;

	delete window;

}

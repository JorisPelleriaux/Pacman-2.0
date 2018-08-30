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
	window = factory->CreateWindow(665, 525); //668, 603 //Height, Width
	window->CreateWindow();

	//Render the background
	background = factory->CreateBackground();

	//Create Pacman
	Pac = factory->CreatePacman(3, 251, 595, 10);

	lives = 3;

	//Default state
	state = Menu;

	inputhandler = factory->GetInputhandler();
	input = NULL;

	//Create Ghost
	Ghosts[1] = factory->CreateGhost(300,250,2, 1);


	//Ghosts[2] = factory->CreateGhost(60,60,5, 2);
	//Ghosts[2]->Visualise(0.0);
}
void Game::Start() {
	//Main loop flag
	bool quit = false;

	/*for (InputType dir : input->inputVector) {
	 Pac->Move(dir);
	 }*/
	double angle = 0;
	while (!quit) {
		//cout<<"get input"<<endl;
		input = inputhandler->GetInput();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::Quit) != input->inputVector.end()) {
			quit = true;
		}

		//pass the input (left,right,up,down) to the pac
		for (InputType dir : input->inputVector) {
			Pac->handleEvent(dir);
		}
		Pac->Move();
		Ghosts[1]->Move();
		//Ghosts[2]->Move();
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::DLeft) != input->inputVector.end()) {
			angle = 180;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::DRight) != input->inputVector.end()) {
			angle = 0;
			cout << "input gekregen" << endl;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::DUp) != input->inputVector.end()) {
			angle = 270;
		}
		if (find(input->inputVector.begin(), input->inputVector.end(),
				InputType::DDown) != input->inputVector.end()) {
			angle = 90;
		} else {

			//1: Clear screen
			//2: Render background
			background->Visualise(angle);
			//3: render dot
			Pac->Visualise(angle);
			Ghosts[1]->Visualise(0.0);
			//4: update screen

			//background->Visualise(0);
			window->Render();

			//background->Close();

			//input= NULL;
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

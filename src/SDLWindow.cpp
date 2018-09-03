#include <sdl2/SDL_image.h>
#include <iostream>
#include "SDLWindow.h"
using namespace std;

namespace PACMAN_SDL {
SDLWindow::SDLWindow(int screen_width, int screen_height) :
		Window(screen_width, screen_height) {
	gWindow = nullptr;
	gRenderer = nullptr;
	this->screen_width = screen_width;
	this->screen_height = screen_height;
}
SDLWindow::~SDLWindow() {
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	cout << "Closing Window" << endl;
}

int SDLWindow::createWindow() {
	cout << "Create window" << endl;
	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return 1;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height,
				SDL_WINDOW_SHOWN);
		if (gWindow == nullptr) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			return 1;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				return 1;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					return 1;
				}
				//Initialize SDL_ttf
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n",
					TTF_GetError());
				}
			}
		}
	}
	return 0;
}

void SDLWindow::render() {
	SDL_RenderPresent(gRenderer);
}

void SDLWindow::clearScreen() {
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);
}
}

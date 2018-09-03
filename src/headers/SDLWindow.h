#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>
#include "Window.h"
#include "SDLContext.h"
#include <stdio.h>

using namespace PACMAN;

namespace PACMAN_SDL {
class SDLContext;
class SDLWindow: public Window {
public:
	SDLWindow(int screen_height, int screen_width);
	~SDLWindow();

	int createWindow();
	void render() override;
	void clearScreen() override;

	//The window renderer
	SDL_Renderer* gRenderer;

	//Globally used font
	TTF_Font *gFont = nullptr;

private:
	//The window we'll be rendering to
	SDL_Window* gWindow;

	int screen_width = 0;
	int screen_height = 0;
};
}
#endif /* SDLWINDOW_H_ */

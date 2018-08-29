#ifndef SDLWINDOW_H_
#define SDLWINDOW_H_
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "Window.h"
#include "SDLContext.h"
#include <stdio.h>
#include <string>

using namespace std;

class SDLWindow: public Window {
public:
	SDLWindow(int screen_height, int screen_width);
	~SDLWindow();

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The window renderer
	SDL_Renderer* gRenderer;

	//Current displayed texture
	SDL_Texture* gTexture;

	//Walking animation
	const int ANIMATION_FRAMES = 4;
	SDL_Rect gSpriteClips[4];

	//SDLContext gSpriteSheetTexture;

	int CreateWindow();
	void Render();
};

#endif /* SDLWINDOW_H_ */

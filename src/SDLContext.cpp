#include <stdio.h>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>
#include <fstream>
#include "SDLContext.h"
#include "Game.h"
#include "SDLBackground.h"

namespace PACMAN_SDL {
SDLContext::SDLContext(SDLWindow* window) :
		Context() {
	//The window
	this->window = window;

	//Initialize value's
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;

	sWidth = window->getScreen_width();
	sHeight = window->getScreen_height();
}

SDLContext::~SDLContext() {
	//Deallocate
	free();
}

SDL_Texture* SDLContext::loadFromFile(std::string path) {
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
		IMG_GetError());
	} else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(window->gRenderer,
				loadedSurface);
		if (newTexture == nullptr) {
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		} else {
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	return newTexture;
}

bool SDLContext::loadFromRenderedText(std::string textureText,
		SDL_Color textColor, int size) {
	//Get rid of preexisting texture
	free();

	//Open the font with correct size
	window->gFont = TTF_OpenFont("Media/lazy.ttf", size);
	if (window->gFont == nullptr) {
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(window->gFont,
			textureText.c_str(), textColor);
	if (textSurface == nullptr) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n",
		TTF_GetError());
	} else {
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(window->gRenderer, textSurface);
		if (mTexture == nullptr) {
			printf(
					"Unable to create texture from rendered text! SDL Error: %s\n",
					SDL_GetError());
		} else {
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return mTexture != nullptr;
}

void SDLContext::free() {

	//Free texture if it exists
	if (mTexture != nullptr) {
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

void SDLContext::setColor(Uint8 red, Uint8 green, Uint8 blue) {
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void SDLContext::setBlendMode(SDL_BlendMode blending) {
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void SDLContext::setAlpha(Uint8 alpha) {
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void SDLContext::createPacSprites() {
	gSpriteClips[0].x = 70;
	gSpriteClips[0].y = 35;
	gSpriteClips[0].w = 36;
	gSpriteClips[0].h = 36;

	gSpriteClips[1].x = 35;
	gSpriteClips[1].y = 35;
	gSpriteClips[1].w = 33;
	gSpriteClips[1].h = 36;

	gSpriteClips[2].x = 0;
	gSpriteClips[2].y = 35;
	gSpriteClips[2].w = 33;
	gSpriteClips[2].h = 36;

	gSpriteClips[3].x = 35;
	gSpriteClips[3].y = 35;
	gSpriteClips[3].w = 33;
	gSpriteClips[3].h = 36;

	//Sprites pacman die
	gSpriteClips[4].x = 0;
	gSpriteClips[4].y = 0;
	gSpriteClips[4].w = 35;
	gSpriteClips[4].h = 35;

	gSpriteClips[5].x = 42;
	gSpriteClips[5].y = 0;
	gSpriteClips[5].w = 33;
	gSpriteClips[5].h = 35;

	gSpriteClips[6].x = 81;
	gSpriteClips[6].y = 0;
	gSpriteClips[6].w = 38;
	gSpriteClips[6].h = 35;

	gSpriteClips[7].x = 123;
	gSpriteClips[7].y = 0;
	gSpriteClips[7].w = 38;
	gSpriteClips[7].h = 35;

	gSpriteClips[8].x = 165;
	gSpriteClips[8].y = 0;
	gSpriteClips[8].w = 38;
	gSpriteClips[8].h = 35;

	gSpriteClips[9].x = 206;
	gSpriteClips[9].y = 0;
	gSpriteClips[9].w = 39;
	gSpriteClips[9].h = 35;

	gSpriteClips[10].x = 248;
	gSpriteClips[10].y = 0;
	gSpriteClips[10].w = 38;
	gSpriteClips[10].h = 35;

	gSpriteClips[11].x = 293;
	gSpriteClips[11].y = 0;
	gSpriteClips[11].w = 32;
	gSpriteClips[11].h = 35;

	gSpriteClips[12].x = 335;
	gSpriteClips[12].y = 0;
	gSpriteClips[12].w = 32;
	gSpriteClips[12].h = 35;

	gSpriteClips[13].x = 377;
	gSpriteClips[13].y = 0;
	gSpriteClips[13].w = 32;
	gSpriteClips[13].h = 35;

	gSpriteClips[14].x = 418;
	gSpriteClips[14].y = 0;
	gSpriteClips[14].w = 33;
	gSpriteClips[14].h = 35;

	gSpriteClips[15].x = 462;
	gSpriteClips[15].y = 0;
	gSpriteClips[15].w = 28;
	gSpriteClips[15].h = 35;
}

void SDLContext::createGhostSprites(int number) {
	int x1, x2, y1, y2;
	switch (number) {
	case 0:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 0;
		break;
	case 1:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 34;
		break;
	case 2:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 77;
		break;
	case 3:
		x1 = 156;
		x2 = 182;
		y1 = y2 = 112;
		break;
	default:
		break;
	}

	gSpriteClips_Ghost[number][0].x = x1;
	gSpriteClips_Ghost[number][0].y = y1;
	gSpriteClips_Ghost[number][0].w = 23;
	gSpriteClips_Ghost[number][0].h = 25;

	gSpriteClips_Ghost[number][1].x = x2;
	gSpriteClips_Ghost[number][1].y = y2;
	gSpriteClips_Ghost[number][1].w = 23;
	gSpriteClips_Ghost[number][1].h = 25;
}
void SDLContext::clearScreen() {
	//Clear screen
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(window->gRenderer);
}

void SDLContext::draw(int x, int y, SDL_Texture* texture, SDL_Rect* clip,
		double angle) {

	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(window->gRenderer, texture, clip, &renderQuad, angle, nullptr,
			SDL_FLIP_NONE);
}

void SDLContext::updateScreen() {
	SDL_RenderPresent(window->gRenderer);
}

int SDLContext::getWidth() {
	return mWidth;
}
int SDLContext::getHeight() {
	return mHeight;
}
}

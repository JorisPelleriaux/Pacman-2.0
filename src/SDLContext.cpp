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
	this->window = window;

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
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void SDLContext::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(mTexture, blending);
}

void SDLContext::setAlpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void SDLContext::draw(int x, int y, SDL_Texture* texture, SDL_Rect* clip,
		double angle) {

	//For text rendering
	if (texture == nullptr) {
		texture = mTexture;
	}

	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(window->gRenderer, texture, clip, &renderQuad, angle,
			nullptr, SDL_FLIP_NONE);
}

void SDLContext::clearScreen() {
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(window->gRenderer);
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

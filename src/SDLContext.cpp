#include <stdio.h>
#include "SDLContext.h"
#include "Game.h"

SDLContext::SDLContext(SDLWindow* window) {
	this->window = window;

	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	//Current animation frame
	frame = 0;

}

SDLContext::~SDLContext() {
	//Deallocate
	free();
}

SDL_Texture* SDLContext::loadFromFile(std::string path) {
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
		IMG_GetError());
	} else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(window->gRenderer,
				loadedSurface);
		if (newTexture == NULL) {
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

void SDLContext::free() {

	//Free texture if it exists
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
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


void SDLContext::CreateSprites() {
	window->gSpriteClips[0].x = 0;
	window->gSpriteClips[0].y = 0;
	window->gSpriteClips[0].w = 23;
	window->gSpriteClips[0].h = 23;

	window->gSpriteClips[1].x = 27;
	window->gSpriteClips[1].y = 0;
	window->gSpriteClips[1].w = 23;
	window->gSpriteClips[1].h = 23;

	window->gSpriteClips[2].x = 53;
	window->gSpriteClips[2].y = 0;
	window->gSpriteClips[2].w = 23;
	window->gSpriteClips[2].h = 23;

	window->gSpriteClips[3].x = 76;
	window->gSpriteClips[3].y = 0;
	window->gSpriteClips[3].w = 23;
	window->gSpriteClips[3].h = 23;
}

void SDLContext::ClearScreen() {
	//Clear screen
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(window->gRenderer);
}

void SDLContext::Draw(int x, int y, SDL_Texture* texture, SDL_Rect* clip,
		double angle) {

	if (clip == NULL){
		//Render current frame
		SDL_Rect* currentClip = &window->gSpriteClips[frame / 8];
		clip = currentClip;
	}
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	//SDL_RenderCopy(window->gRenderer, texture, clip, &renderQuad);
	SDL_RenderCopyEx(window->gRenderer, texture, clip, &renderQuad, angle, NULL, SDL_FLIP_NONE);

	//Update screen
	//SDL_RenderPresent(window->gRenderer);

	//Go to next frame
	++frame;

	//Cycle animation
	if (frame / 8 >= window->ANIMATION_FRAMES) {
		frame = 0;
	}

}

void SDLContext::UpdateScreen(){
	SDL_RenderPresent(window->gRenderer);
}

int SDLContext::getWidth() {
	return mWidth;
}

int SDLContext::getHeight() {
	return mHeight;
}

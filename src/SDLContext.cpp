#include <stdio.h>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <fstream>
#include "SDLContext.h"
#include "Game.h"
#include "SDLBackground.h"
SDLContext::SDLContext(SDLWindow* window) :
		Context() {
	this->window = window;

	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	sWidth = window->screen_width;
	sHeight = window->screen_height;

	//Current animation frame
	frame = 0;

	//Current Ghost
	CurrGhost = 0;

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

bool SDLContext::touchesWall(SDL_Rect box, AbsTile* tiles[], bool pacman) {
	//Go through the tiles

	for (int i = 0; i < TOTAL_TILES; ++i) {
		if (tiles[i]->getType() > 15) { //TODO tile path dynamic
			if (checkCollision(box, tiles[i]->getBox()) && pacman) {
				tiles[i]->setType(15);
				window->SetScore(5);
			}
		}
		//If the tile is a wall type tile
		if ((tiles[i]->getType() < 15) //TODO tile path dynamic
		&& (tiles[i]->getType() >= 0)) {
			//If the collision box touches the wall tile
			if (checkCollision(box, tiles[i]->getBox())) {
				return true;
			}
		}
	}

	//If no wall tiles were touched
	return false;
}

bool SDLContext::checkCollision(SDL_Rect a, RECT b) {
	//The sides of the rectangles
	int leftA;
	int rightA;
	int topA;
	int bottomA;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//If any of the sides from A are outside of B
	if (bottomA <= b.top) {
		return false;
	}

	if (topA >= b.bottom) {
		return false;
	}

	if (rightA <= b.left) {
		return false;
	}

	if (leftA >= b.right) {
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

void SDLContext::CreatePacSprites() {
	gSpriteClips[0].x = 0;
	gSpriteClips[0].y = 0;
	gSpriteClips[0].w = 35;
	gSpriteClips[0].h = 35;

	gSpriteClips[1].x = 41;
	gSpriteClips[1].y = 0;
	gSpriteClips[1].w = 35;
	gSpriteClips[1].h = 35;

	gSpriteClips[2].x = 81;
	gSpriteClips[2].y = 0;
	gSpriteClips[2].w = 35;
	gSpriteClips[2].h = 35;

	gSpriteClips[3].x = 117;
	gSpriteClips[3].y = 0;
	gSpriteClips[3].w = 35;
	gSpriteClips[3].h = 35;

	gSpriteClips[4].x = 117;
	gSpriteClips[4].y = 0;
	gSpriteClips[4].w = 35;
	gSpriteClips[4].h = 35;
}

void SDLContext::CreateGhostSprites(int number) {
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
void SDLContext::ClearScreen() {
	//Clear screen
	SDL_SetRenderDrawColor(window->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(window->gRenderer);
}

void SDLContext::Draw(int x, int y, SDL_Texture* texture, SDL_Rect* clip,
		double angle) {

	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	//SDL_RenderCopy(window->gRenderer, texture, clip, &renderQuad);
	SDL_RenderCopyEx(window->gRenderer, texture, clip, &renderQuad, angle, NULL,
			SDL_FLIP_NONE);

	//Update screen
	//SDL_RenderPresent(window->gRenderer);

}

void SDLContext::UpdateScreen() {
	SDL_RenderPresent(window->gRenderer);
}

int SDLContext::getWidth() {
	return mWidth;
}

int SDLContext::getHeight() {
	return mHeight;
}

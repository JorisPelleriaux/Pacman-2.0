#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Tile.h"
#include "SDLBackground.h"
using namespace std;

namespace PACMAN_SDL {
SDLBackground::SDLBackground(SDLContext* context) :
		Background() {
	this->context = context;

	image = context->loadFromFile("Media/Tile.png");
	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	}

	if (!setTiles()) {
		printf("Failed to set the tiles!\n");
	}
}
SDLBackground::~SDLBackground() {
	context->free();

	//Deallocate tiles
	for (int i = 0; i < TOTAL_TILES; ++i) {
		if (context->tileSet[i] == nullptr) {
			context->tileSet[i] = nullptr;
		}
	}
}

void SDLBackground::visualise(int State) {
	for (int i = 0; i < TOTAL_TILES; ++i) {
		context->draw(context->tileSet[i]->getBox().left,
				context->tileSet[i]->getBox().top, image,
				&gTileClips[context->tileSet[i]->getType()], 0.0);
	}
}

bool SDLBackground::setTiles() {
	bool tilesLoaded = true;

	//The tile offsets
	int x = 0, y = 0;

	std::ifstream map("Media/lazy.map");

	if (!map.is_open()) {
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	} else {
		for (int i = 0; i < TOTAL_TILES; ++i) {
			int tileType = -1;

			map >> tileType;

			if (map.fail()) {
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			if ((tileType >= 0) && (tileType < 20)) {
				context->tileSet[i] = new AbsTile(x, y, tileType);
			} else {
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			if (x >= context->sWidth) {
				x = 0;
				y += TILE_HEIGHT;
			}
		}

		//Clip the sprite sheet
		if (tilesLoaded) {
			gTileClips[TILE_HORIZONTAL].x = 1;
			gTileClips[TILE_HORIZONTAL].y = 1;
			gTileClips[TILE_HORIZONTAL].w = TILE_WIDTH;
			gTileClips[TILE_HORIZONTAL].h = TILE_HEIGHT;

			gTileClips[TILE_LEFT].x = 38;
			gTileClips[TILE_LEFT].y = 1;
			gTileClips[TILE_LEFT].w = TILE_WIDTH;
			gTileClips[TILE_LEFT].h = TILE_HEIGHT;

			gTileClips[TILE_RIGHT].x = 75;
			gTileClips[TILE_RIGHT].y = 1;
			gTileClips[TILE_RIGHT].w = TILE_WIDTH;
			gTileClips[TILE_RIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_TOPRIGHT].x = 112;
			gTileClips[TILE_TOPRIGHT].y = 1;
			gTileClips[TILE_TOPRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_TOPRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_CENTERDOWN].x = 149;
			gTileClips[TILE_CENTERDOWN].y = 1;
			gTileClips[TILE_CENTERDOWN].w = TILE_WIDTH;
			gTileClips[TILE_CENTERDOWN].h = TILE_HEIGHT;

			gTileClips[TILE_TOPLEFT].x = 186;
			gTileClips[TILE_TOPLEFT].y = 1;
			gTileClips[TILE_TOPLEFT].w = TILE_WIDTH;
			gTileClips[TILE_TOPLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_TOP].x = 1;
			gTileClips[TILE_TOP].y = 37;
			gTileClips[TILE_TOP].w = TILE_WIDTH;
			gTileClips[TILE_TOP].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOMRIGHT].x = 38;
			gTileClips[TILE_BOTTOMRIGHT].y = 37;
			gTileClips[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_CENTERUP].x = 75;
			gTileClips[TILE_CENTERUP].y = 37;
			gTileClips[TILE_CENTERUP].w = TILE_WIDTH;
			gTileClips[TILE_CENTERUP].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOMLEFT].x = 112;
			gTileClips[TILE_BOTTOMLEFT].y = 37;
			gTileClips[TILE_BOTTOMLEFT].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_VERTICAL].x = 149;
			gTileClips[TILE_VERTICAL].y = 37;
			gTileClips[TILE_VERTICAL].w = TILE_WIDTH;
			gTileClips[TILE_VERTICAL].h = TILE_HEIGHT;

			gTileClips[TILE_BOTTOM].x = 186;
			gTileClips[TILE_BOTTOM].y = 37;
			gTileClips[TILE_BOTTOM].w = TILE_WIDTH;
			gTileClips[TILE_BOTTOM].h = TILE_HEIGHT;

			gTileClips[TILE_CENTERLEFT].x = 1;
			gTileClips[TILE_CENTERLEFT].y = 73;
			gTileClips[TILE_CENTERLEFT].w = TILE_WIDTH;
			gTileClips[TILE_CENTERLEFT].h = TILE_HEIGHT;

			gTileClips[TILE_FOOD3].x = 38;
			gTileClips[TILE_FOOD3].y = 73;
			gTileClips[TILE_FOOD3].w = TILE_WIDTH;
			gTileClips[TILE_FOOD3].h = TILE_HEIGHT;

			gTileClips[TILE_CENTERRIGHT].x = 75;
			gTileClips[TILE_CENTERRIGHT].y = 73;
			gTileClips[TILE_CENTERRIGHT].w = TILE_WIDTH;
			gTileClips[TILE_CENTERRIGHT].h = TILE_HEIGHT;

			gTileClips[TILE_PATH].x = 186;
			gTileClips[TILE_PATH].y = 73;
			gTileClips[TILE_PATH].w = TILE_WIDTH;
			gTileClips[TILE_PATH].h = TILE_HEIGHT;

			gTileClips[TILE_FOOD1].x = 112;
			gTileClips[TILE_FOOD1].y = 73;
			gTileClips[TILE_FOOD1].w = TILE_WIDTH;
			gTileClips[TILE_FOOD1].h = TILE_HEIGHT;

			gTileClips[TILE_FOOD2].x = 149;
			gTileClips[TILE_FOOD2].y = 73;
			gTileClips[TILE_FOOD2].w = TILE_WIDTH;
			gTileClips[TILE_FOOD2].h = TILE_HEIGHT;
		}
	}

	//Close the file
	map.close();

	return tilesLoaded;
}

void SDLBackground::startScreen() {
	std::string Text = "Press enter to start";
	SDL_Color textColor = { 255, 255, 255 };

	if (!context->loadFromRenderedText(Text, textColor, 50)) {
		printf("Failed to render text texture!\n");
	}

	context->draw((context->sWidth - context->getWidth()) / 2,
			(context->sHeight - context->getHeight()) / 2);
}
}

#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include "SDLBackground.h"
#include <stdio.h>
#include <string>
#include <fstream>
#include "Tile.h"
using namespace std;

namespace PACMAN_SDL {
SDLBackground::SDLBackground(SDLContext* context) :
		Background() {
	this->context = context;

	//Load tile texture
	image = context->loadFromFile("Media/Tile.png");
	if (image == nullptr) {
		printf("Failed to load texture image!\n");
	}
	//Set Tiles
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
	//Render Tiles
	for (int i = 0; i < TOTAL_TILES; ++i) {
		context->draw(context->tileSet[i]->getBox().left,
				context->tileSet[i]->getBox().top, image,
				&gTileClips[context->tileSet[i]->getType()], 0.0);
	}
}

bool SDLBackground::setTiles() {
	//Success flag
	bool tilesLoaded = true;
	//The tile offsets
	int x = 0, y = 0;
	//Open the map
	std::ifstream map("Media/lazy.map");

	//If the map couldn't be loaded
	if (!map.is_open()) {
		printf("Unable to load map file!\n");
		tilesLoaded = false;
	} else {
		//Initialize the tiles
		for (int i = 0; i < TOTAL_TILES; ++i) {
			//Determines what kind of tile will be made
			int tileType = -1;

			//Read tile from map file
			map >> tileType;

			//If the was a problem in reading the map
			if (map.fail()) {
				//Stop loading map
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//If the number is a valid tile number
			if ((tileType >= 0) && (tileType < 20)) {
				context->tileSet[i] = new AbsTile(x, y, tileType);
			}
			//If we don't recognize the tile type
			else {
				//Stop loading map
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}

			//Move to next tile spot
			x += TILE_WIDTH;

			//If we've gone too far
			if (x >= context->sWidth) {
				//Move back
				x = 0;

				//Move to the next row
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

			gTileClips[TILE_CENTER].x = 38;
			gTileClips[TILE_CENTER].y = 73;
			gTileClips[TILE_CENTER].w = TILE_WIDTH;
			gTileClips[TILE_CENTER].h = TILE_HEIGHT;

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

	//If the map was loaded fine
	return tilesLoaded;
}

void SDLBackground::startScreen() {
	//Render text
	std::string Text = "Press enter to start";
	SDL_Color textColor = { 255, 255, 255 };
	if (!context->loadFromRenderedText(Text, textColor, 50)) {
		printf("Failed to render text texture!\n");
	}
	context->draw((context->sWidth - context->getWidth()) / 2, (context->sHeight - context->getHeight()) / 2, context->mTexture);
}
}

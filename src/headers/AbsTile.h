#ifndef HEADERS_ABSTILE_H_
#define HEADERS_ABSTILE_H_
#include <string>
#include <windef.h>
using namespace std;

class AbsTile {
public:

	//Initializes position and type
	AbsTile(int x, int y, int tileType);

	//Get the tile type
	int getType();

	//Set the tile type
	void setType(int type);

	//virtual void render()=0;
	//Get the collision box
	RECT getBox();

	//Tile constants
	static const int TILE_WIDTH = 35;
	static const int TILE_HEIGHT = 35;
	static const int TOTAL_TILES = 192;
	static const int TOTAL_TILE_SPRITES = 16;

private:
	//The attributes of the tile
	RECT mBox;

	//The tile type
	int mType =0;

};
#endif /* HEADERS_ABSTILE_H_ */

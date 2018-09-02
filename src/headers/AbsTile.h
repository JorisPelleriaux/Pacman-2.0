#ifndef HEADERS_ABSTILE_H_
#define HEADERS_ABSTILE_H_
#include <windef.h>

namespace PACMAN {
class AbsTile {
public:
	AbsTile(int x, int y, int tileType);	//Initializes position and type
	int getType();							//Get the tile type
	void setType(int type);					//Set the tile type (after eating food)
	RECT getBox();							//Get the collision box

private:
	//Tile constants
	const int TILE_WIDTH = 35;
	const int TILE_HEIGHT = 35;

	//Collision box of a tile
	RECT mBox;

	//The tile type
	int mType = 0;
};
}
#endif /* HEADERS_ABSTILE_H_ */

#ifndef HEADERS_ABSTILE_H_
#define HEADERS_ABSTILE_H_
#include <windef.h>

namespace PACMAN {
class AbsTile {
public:
	AbsTile(int x, int y, int tileType);
	int getType();
	void setType(int type);
	RECT getBox();

private:
	const int TILE_WIDTH = 34;
	const int TILE_HEIGHT = 34;

	//Collision box of the tile
	RECT mBox;

	int mType = 0;
};
}
#endif /* HEADERS_ABSTILE_H_ */

#ifndef HEADERS_CONTEXT_H_
#define HEADERS_CONTEXT_H_
#include <string>
#include <windef.h>
#include "AbsTile.h"

namespace PACMAN {

//Helper class to check collisions and pass variables
class Context {
public:
	Context();
	virtual ~Context();
	bool checkcollision(RECT a, RECT b);
	bool touchesWall(RECT box, bool pacman);

	AbsTile* tileSet[285];

	//Possition of all the ghosts
	RECT ghosts[4];

	int currGhost = 0;

	//score of Pacman
	int score = 0;

	//Screen dimensions
	int sWidth = 0, sHeight = 0;
};
}
#endif /* HEADERS_CONTEXT_H_ */

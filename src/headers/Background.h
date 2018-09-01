#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <iostream>
#include "Entity.h"
#include "Tile.h"
using namespace std;

namespace PACMAN {
class Background: public Entity {
public:
	Background();
	virtual ~Background();
	virtual void StartScreen() = 0;
};
}
#endif /* BACKGROUND_H_ */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <iostream>
#include "Entity.h"
#include "Tile.h"
using namespace std;

class Background: public Entity {
public:
	Background();
	virtual ~Background();
	void Move();
};

#endif /* BACKGROUND_H_ */

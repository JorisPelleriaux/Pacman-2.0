#ifndef HEADERS_GHOST_H_
#define HEADERS_GHOST_H_
#include <string>
#include "Entity.h"
#include "Context.h"

namespace PACMAN {
class AbstractFactory;

class Ghost: public Entity {
public:
	Ghost(AbstractFactory* factory, Context* context, int x, int y,
			int movespeed);
	virtual ~Ghost();
	void move() override;
	void startMove();
	void defaultPosition(int Ghost);
	RECT getBox();

	//Check ghosts start move complete
	bool start = false;

private:
	AbstractFactory* factory;
	Context* context;

	const int GHOST_WIDTH = 23;
	const int GHOST_HEIGHT = 23;

	int ghost_VEL = 0;

	//Collision box of the Ghost
	RECT mBox;

	// movement of each ghost 0:right ; 1:left ; 2:down ; 3:up
	int num[4] = { 0, 1, 2, 3 };
	int prevNum[4];
	int tempPosX[4];
	int tempPosY[4];
};
}
#endif /* HEADERS_GHOST_H_ */

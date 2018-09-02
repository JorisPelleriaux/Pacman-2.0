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
	void move() override;		//How to move the ghosts
	RECT getBox();				//Get the collision box
	int getCurrentGhost();		//get current ghost
	void startMove();			//Startmove to get out of the box
	void defaultPosition(int Ghost);	//Set Ghosts to default position

	bool start = false;	//Ghosts start move

private:
	AbstractFactory* factory;
	Context* context;

	//The dimensions of the Ghost
	const int GHOST_WIDTH = 23;
	const int GHOST_HEIGHT = 23;

	//Maximum axis velocity of the Ghost
	int ghost_VEL = 0;	//Set later in game

	//Collision box of the Ghost
	RECT mBox;

	int num[4] = { 0, 1, 2, 3 };//Start movement 0:right ; 1:left ; 2:down ; 3:up
	int prevNum[4];
	int tempPosX[4];
	int tempPosY[4];
};
}
#endif /* HEADERS_GHOST_H_ */

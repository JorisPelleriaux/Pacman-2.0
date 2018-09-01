#ifndef HEADERS_GHOST_H_
#define HEADERS_GHOST_H_

#include <string>
#include "Entity.h"
#include "Context.h"
using namespace std;

class AbstractFactory;
//required

class Ghost: public Entity {
public:
	Ghost(AbstractFactory* factory, Context* context, int x, int y,
			int movespeed);
	virtual ~Ghost();
	void Move() override;
	void StartMove(int Ghost);
	//The dimensions of the Ghost
	static const int Ghost_WIDTH = 23;
	static const int Ghost_HEIGHT = 23;

	//Collision box of the Ghost
	RECT Box;
	//Maximum axis velocity of the Ghost
	int Ghost_VEL = 0;	//Set later in game

	bool Start=false;	//Ghosts start move
private:
	AbstractFactory* factory;
	Context* context;


	int counter[4];
	int Num[4] = {0,1,2,3};	//Start movement 0:right ; 1:left ; 2:down ; 3:up
	int PrevNum[4];
	int tempPosX[4];
	int tempPosY[4];


};
#endif /* HEADERS_GHOST_H_ */

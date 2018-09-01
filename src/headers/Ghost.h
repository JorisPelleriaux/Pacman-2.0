#ifndef HEADERS_GHOST_H_
#define HEADERS_GHOST_H_

#include <string>
#include "Entity.h"
#include "Context.h"
using namespace std;

class AbstractFactory;	//required

class Ghost: public Entity {
public:
	Ghost(AbstractFactory* factory, Context* context, int x, int y, int movespeed);
	virtual ~Ghost();
	void Move() override;
	//The dimensions of the Ghost
	static const int Ghost_WIDTH = 23;
	static const int Ghost_HEIGHT = 23;

	//Collision box of the Ghost
	RECT Box;
	int Ghost_VEL = 2;
protected:

private:
	AbstractFactory* factory;
	Context* context;
	//Maximum axis velocity of the Ghost

	int XVEL;
	int YVEL;
	int counter = 0;
	int Num = 0;
	int PrevNum = 0;
};
#endif /* HEADERS_GHOST_H_ */

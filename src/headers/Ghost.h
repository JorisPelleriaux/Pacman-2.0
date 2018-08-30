#ifndef HEADERS_GHOST_H_
#define HEADERS_GHOST_H_

#include <string>
#include "Entity.h"
using namespace std;

class AbstractFactory;

class Ghost: public Entity {
public:
	Ghost(AbstractFactory* factory, int x, int y, int movespeed);
	virtual ~Ghost();

	//The dimensions of the Ghost
	static const int Ghost_WIDTH = 23;
	static const int Ghost_HEIGHT = 23;
	RECT Box;	//Position
protected:

private:
	AbstractFactory* factory;

	//Maximum axis velocity of the Ghost
	int Ghost_VEL = 2;
};
#endif /* HEADERS_GHOST_H_ */

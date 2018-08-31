#ifndef HEADERS_GHOST_H_
#define HEADERS_GHOST_H_

#include <string>
#include "Entity.h"
#include "Context.h"
using namespace std;

class AbstractFactory;

class Ghost: public Entity {
public:
	Ghost(AbstractFactory* factory, Context* context, int x, int y, int movespeed);
	virtual ~Ghost();
	void Move(RECT box) override;
	//The dimensions of the Ghost
	static const int Ghost_WIDTH = 23;
	static const int Ghost_HEIGHT = 23;
	RECT Box;	//Position
protected:

private:
	AbstractFactory* factory;
	Context* context;
	//Maximum axis velocity of the Ghost
	int Ghost_VEL = 2;
};
#endif /* HEADERS_GHOST_H_ */

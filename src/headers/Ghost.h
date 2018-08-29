/*
 * Ghost.h
 *
 *  Created on: 29 aug. 2018
 *      Author: joris
 */

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
	void Update();
	void Move();
	int GetLives();
	//Maximum axis velocity of the Ghost
	static const int Ghost_VEL = 5;

	//The dimensions of the Pacman
	static const int Ghost_WIDTH = 23;
	static const int Ghost_HEIGHT = 23;
protected:
	int x;
	int y;
	int movespeed;
private:
	AbstractFactory* factory;

};
#endif /* HEADERS_GHOST_H_ */

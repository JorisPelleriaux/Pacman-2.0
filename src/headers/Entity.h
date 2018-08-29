/*
 * Entity.h
 *
 *  Created on: 5 mrt. 2018
 *      Author: joris
 */

#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_
#include "Input.h"
#include "Tile.h"
using namespace std;

class Entity {
public:
	//entity heeft default eigenschappen zoals positie, grootte, snelheid
	Entity(int x, int y, int width, int height, int movespeed);
	virtual ~Entity();

	virtual void Update()=0;

	//entity weergeven
	virtual void Visualise(double angle)=0;

	//entity bewegen
	virtual void Move();

private:
	int movespeed;
};

#endif /* HEADERS_ENTITY_H_ */

#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_
#include "Input.h"
#include "Tile.h"
#include<windef.h>
using namespace std;

class Entity {
public:
	//Defenition of entity
	Entity(int x, int y, int width, int height, int movespeed);
	virtual ~Entity();
	virtual void Visualise(int State)=0;	//Visualise entity
	virtual void Move(RECT box)=0;	//Move entity

	bool CheckCollisions(RECT a, RECT b);	//Check for collision

private:
	int movespeed;
	RECT rect;
};

#endif /* HEADERS_ENTITY_H_ */

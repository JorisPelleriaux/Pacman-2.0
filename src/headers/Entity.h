#ifndef HEADERS_ENTITY_H_
#define HEADERS_ENTITY_H_
#include "Input.h"
#include "Tile.h"
#include<windef.h>
using namespace std;

namespace PACMAN {

//Base class for entities to use as a template.
class Entity {
public:
	Entity(int x, int y, int width, int height, int movespeed);
	virtual ~Entity();
	virtual void visualise(int State)=0;
	virtual void move()=0;

private:
	int movespeed;
};
}
#endif /* HEADERS_ENTITY_H_ */

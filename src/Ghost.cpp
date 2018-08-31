#include "Ghost.h"
#include "AbstractFactory.h"
#include <iostream>

using namespace std;

//Constructor sets required parameters
Ghost::Ghost(AbstractFactory* factory, Context* context, int x, int y, int movespeed) :
		Entity(x, y, 20, 20, movespeed) {
	this->factory = factory;
	this->Box.left = x;
	this->Box.top = y;
	this->Box.right = Box.left + Ghost_WIDTH;
	this->Box.bottom = Box.top + Ghost_HEIGHT;
	this->Ghost_VEL = movespeed;
	this->context = context;

}
Ghost::~Ghost() {
}

void Ghost::Move(RECT box) {
//Define how the ghost should move

	Box.left += Ghost_VEL;
//	cout<<context->AbstileSet[1]->getBox().left<<endl;
	/*if (context->touchesWall(Box)){
		cout<<"Wall"<<endl;
	}*/
	/*this->Box.right = Box.left + Ghost_WIDTH;
	this->Box.bottom = Box.top + Ghost_HEIGHT;

	bool Collision = context->checkcollision(Box, box);
	if (Collision){
		cout<<"Leven kwijt"<<endl;
	}


	Box.left += Ghost_VEL;
	if (Box.left >= 330) {
		Box.left -= Ghost_VEL;
		Box.top += Ghost_VEL;
	}
	if (Box.top >= 280){
		Box.top -= Ghost_VEL;
		Ghost_VEL = Ghost_VEL * (-1);
		Box.left += Ghost_VEL;
	}
	if (Box.left <= 170){
		Box.left -= Ghost_VEL;
		Ghost_VEL = Ghost_VEL * (-1);
		Box.top -= Ghost_VEL;
	}
*/
}
void Ghost::testmethod(){

}

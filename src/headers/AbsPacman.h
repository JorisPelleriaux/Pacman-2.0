#ifndef HEADERS_ABSPACMAN_H_
#define HEADERS_ABSPACMAN_H_

#include <string>
#include "Entity.h"
#include "Input.h"

using namespace std;

class AbstractFactory;

class AbsPacman: public Entity {
public:
	AbsPacman(AbstractFactory* factory, int lives, int x, int y, int movespeed);
	virtual ~AbsPacman();
	void Update();
	void Move();
	virtual void handleEvent(InputType dir)=0;
	int GetLives();
	//Maximum axis velocity of the Pacman
	static const int PAC_VEL = 5;

	//The dimensions of the Pacman
	static const int PAC_WIDTH = 35;
	static const int PAC_HEIGHT = 35;
protected:
	int x;
	int y;
	int movespeed;
private:
	AbstractFactory* factory;
	Input* inputHandler;
	int lives;

};

#endif /* HEADERS_ABSPACMAN_H_ */

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

	void handleEvent(InputType dir);
	int GetLives();

	//The dimensions of the Pacman
	static const int PAC_WIDTH = 34;
	static const int PAC_HEIGHT = 35;

	RECT box;	//Position
protected:
	int movespeed;	//May be removed
	int XVEL = 0;	//X velocity of the Pacman
	int YVEL = 0;	//Y velocity of the Pacman
	int sAngle = 0;	//Angle of the pacman
private:
	AbstractFactory* factory;
	Input* inputHandler;
	int lives;
	int score = 0;


	const int PAC_VEL = 5;	//Maximum axis velocity of the Pacman

};

#endif /* HEADERS_ABSPACMAN_H_ */

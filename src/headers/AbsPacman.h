#ifndef HEADERS_ABSPACMAN_H_
#define HEADERS_ABSPACMAN_H_
#include "Entity.h"

namespace PACMAN {
class AbstractFactory;

class AbsPacman: public Entity {
public:
	AbsPacman(AbstractFactory* factory, Context* context, int lives, int x,
			int y, int movespeed);
	virtual ~AbsPacman();
	virtual void showText() = 0;
	virtual void gameOver() = 0;
	void handleEvent(InputType dir);
	void setStartPosition();
	void takeLive();
	void move() override;
	int getLives();
	int getScore();
	int getAngle();
	RECT getBox();

	bool checkCollision();

	//Check if dead-animation is complete.
	bool IsDead = false;

private:
	AbstractFactory* factory;
	Input* inputHandler;
	Context* context;

	const int PAC_WIDTH = 33;
	const int PAC_HEIGHT = 34;
	const int PAC_VEL = 3;

	int lives;
	int score = 0;
	int xVel = 0, yVel = 0;
	int sAngle = 0;

	//Start position
	int x, y;

	//Collision box of the Pacman
	RECT mBox;
};
}
#endif /* HEADERS_ABSPACMAN_H_ */

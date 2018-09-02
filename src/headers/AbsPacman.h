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
	void handleEvent(InputType dir);		//handle the input
	int getLives();							//Return lives
	int getScore();							//Return score
	int getAngle();							//Return angle of the pacman
	RECT getBox();							//Get the collision box
	void takeLive();						//Take a live from the pac
	bool checkCollision();					//Check collision with ghosts
	void setStartPosition();				//Set pacman back to start position
	virtual void showText() = 0;		//Show the score and lives on the screen
	virtual void gameOver() = 0;			//Show gameover on the screen
	void move() override;					//How the pacman moves

	bool IsDead = false;				//Check if dead-animation is complete

protected:
	int movespeed;	//May be removed

private:
	AbstractFactory* factory;
	Input* inputHandler;
	Context* context;

	//Collision box of the Pacman
	RECT mBox;

	//The dimensions of the pacman
	const int PAC_WIDTH = 33;
	const int PAC_HEIGHT = 34;

	const int PAC_VEL = 3;	//Maximum axis velocity of the Pacman

	int lives;				//Set later
	int score = 0;			//Score
	int x, y;				//Start position

	int xVel = 0, yVel = 0;	//X,Y velocity of the Pacman
	int sAngle = 0;			//Angle of the pacman (direction)

};
}
#endif /* HEADERS_ABSPACMAN_H_ */

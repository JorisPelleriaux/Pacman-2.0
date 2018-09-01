#ifndef HEADERS_ABSPACMAN_H_
#define HEADERS_ABSPACMAN_H_

#include <string>
#include "Entity.h"
#include "Input.h"

using namespace std;


namespace PACMAN {
class AbstractFactory;
class AbsPacman: public Entity {
public:
	AbsPacman(AbstractFactory* factory, Context* context, int lives, int x,
			int y, int movespeed);
	virtual ~AbsPacman();

	void handleEvent(InputType dir);	//handle the input
	int GetLives();						//Return lives
	int GetScore();						//Return score
	void TakeLive();					//Take a live from the pac
	bool CheckCollision();				//Check collision with ghosts
	virtual void SetStartPosition() = 0;	//Set pacman back to start position
	virtual void ShowText() = 0;		//Show the score and lives on the screen
	virtual void GameOver() = 0;		//Show the score and lives on the screen
	//void Move(RECT box) override;

	//The dimensions of the Pacman
	static const int PAC_WIDTH = 33;
	static const int PAC_HEIGHT = 34;

	bool IsDead = false;				//Check if dead-animation is complete

	RECT Pbox;	//Position
protected:
	int movespeed;	//May be removed
	int XVEL = 0;	//X velocity of the Pacman
	int YVEL = 0;	//Y velocity of the Pacman
	int sAngle = 0;	//Angle of the pacman

private:
	AbstractFactory* factory;
	Input* inputHandler;
	Context* context;
	int lives;
	int score = 0;

	const int PAC_VEL = 5;	//Maximum axis velocity of the Pacman

};
}
#endif /* HEADERS_ABSPACMAN_H_ */

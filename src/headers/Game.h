#ifndef HEADERS_GAME_H_
#define HEADERS_GAME_H_
#include <string>
#include "Window.h"
#include "Background.h"
#include "Input.h"
#include "AbsPacman.h"
using namespace std;

class AbstractFactory;

//Possible states of the game
enum GameState {
	Menu, Running, GameOver, QuitGame, NoState
};

class Game {
public:
	Game(AbstractFactory* factory);
	~Game();
	void Start();

protected:
	BaseInput* input;
	AbsPacman* Pac;

private:
	AbstractFactory* factory;

	Window* window;
	GameState state;
	Background* background;
	Input* inputhandler;
	int lives;
};
#endif /* HEADERS_GAME_H_ */

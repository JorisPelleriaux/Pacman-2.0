#ifndef HEADERS_GAME_H_
#define HEADERS_GAME_H_
#include <string>
#include "Window.h"
#include "Background.h"
#include "Input.h"
#include "AbsPacman.h"
#include "Ghost.h"
using namespace std;

namespace PACMAN {
class AbstractFactory;
class Ghost;
//Possible states of the game
enum GameState {
	Menu, Running, GameOver, QuitGame, LostLife, NoState
};

class Game {
public:
	Game(AbstractFactory* factory);
	~Game();
	void Start();

protected:
	BaseInput* input;
	AbsPacman* Pac;
	Ghost* Ghosts[4];

private:
	AbstractFactory* factory;

	Window* window;
	GameState state;
	Background* background;
	Input* inputhandler;
};
}
#endif /* HEADERS_GAME_H_ */

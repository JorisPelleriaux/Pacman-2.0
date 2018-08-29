#ifndef HEADERS_SDLFACTORY_H_
#define HEADERS_SDLFACTORY_H_
#include "AbstractFactory.h"
#include "SDLPacman.h"
#include "SDLWindow.h"
#include "SDLBackground.h"
#include "SDLInput.h"
using namespace std;

class SDLFactory: public AbstractFactory {
public:
	SDLFactory();
	~SDLFactory() override;
	AbsPacman* CreatePacman(int lives, int x, int y, int movespeed) override;
	Window* CreateWindow(int screen_width, int screen_height) override;
	Background* CreateBackground() override;
	Input* GetInputhandler() override;

private:
	Input* inputHandler;
	SDLContext* Paccontext;
	SDLContext* Tilecontext;


};

#endif /* HEADERS_SDLFACTORY_H_ */

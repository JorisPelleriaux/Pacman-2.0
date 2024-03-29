#ifndef HEADERS_SDLFACTORY_H_
#define HEADERS_SDLFACTORY_H_
#include "SDLPacman.h"
#include "SDLWindow.h"
#include "SDLBackground.h"
#include "SDLInput.h"
#include "SDLGhost.h"
#include "AbstractFactory.h"

using namespace PACMAN;

namespace PACMAN_SDL {
class SDLFactory: public AbstractFactory {
public:
	SDLFactory();
	~SDLFactory() override;
	AbsPacman* CreatePacman(int lives, int x, int y, int movespeed) override;
	Window* CreateWindow(int screen_width, int screen_height) override;
	Background* CreateBackground() override;
	Input* GetInputhandler() override;
	Ghost* CreateGhost(int x, int y, int movespeed, int number) override;

private:
	Input* inputHandler;
	SDLContext* Gamecontext;
};
}
#endif /* HEADERS_SDLFACTORY_H_ */

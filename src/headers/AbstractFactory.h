#ifndef HEADERS_ABSTRACTFACTORY_H_
#define HEADERS_ABSTRACTFACTORY_H_
using namespace std;

#include "AbsPacman.h"
#include "Window.h"
#include "Background.h"
#include "input.h"

class AbstractFactory {
public:
	virtual ~AbstractFactory() {
	}
	virtual AbsPacman *CreatePacman(int lives, int x, int y, int movespeed)=0;
	virtual Window *CreateWindow(int screen_width, int screen_height)=0;
	virtual Background *CreateBackground()=0;
	virtual Input *GetInputhandler()=0;

};

#endif /* HEADERS_ABSTRACTFACTORY_H_ */

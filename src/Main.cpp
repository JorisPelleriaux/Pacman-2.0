//============================================================================
// Name        : Pacman.cpp
// Author      : Joris Pelleriaux
// Version     :
// Copyright   : Your copyright notice
// Description : Pacman game c++
//============================================================================

#include <iostream>
#include "Game.h"
#include "SDLFactory.h"
#include "AbstractFactory.h"

using namespace PACMAN;
using namespace PACMAN_SDL;

int main( int argc, char* argv[] )
{
    AbstractFactory* factory =new SDLFactory();
    Game* game=new Game(factory);
    game->start();
    delete game;
    delete factory;
    return 0;
}


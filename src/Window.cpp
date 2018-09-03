#include "Window.h"
#include <iostream>

namespace PACMAN {
Window::Window(int screen_width, int screen_height) {
	this->screen_width = screen_width;
	this->screen_height = screen_height;
}
Window::~Window() {
}

int Window::getScreen_width() {
	return screen_width;
}

int Window::getScreen_height() {
	return screen_height;
}
}

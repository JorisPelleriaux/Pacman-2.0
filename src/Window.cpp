#include "Window.h"
#include <iostream>

Window::Window(int screen_width, int screen_height) {
	this->screen_height = screen_height;
	this->screen_width = screen_width;
	score = 0;

}
Window::~Window() {
	// TODO Auto-generated destructor stub
}

void Window::SetScore(int score){
	this->score += score;
	cout<<"score: ";
	cout<<this->score<<endl;
}

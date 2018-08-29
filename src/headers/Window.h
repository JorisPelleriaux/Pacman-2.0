#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_
using namespace std;

class Window {
public:
	Window();
	Window(int Screen_height, int Screen_width);
	virtual ~Window();

	virtual int CreateWindow()=0;
	virtual void Render()=0;

	//DOET NIETS
	int screen_height = 480;
	int screen_width = 640;

};

#endif /* WINDOW_H_ */

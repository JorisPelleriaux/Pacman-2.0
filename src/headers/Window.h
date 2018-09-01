#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_
using namespace std;

namespace PACMAN {
class Window {
public:
	Window();
	Window(int Screen_width, int Screen_height);
	virtual ~Window();

	virtual int CreateWindow()=0;
	virtual void Render()=0;
	virtual void ClearScreen()=0;

	int screen_height = 0;
	int screen_width = 0;

private:

};
}
#endif /* WINDOW_H_ */

#pragma once
#ifndef WINDOW_H_
#define WINDOW_H_
using namespace std;

class Window {
public:
	Window();
	Window(int Screen_width, int Screen_height);
	virtual ~Window();

	virtual int CreateWindow()=0;
	virtual void Render()=0;
	void SetScore(int score);

	int screen_height = 0;
	int screen_width = 0;

private:
	int score;

};

#endif /* WINDOW_H_ */

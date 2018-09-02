#ifndef HEADERS_WINDOW_H_
#define HEADERS_WINDOW_H_

namespace PACMAN {
class Window {
public:
	Window();
	Window(int Screen_width, int Screen_height);
	virtual ~Window();
	virtual int createWindow()=0;
	virtual void render()=0;
	virtual void clearScreen()=0;

	int getScreen_width();
	int getScreen_height();

private:
	int screen_width = 0;
	int screen_height = 0;
};
}
#endif /* HEADERS_WINDOW_H_ */

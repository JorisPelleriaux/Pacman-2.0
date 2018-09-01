#ifndef SDLINPUT_H_
#define SDLINPUT_H_
#include "Input.h"
#include "BaseInput.h"
using namespace PACMAN;

namespace PACMAN_SDL {
class SDLInput: public Input {
public:
	SDLInput();
	~SDLInput();
	BaseInput* GetInput() override;
};
}
#endif /* SDLINPUT_H_ */

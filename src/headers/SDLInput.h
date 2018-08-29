#ifndef SDLINPUT_H_
#define SDLINPUT_H_
#include "Input.h"
#include "BaseInput.h"

class SDLInput: public Input {
public:
	SDLInput();
	~SDLInput();
	BaseInput* GetInput() override;
};

#endif /* SDLINPUT_H_ */

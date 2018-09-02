#ifndef INPUT_H_
#define INPUT_H_
#include <vector>
#include "BaseInput.h"

namespace PACMAN {
class Input {
public:
	virtual ~Input();
	virtual BaseInput* getInput()=0;
};
}
#endif /* INPUT_H_ */

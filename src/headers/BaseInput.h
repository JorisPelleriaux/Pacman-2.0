#ifndef HEADERS_BASEINPUT_H_
#define HEADERS_BASEINPUT_H_
#include <vector>

namespace PACMAN {
//Enum of Input types
enum InputType {
	None, DLeft, DRight, DUp, DDown, Quit, ULeft, URight, UUp, UDown, Enter
};

class BaseInput {
public:
	BaseInput();
	~BaseInput();
	std::vector<InputType> inputVector;
};
}
#endif /* HEADERS_BASEINPUT_H_ */

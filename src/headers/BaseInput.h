#ifndef HEADERS_BASEINPUT_H_
#define HEADERS_BASEINPUT_H_
#include <vector>

//Enum of Input types
enum InputType {
	None, DLeft, DRight, DUp, DDown, Quit, ULeft, URight, UUp, UDown
};

class BaseInput {
public:
	BaseInput();
	~BaseInput();
	std::vector<InputType> inputVector;
};

#endif /* HEADERS_BASEINPUT_H_ */

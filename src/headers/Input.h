#ifndef INPUT_H_
#define INPUT_H_
#include <vector>
#include "BaseInput.h"
using namespace std;

namespace PACMAN {
class Input {
public:
	virtual ~Input();
	virtual BaseInput* GetInput()=0;
};
}
#endif /* INPUT_H_ */

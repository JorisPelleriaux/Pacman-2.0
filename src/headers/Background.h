#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "Entity.h"

namespace PACMAN {
class Background: public Entity {
public:
	Background();
	virtual ~Background();
	void move() override;

	//Text on the beginning
	virtual void startScreen() = 0;
};
}
#endif /* BACKGROUND_H_ */

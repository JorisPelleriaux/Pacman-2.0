#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "Entity.h"

namespace PACMAN {
class Background: public Entity {
public:
	Background();
	virtual ~Background();
	void move() override;
	virtual void startScreen() = 0;	//Text on the beginning
};
}
#endif /* BACKGROUND_H_ */

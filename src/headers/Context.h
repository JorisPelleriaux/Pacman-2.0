#ifndef HEADERS_CONTEXT_H_
#define HEADERS_CONTEXT_H_
using namespace std;
#include <string>
#include <windef.h>
#include "AbsTile.h"

class Context {
public:
	Context();
	virtual ~Context();
	bool checkcollision(RECT a, RECT b);
	bool touchesWall(RECT box);

};

#endif /* HEADERS_CONTEXT_H_ */

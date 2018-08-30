#ifndef HEADERS_CONTEXT_H_
#define HEADERS_CONTEXT_H_
using namespace std;
#include <string>
#include<windef.h>

class Context {
	public:
		Context();
		virtual ~Context();
		bool checkcollision(RECT a, RECT b);
		//The level tiles
};

#endif /* HEADERS_CONTEXT_H_ */

/*
 * Context.cpp
 *
 *  Created on: 30 aug. 2018
 *      Author: joris
 */
#include <iostream>
#include "Context.h"
using namespace std;
Context::Context() {

}

Context::~Context() {

}
bool Context::checkcollision(RECT a, RECT b) {

	//If any of the sides from A are outside of B
	if (a.bottom <= b.top) {
		return false;
	}

	if (a.top >= b.bottom) {
		return false;
	}

	if (a.right <= b.left) {
		return false;
	}

	if (a.left >= b.right) {
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

/* MANTAS */

#pragma once

#include "SDL.h"

class Controller{
protected:
	static Controller* controllerPointer;
	const Uint8* keyCheck;
public:
	Controller();
	~Controller();
	static Controller* useController();
	bool checkKey(int key);
	int getPressedKey();
};


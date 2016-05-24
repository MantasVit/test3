/* MANTAS */

#pragma once

#include "SDL.h"
#include <string>

const int DEFAULT_WIDTH = 1024;
const int DEFAULT_HEIGHT = 768;

class Window{
protected:
	SDL_Window* gameWindow;
public:
	//create new default window
	Window();
	Window(std::string flag);
	//create new window with size dimensions
	Window(int w, int h, std::string flag);
	//create new window with size dimensions and a name
	Window(std::string windowTitle, int w, int h);
	//create new window with a name
	Window(std::string windowTitle, std::string flag);
	Window(std::string windowTitle, int w, int h, std::string flag);
	~Window();
};


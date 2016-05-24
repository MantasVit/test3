/* MANTAS */

#pragma once

#include <array>
#include "SDL.h"
#include "EngineManager.h"

class Quadtree{
protected:
	const int MAX_OBJECTS = 10;
	const int MAX_SPLITS = 5;
	std::array<Quadtree*, 4> branch;
	std::array<Quadtree*, 4>::iterator branchIterator;
	SDL_Rect area;
	int splits;
public:
	Quadtree();
	Quadtree(int Split, SDL_Rect Area);
	~Quadtree();
	void clear();
	void split();
	void getBranch();
	void insert();
	void retrieve();
};


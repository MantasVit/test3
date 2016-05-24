/* MANTAS */

#pragma once

#include <iostream>
#include "SDL.h"

class Vector2D{
	int x, y;
public:
	Vector2D();
	Vector2D(int X, int Y);
	~Vector2D();
	float magnitude();
	void normalize();
	void draw(SDL_Renderer* renderer);
};


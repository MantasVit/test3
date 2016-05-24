/* MANTAS */

#pragma once

#include "ViewFrustum.h"

class ViewFrustum;

class Camera{
protected:
	int x, y;
	ViewFrustum* vf;
public:
	Camera();
	~Camera();
	void setCameraX(int X);
	void setCameraY(int Y);
	int getCameraX();
	int getCameraY();
	//SDL_Rect* getRect();
	void update();
};


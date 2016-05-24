/* MANTAS */

#pragma once

#include "include\SDL.h"

class ObjectBase{
protected:
	int			worldLocationX, worldLocationY;
	bool		destroyed;
public:
	ObjectBase();
	ObjectBase(int x, int y);
	~ObjectBase();
	void setWorldLocationX(int x);
	void setWorldLocationY(int y);
	int getWorldLocationX();
	int getWorldLocationY();
	void destroy();
	bool getDestroyed();
	void setDestroyed(bool Destroyed);
	virtual SDL_Texture* getTexture(){return nullptr;};
	virtual SDL_Rect* getTextureRect(){return nullptr;};
	virtual SDL_Rect* getRenderArea(){return nullptr;};
	virtual void update(){};
};


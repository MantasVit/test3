/* MANTAS */

#pragma once

#include "include\SDL.h"
#include "ObjectBase.h"
#include "TextureDatabase.h"

class ObjectBase;
class Texture;
class TextureDatabase;
//class EntityBase;
class WorldSpace;

class Object: public ObjectBase{
protected:
	SDL_Rect	hitbox;
	Texture*	objectTexture;
	SDL_Rect	textureRect;
	SDL_Rect	renderArea;
	int			w, h;
	std::string worldSpace;
public:
	//default object constructor
	Object();
	//object constructor specifying which worldspace the object is created in
	Object(WorldSpace* WorldSpace);
	//object constructor specifying the texture name
	Object(std::string filename);
	//object constructor specifying the texture and worldspace
	Object(std::string filename, WorldSpace* WorldSpace);
	//object constructor specifying the texture and location
	Object(std::string filename, int x, int y);
	//object constructor specifying the texture, location and worldspace
	Object(std::string filename, int x, int y, WorldSpace* WorldSpace);
	//object deconstructor
	~Object();
	void setTexture(std::string filename);
	SDL_Texture* getTexture();
	SDL_Rect* getTextureRect();
	SDL_Rect* getRenderArea();
	//change the x location of the object
	void setX(int x);
	//change the y location of the object
	void setY(int y);
	//get the width of the object
	int getW();
	//get the height of the object
	int getH();
	void updateLocation();
	//update the object
	void update();
};


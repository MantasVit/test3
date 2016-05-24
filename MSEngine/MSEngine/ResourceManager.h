/* MANTAS */

#pragma once

#include <vector>
#include <map>
#include "include\SDL_ttf.h"
#include "ObjectBase.h"
#include "EntityBase.h"

class WorldSpace;

class ResourceManager{
protected:
	static ResourceManager* resourceManagerPointer;
	std::map<std::pair<std::pair<std::string, std::string>, int>, SDL_Texture*> textures;
	std::map<std::pair<std::string, int>, TTF_Font*> fonts;
public:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* useResources();
	//add object to object lists
	void add(ObjectBase* object);
	//add entity to entity lists
	void add(EntityBase* entity);
	//add worldspace to worldspace lists
	void add(std::string name, WorldSpace* worldSpace);
	//add texture to texture lists
	void add(SDL_Texture* texture);
	//add font to font lists
	void add(TTF_Font* font);
	//return object list
	std::vector<ObjectBase*> getObjectList();
	//return entity list
	std::vector<EntityBase*> getEntityList();
	//return worldspace list
	std::map<std::string, WorldSpace*> getWorldSpaceList();
	//return a specific worldspace
	WorldSpace* getWorldSpace(std::string name);
	//destroy a worldspace
	void destroy(WorldSpace* worldSpace);
	//destroy an object
	void destroy(ObjectBase* object);
	//destroy an entity
	void destroy(EntityBase* entity);
};


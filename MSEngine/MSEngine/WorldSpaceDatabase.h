/* MANTAS */

#pragma once

#include <map>

class WorldSpace;

class WorldSpaceDatabase{
protected:
	static WorldSpaceDatabase* classPointer;
	std::map<std::string, WorldSpace*> worldSpaceMap;
	std::map<std::string, WorldSpace*>::iterator mapIterator;
public:
	WorldSpaceDatabase();
	~WorldSpaceDatabase();
	static WorldSpaceDatabase* use();
	void add(std::string name, WorldSpace* worldSpace);
	std::map<std::string, WorldSpace*> getWorldSpaceMap();
	WorldSpace* getWorldSpace(std::string name);
	void destroy(WorldSpace* worldSpace);
};


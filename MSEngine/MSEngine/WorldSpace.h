/* MANTAS */

#pragma once

#include <string>
#include "include\SDL.h"
#include "ResourceManager.h"

class WorldSpace{
protected:
	std::string worldName;
	int worldX, worldY;
	int worldXEnd, worldYEnd;
public:
	WorldSpace();
	WorldSpace(std::string name);
	~WorldSpace();
	void setWorldName(std::string name);
	void setXCoordinates(int x);
	void setXYCoordinates(int y);
	std::string getWorldName();
	int getXCoordinates();
	int getYCoordinates();
};


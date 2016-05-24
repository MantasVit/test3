/* MANTAS */

#include "WorldSpace.h"

WorldSpace::WorldSpace(){
	worldName = "World Space";
	worldX = 0;
	worldY = 0;
	worldXEnd = 200000;
	worldYEnd = 200000;
	ResourceManager::useResources()->add(worldName, this);
	//ResourceManager::useResources()->addItem(worldName, this);
}

WorldSpace::WorldSpace(std::string name){
	worldName = name;
	worldX = 0;
	worldY = 0;
	worldXEnd = 200000;
	worldYEnd = 200000;
	ResourceManager::useResources()->add(worldName, this);
	//SDL_RenderDrawLine(renderer, worldX, worldY, worldXEnd, worldYEnd);
	//ResourceManager::useResources()->addItem(worldName, this);
}

WorldSpace::~WorldSpace(){
}

void WorldSpace::setWorldName(std::string name){
	worldName = name;
}
void WorldSpace::setXCoordinates(int x){
	worldX = x;
}
void WorldSpace::setXYCoordinates(int y){
	worldY = y;
}
std::string WorldSpace::getWorldName(){
	return worldName;
}
int WorldSpace::getXCoordinates(){
	return worldX;
}
int WorldSpace::getYCoordinates(){
	return worldY;
}

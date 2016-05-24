/* MANTAS */

#include "WorldSpaceDatabase.h"
#include "WorldSpace.h"

WorldSpaceDatabase* WorldSpaceDatabase::classPointer = nullptr;

WorldSpaceDatabase::WorldSpaceDatabase()
{
}

WorldSpaceDatabase::~WorldSpaceDatabase()
{
}

WorldSpaceDatabase* WorldSpaceDatabase::use(){
	if(classPointer == nullptr){
		classPointer = new WorldSpaceDatabase();
		return classPointer;
	}
	return classPointer;
}
void WorldSpaceDatabase::add(std::string name, WorldSpace* worldSpace){
	for(mapIterator = worldSpaceMap.begin(); mapIterator != worldSpaceMap.end(); mapIterator++){
		if(mapIterator->first != name){
			worldSpaceMap.insert(std::pair<std::string, WorldSpace*>(name, worldSpace));
		}
	}
}
std::map<std::string, WorldSpace*> WorldSpaceDatabase::getWorldSpaceMap(){
	return worldSpaceMap;
}
WorldSpace* WorldSpaceDatabase::getWorldSpace(std::string name){
	for(mapIterator = worldSpaceMap.begin(); mapIterator != worldSpaceMap.end(); mapIterator++){
		if(mapIterator->first == name){
			return mapIterator->second;
		}
	}
	return nullptr;
}
void WorldSpaceDatabase::destroy(WorldSpace* worldSpace){
	for(mapIterator = worldSpaceMap.begin(); mapIterator != worldSpaceMap.end(); mapIterator++){
		if(mapIterator->second == worldSpace){
			worldSpaceMap.erase(mapIterator);
		}
	}
}
/* MANTAS */

#include "ResourceManager.h"
#include "ObjectDatabase.h"
#include "EntityDatabase.h"
#include "WorldSpaceDatabase.h"
#include "TextureDatabase.h"

ResourceManager* ResourceManager::resourceManagerPointer = nullptr;

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::useResources(){
	if(resourceManagerPointer == nullptr){
		resourceManagerPointer = new ResourceManager();
		std::cout<<"Game database created."<<std::endl;
		return resourceManagerPointer;
	}
	//std::cout<<"SDL manager already exists."<<std::endl;
	return resourceManagerPointer;
}

void ResourceManager::add(ObjectBase* object){
	ObjectDatabase::use()->add(object);
}
void ResourceManager::add(EntityBase* entity){
	EntityDatabase::use()->add(entity);
}
void ResourceManager::add(std::string name, WorldSpace* worldSpace){
	WorldSpaceDatabase::use()->add(name, worldSpace);
}
void ResourceManager::add(SDL_Texture* texture){
	//textures.push_back(texture);
}
void ResourceManager::add(TTF_Font* font){
	//fonts.push_back(font);
}
std::vector<ObjectBase*> ResourceManager::getObjectList(){
	return ObjectDatabase::use()->getObjectList();
}
std::vector<EntityBase*> ResourceManager::getEntityList(){
	return EntityDatabase::use()->getEntityList();
}
std::map<std::string, WorldSpace*> ResourceManager::getWorldSpaceList(){
	return WorldSpaceDatabase::use()->getWorldSpaceMap();
}
WorldSpace* ResourceManager::getWorldSpace(std::string name){
	return WorldSpaceDatabase::use()->getWorldSpace(name);
}
void ResourceManager::destroy(WorldSpace* worldSpace){
	WorldSpaceDatabase::use()->destroy(worldSpace);
}
void ResourceManager::destroy(ObjectBase* object){
	ObjectDatabase::use()->destroy(object);
}
void ResourceManager::destroy(EntityBase* entity){
	EntityDatabase::use()->destroy(entity);
}


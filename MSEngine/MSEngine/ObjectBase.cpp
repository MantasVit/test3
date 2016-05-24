/* MANTAS */

#include "ObjectBase.h"
#include "ResourceManager.h"

ObjectBase::ObjectBase(){
	worldLocationX = 0;
	worldLocationY = 0;
	destroyed = false;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}

ObjectBase::ObjectBase(int x, int y){
	worldLocationX = x;
	worldLocationY = y;
	destroyed = false;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}

ObjectBase::~ObjectBase(){

}

void ObjectBase::setWorldLocationX(int x){
	worldLocationX = x;
}
void ObjectBase::setWorldLocationY(int y){
	worldLocationY = y;
}

int ObjectBase::getWorldLocationX(){
	return worldLocationX;
}
int ObjectBase::getWorldLocationY(){
	return worldLocationY;
}
void ObjectBase::destroy(){

}
bool ObjectBase::getDestroyed(){
	return destroyed;
}
void ObjectBase::setDestroyed(bool Destroyed){
	destroyed = Destroyed;
}

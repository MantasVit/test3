/* MANTAS */

#include "EntityBase.h"
#include "ResourceManager.h"

EntityBase::EntityBase(){
	alive = true;
	ResourceManager::useResources()->add(this);
}

EntityBase::~EntityBase(){
}

void EntityBase::addToList(EntityBase* entity){
	ResourceManager::useResources()->add(this);
	//EntityDatabase::use()->add(entity);
}
void EntityBase::setAlive(bool Alive){
	alive = Alive;
}
bool EntityBase::getAlive(){
	return alive;
}
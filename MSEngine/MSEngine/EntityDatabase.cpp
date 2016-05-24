/* MANTAS */

#include "EntityDatabase.h"
#include "EntityBase.h"

EntityDatabase* EntityDatabase::classPointer = nullptr;

EntityDatabase::EntityDatabase(){
}

EntityDatabase::~EntityDatabase(){
}

EntityDatabase* EntityDatabase::use(){
	if(classPointer == nullptr){
		classPointer = new EntityDatabase();
		return classPointer;
	}
	return classPointer;
}

void EntityDatabase::add(EntityBase* entity){
	entityStorage.push_back(entity);
}

std::vector<EntityBase*> EntityDatabase::getEntityList(){
	return entityStorage;
}

void EntityDatabase::destroy(EntityBase* entity){
	delete entity;
}

void EntityDatabase::clear(){
	for(int i = 0; i < entityStorage.size(); i++){
		if(!entityStorage.at(i)->getAlive()){
			delete entityStorage.at(i);
		}
	}
}

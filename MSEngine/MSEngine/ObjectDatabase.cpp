/* MANTAS */

/* MANTAS */

#include "ObjectDatabase.h"
#include "ObjectBase.h"

ObjectDatabase* ObjectDatabase::classPointer = nullptr;

ObjectDatabase::ObjectDatabase(){
}

ObjectDatabase::~ObjectDatabase(){
}

ObjectDatabase* ObjectDatabase::use(){
	if(classPointer == nullptr){
		classPointer = new ObjectDatabase();
		return classPointer;
	}
	return classPointer;
}

void ObjectDatabase::add(ObjectBase* object){
	objectStorage.push_back(object);
}

std::vector<ObjectBase*> ObjectDatabase::getObjectList(){
	return objectStorage;
}

void ObjectDatabase::destroy(ObjectBase* object){
	delete object;
}

void ObjectDatabase::clear(){
	for(int i = 0; i < objectStorage.size(); i++){
		if(objectStorage.at(i)->getDestroyed()){
			delete objectStorage.at(i);
		}
	}
}

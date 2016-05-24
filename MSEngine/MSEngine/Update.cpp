/* MANTAS */

#include "Update.h"
#include "ResourceManager.h"

Update* Update::updatePointer = nullptr;

Update::Update(){
}

Update::~Update(){
}

Update* Update::updateLogic(){
	if(updatePointer == nullptr){
		updatePointer = new Update();
		return updatePointer;
	}
	return updatePointer;
}

void Update::update(){
	for(int i = 0; i < ResourceManager::useResources()->getObjectList().size(); i++){
		ResourceManager::useResources()->getObjectList().at(i)->update();
	}
	for(int i = 0; i < ResourceManager::useResources()->getEntityList().size(); i++){
		ResourceManager::useResources()->getEntityList().at(i)->update();
		//ResourceManager::useResources()->getEntityList().at(i)->update();
	}
}

void Update::updateUpdateList(){
	for(int i = 0; i < ResourceManager::useResources()->getObjectList().size(); i++){
		updateList.push(ResourceManager::useResources()->getObjectList().at(i));
	}
	/*for(int i = 0; i < ResourceManager::useResources()->getEntityList().size(); i++){
		updateList.push(ResourceManager::useResources()->getEntityList().at(i));
	}*/
}

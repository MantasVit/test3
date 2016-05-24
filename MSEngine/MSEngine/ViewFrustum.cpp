/* MANTAS */

#include "ViewFrustum.h"



ViewFrustum::ViewFrustum()
{
}


ViewFrustum::~ViewFrustum()
{
}

void ViewFrustum::culling(Camera* camera){
	//std::cout<<ResourceManager::useResources()->getObjectList().size()<<std::endl;
	for(int i = 0; i < ResourceManager::useResources()->getObjectList().size(); i++){
		if(ResourceManager::useResources()->getObjectList().at(i)->getWorldLocationX() >= camera->getCameraX() && ResourceManager::useResources()->getObjectList().at(i)->getWorldLocationX() <= (camera->getCameraX() + 800)){
			//std::cout<<"object x within camera";
			if(ResourceManager::useResources()->getObjectList().at(i)->getWorldLocationY() >= camera->getCameraY() && ResourceManager::useResources()->getObjectList().at(i)->getWorldLocationY() <= (camera->getCameraY() + 600)){
				//std::cout<<"object y within camera";
			}
		}
	}
}
/* MANTAS */

#include "Quadtree.h"

Quadtree::Quadtree(){
	splits = 0;
	area.w = EngineManager::getManager()->getWindow()->w / branch.size();
	area.h = EngineManager::getManager()->getWindow()->h / branch.size();
	area.x = EngineManager::getManager()->getWindow()->x / branch.size();
	area.y = EngineManager::getManager()->getWindow()->y / branch.size();
}

Quadtree::Quadtree(int Split, SDL_Rect Area){
	splits = Split;
	area = Area;
}

Quadtree::~Quadtree(){

}

void Quadtree::clear(){
	for(int i = 0; i < branch.size(); i++){
		branch.at(i)->clear();
		branch.at(i) = nullptr;
	}
}
void Quadtree::split(){

}
void Quadtree::getBranch(){

}
void Quadtree::insert(){

}
void Quadtree::retrieve(){

}
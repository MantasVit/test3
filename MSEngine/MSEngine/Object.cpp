/* MANTAS */

#include "Object.h"
#include "ResourceManager.h"

Object::Object(){
	objectTexture = new Texture("Adamant_axe.png");
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = 0;
	worldLocationY = 0;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}
Object::Object(WorldSpace* WorldSpace){
	objectTexture = new Texture("Adamant_axe.png");
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = 0;
	worldLocationY = 0;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}

Object::Object(std::string filename){
	objectTexture = new Texture(filename.c_str());
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = 0;
	worldLocationY = 0;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}
Object::Object(std::string filename, WorldSpace* WorldSpace){
	objectTexture = new Texture(filename.c_str());
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = 0;
	worldLocationY = 0;
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}

Object::Object(std::string filename, int x, int y){
	objectTexture = new Texture(filename.c_str());
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = x - (w / 2);
	worldLocationY = y - (w / 2);
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}
Object::Object(std::string filename, int x, int y, WorldSpace* WorldSpace){
	objectTexture = new Texture(filename.c_str());
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
	worldLocationX = x - (w / 2);
	worldLocationY = y - (w / 2);
	ResourceManager::useResources()->add(this);
	//ObjectDatabase::use()->add(this);
}
Object::~Object(){

}

void Object::setTexture(std::string filename){
	objectTexture = new Texture(filename.c_str());
	SDL_QueryTexture(objectTexture->getTexture(), NULL, NULL, &w, &h);
	textureRect.w = w;
	textureRect.h = h;
}

SDL_Texture* Object::getTexture(){
	return objectTexture->getTexture();
}

SDL_Rect* Object::getTextureRect(){
	return &textureRect;
}

SDL_Rect* Object::getRenderArea(){
	return &renderArea;
}

void Object::setX(int x){
	textureRect.x = x;
}

void Object::setY(int y){
	textureRect.y = y;
}

int Object::getW(){
	return textureRect.w;
}

int Object::getH(){
	return textureRect.h;
}

void Object::updateLocation(){
	textureRect.x =  worldLocationX;
	//std::cout<<textureRect.x<<std::endl;
	textureRect.y =  worldLocationY;
}

void Object::update(){

}
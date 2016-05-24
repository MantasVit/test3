/* MANTAS */

#include "Camera.h"

Camera::Camera(){
	//camera.w = 800;
	//camera.h = 600;
	x = 0;
	y = 0;
	vf = new ViewFrustum();
}

Camera::~Camera(){
}

void Camera::setCameraX(int X){
	x += X;
}
void Camera::setCameraY(int Y){
	y += Y;
}

int Camera::getCameraX(){
	return x;
}
int Camera::getCameraY(){
	return y;
}

/*SDL_Rect* Camera::getRect(){
	return &camera;
}*/

void Camera::update(){
	vf->culling(this);
	/*for(int i = 0; i < ResourceManager::useResources()->getList().size(); i++){
		if(ResourceManager::useResources()->getList().at(i)->getWorldLocationX() >= x && ResourceManager::useResources()->getList().at(i)->getWorldLocationX() <= (x + 800)){
			std::cout<<"object x within camera";
			if(ResourceManager::useResources()->getList().at(i)->getWorldLocationY() >= y && ResourceManager::useResources()->getList().at(i)->getWorldLocationY() <= (y + 600)){
			std::cout<<"object y within camera";

			}
		}
	}*/
}
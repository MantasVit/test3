/* MANTAS */

#include "Controller.h"

Controller* Controller::controllerPointer = nullptr;

Controller::Controller(){
	keyCheck = SDL_GetKeyboardState(NULL);
}

Controller::~Controller(){

}

Controller* Controller::useController(){
	if(controllerPointer == nullptr){
		controllerPointer = new Controller();
		return controllerPointer;
	}
	return controllerPointer;
}

bool Controller::checkKey(int key){
	if(keyCheck[key]){
		return true;
	}
}

int Controller::getPressedKey(){
	checkKey(SDLK_UP);
	return 0;
}
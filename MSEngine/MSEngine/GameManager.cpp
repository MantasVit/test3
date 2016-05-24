/* MANTAS */

#include "GameManager.h"

GameManager* GameManager::GameManagerPointer = nullptr;

GameManager::GameManager(){
	gameRunning = true;
}

GameManager::~GameManager(){

}

GameManager* GameManager::getManager(){
	if(GameManagerPointer == nullptr){
		GameManagerPointer = new GameManager();
		std::cout<<"Game manager created."<<std::endl;
		return GameManagerPointer;
	}
	std::cout<<"Game manager already exists."<<std::endl;
	return GameManagerPointer;
}

void GameManager::startGame(){
	EngineManager::getManager()->createWindow("test", 800, 600);
	hi = new Object("WorldSpace_test.png", 300, 500);
	update();
}



void GameManager::update(){
	while(gameRunning){
		while(SDL_PollEvent(EngineManager::getManager()->getEvent())){
			if (EngineManager::getManager()->getEvent()->type == SDL_QUIT)
			{
				gameRunning = false;
			}
			if(EngineManager::getManager()->getEvent()->key.keysym.sym == SDLK_UP){
				EngineManager::getManager()->getCamera()->setCameraY(+4);
			}
			if(EngineManager::getManager()->getEvent()->key.keysym.sym == SDLK_DOWN){
				EngineManager::getManager()->getCamera()->setCameraY(-4);
			}
			if(EngineManager::getManager()->getEvent()->key.keysym.sym == SDLK_LEFT){
				EngineManager::getManager()->getCamera()->setCameraX(+4);
			}
			if(EngineManager::getManager()->getEvent()->key.keysym.sym == SDLK_RIGHT){
				EngineManager::getManager()->getCamera()->setCameraX(-4);
			}
		}
	EngineManager::getManager()->update();
	//Wo
	hi->updateLocation();
	}
}

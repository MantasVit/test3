/* MANTAS */

#include "Renderer.h"
#include "ResourceManager.h"

Renderer* Renderer::rendererPointer = nullptr;

Renderer::Renderer(){
	test = new Vector2D();
}

Renderer::~Renderer(){
}

Renderer* Renderer::useRenderer(){
	if(rendererPointer == nullptr){
		rendererPointer = new Renderer();
		std::cout<<"Renderer created."<<std::endl;
		return rendererPointer;
	}
	//std::cout<<"SDL manager already exists."<<std::endl;
	return rendererPointer;
}

void Renderer::createRenderer(SDL_Window* window){
	mainRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Renderer* Renderer::getRenderer(){
	return mainRenderer;
}

void Renderer::clearRenderer(SDL_Renderer* renderer){
	SDL_RenderClear(renderer);
}

void Renderer::renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* camera, SDL_Rect* rect){
	SDL_RenderCopy(renderer, texture, camera, rect);
}
void Renderer::updateRenderer(SDL_Renderer* renderer){
	SDL_RenderPresent(renderer);
}

void Renderer::render(){
	updateRenderList();
	SDL_RenderClear(mainRenderer);
	for(int i = 0; i < renderList.size(); i++){
		//std::cout<<renderList.size()<<std::endl;
		SDL_RenderCopy(mainRenderer, renderList.front()->getTexture(), NULL, renderList.front()->getTextureRect());
		renderList.pop();
	}
	//test->draw(mainRenderer);
	SDL_RenderPresent(mainRenderer);
}

void Renderer::updateRenderList(){
	for(int i = 0; i < ResourceManager::useResources()->getObjectList().size(); i++){
		renderList.push(ResourceManager::useResources()->getObjectList().at(i));
	}
	/*for(int i = 0; i < ResourceManager::useResources()->getEntityList().size(); i++){
		renderList.push(ResourceManager::useResources()->getEntityList().at(i));
	}*/
}
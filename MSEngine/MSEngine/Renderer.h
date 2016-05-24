/* MANTAS */

#pragma once

#include <iostream>
#include "include\SDL.h"
#include <queue>
#include "Vector2D.h"
#include "Window.h"

class ObjectBase;
class ResourceManager;

class Renderer{
protected:
	static Renderer* rendererPointer;
	SDL_Renderer* mainRenderer;
	std::queue<ObjectBase*> renderList;
	Vector2D *test;
public:
	Renderer();
	~Renderer();
	static Renderer* useRenderer();
	//create a renderer
	void createRenderer(SDL_Window* window);
	//Get the renderer used by the game
	SDL_Renderer* getRenderer();
	void clearRenderer(SDL_Renderer* renderer);
	void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* camera, SDL_Rect* rect);
	void updateRenderer(SDL_Renderer* renderer);
	//render the next frame
	void render();
	//update the list of items getting rendered every frame
	void updateRenderList();
};


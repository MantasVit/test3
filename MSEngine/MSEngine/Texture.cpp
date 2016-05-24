/* MANTAS */

#include "Texture.h"
#include "Renderer.h"

Texture::Texture(){

}

Texture::Texture(std::string filename){
	tempTexture = IMG_LoadTexture(Renderer::useRenderer()->getRenderer(), filename.c_str());
	std::cout<<"new texture"<<std::endl;
	if(tempTexture == nullptr){
		std::cout<<filename<<" not loaded: "<<SDL_GetError()<<std::endl;
	}
}

Texture::~Texture(){

}

SDL_Texture* Texture::getTexture(){
	//std::cout<<"got texture"<<std::endl;
	return tempTexture;
}

/*SDL_Rect* Texture::getRect(){
	//std::cout<<objectRect.x<<std::endl;
	return &objectRect;
}

void Texture::setX(int x){
	//std::cout<<"X set to "<<x<<std::endl;
	objectRect.x = x;
}

void Texture::setY(int y){
	objectRect.y = y;
}

void Texture::centerPivot(int target){

}*/
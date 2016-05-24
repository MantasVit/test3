/* MANTAS */

#include "Vector2D.h"

Vector2D::Vector2D(){
	x = 1;
	y = 1;
}

Vector2D::Vector2D(int X, int Y){
	x = X;
	y = Y;
}

Vector2D::~Vector2D(){

}

float Vector2D::magnitude(){
	return sqrt((x * x) + (y * y));
}
void Vector2D::normalize(){
	x = x / magnitude();
	y = y / magnitude();
}

void Vector2D::draw(SDL_Renderer* renderer){
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF ); 
	SDL_RenderDrawLine(renderer, 100, 100, 200, 200);
	printf("drawn");
}
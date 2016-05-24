/* MANTAS */

#pragma once

#include "include\SDL_ttf.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>

class TTF{
protected:
	static TTF*							ttfPointer;
	//std::map<std::string, int> fku;
	std::pair<std::string, int>					fontPair;
	std::map<std::pair<std::string, int>, TTF_Font*>			fontList;
	std::pair<std::map<std::pair<std::string, int>, TTF_Font*>::iterator, bool>	fontFinder;
	std::map<std::pair<std::string, int>, TTF_Font*>::iterator	fontIt = fontList.begin();
	std::map<std::pair<std::string, int>, TTF_Font*>::iterator fontIt2;
	std::map<std::pair<std::pair<std::string, std::string>, int>, SDL_Texture*>			textureList;
	std::pair<std::map<std::pair<std::pair<std::string, std::string>, int>, SDL_Texture*>::iterator, bool>		textureFinder;
	std::map<std::pair<std::pair<std::string, std::string>, int>, SDL_Texture*>::iterator textureIt = textureList.begin();
	std::map<std::pair<std::pair<std::string, std::string>, int>, SDL_Texture*>::iterator textureIt2;
	std::map<int, TTF_Font*> test;
	std::map<int, TTF_Font*>::iterator Test = test.begin();
	std::map<int, SDL_Texture*> test2;
	std::map<int, SDL_Texture*>::iterator Test2 = test2.begin();
	TTF_Font*							tempFont;
	std::vector<SDL_Surface*>			surfaceList;
	SDL_Surface*						tempSurface;
	std::vector<SDL_Texture*>			textureList2;
	SDL_Texture*						tempTexture;
	std::vector<bool>					fontCheckList;
	SDL_Color							textColour;
public:
	TTF();
	~TTF();
	static TTF* useTTF();
	void addText(SDL_Renderer* renderer, std::string font, std::string text, int fontSize, int r, int g, int b);
	TTF_Font* getFont(std::string font, int fontSize);
	SDL_Texture* getTexture(std::string text, std::string font, int fontSize);
	void getLetterPositions(std::string text, std::vector<int>* minY, std::vector<int>* maxY, std::vector<int>* x);
};


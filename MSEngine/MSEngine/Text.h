/* MANTAS */

#pragma once

#include "include\SDL_ttf.h"
#include <iostream>
#include "FPS.h"
#include "TTF.h"
#include <array>

class Text{
protected:
	std::string				text;
	std::string Font;
	int FontSize;
	std::vector<int>		minY;
	std::vector<int>		maxY;
	std::vector<int>		minX;
	std::vector<int>		maxX;
	std::vector<int>		maxX2;
	int	x3, y3;
	std::array<SDL_Texture*, 62> soloTexture;
	std::string numbers;
	std::string lowercases;
	std::string uppercases;
	std::string symbols;
	std::string all;
	std::array<char, 62> soloLetter;
	std::string textSheet;
	std::string checkList;
	SDL_Rect textSheetRect;
	SDL_Rect textSheetRect2;
	SDL_Rect textRect;
	SDL_Rect textRect2;
	SDL_Rect textRect3;
	SDL_Rect textRect4;
	SDL_Rect textRect5;
	SDL_Rect textRect_2;
	SDL_Rect textRect_3;
	SDL_Rect textRect_4;
	SDL_Rect textRect_5;
	SDL_Rect textRect2_2;
	SDL_Rect textRect3_2;
	int w, h;
	int ij;
	std::vector<SDL_Rect*> letter;
	std::vector<SDL_Rect*> letterSource;
	int perfTest;
	bool textureOpened;
	//std::array<int, 62> minY;
	//std::array<int, 62> maxY;
	//std::array<int, 62> minX;
	//std::array<int, 62> maxX;
	std::array<int, 62> advance;
	std::array<int, 62> minY2;
	std::array<int, 62> maxY2;
	//std::array<int, 62> minX2;
	//std::array<int, 62> maxX2;
	std::array<int, 62> advance2;
	int w2, h2;
	bool letterChecked;
	int lettersChecked;
	int i, j, k, n;
public:
	Text();
	Text(SDL_Renderer* renderer, std::string Text);
	Text(SDL_Renderer* renderer, std::string Text, std::string font);
	Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType);
	Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType, int fontSize);
	Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType, int fontSize, int r, int g, int b, int x, int y);
	~Text();
	SDL_Texture* getTexture();
	SDL_Rect* getRect();
	SDL_Rect* getRect2();
	SDL_Rect* getRect3();
	SDL_Rect* getRect4();
	SDL_Rect* getRect_2();
	SDL_Rect* getRect_3();
	SDL_Rect* getRect_4();
	SDL_Rect* getRect_5();
	SDL_Rect* getTextSheet();
	SDL_Rect* getTextSheet2();
	void outputText(std::string Text);
	std::vector<SDL_Rect*> getLetter();
	SDL_Rect* getLetterRect(int I);
	SDL_Rect* getLetterSourceRect(int I);
	void TEST(int i);
};


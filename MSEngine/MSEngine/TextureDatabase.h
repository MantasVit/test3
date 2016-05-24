/* MANTAS */

#pragma once

#include <unordered_map>
#include "Texture.h"

class Texture;

class TextureDatabase {
protected:
	static TextureDatabase* classPointer;
	std::unordered_map<std::string, Texture*> textureMap;
	std::unordered_map<std::string, Texture*>::iterator mapIterator;
	Texture* texture;
public:
	TextureDatabase();
	~TextureDatabase();
	static TextureDatabase* use();
	Texture* add(std::string filename);
};


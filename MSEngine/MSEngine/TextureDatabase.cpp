/* MANTAS */

#include "TextureDatabase.h"

TextureDatabase* TextureDatabase::classPointer = nullptr;

TextureDatabase::TextureDatabase() {
}

TextureDatabase::~TextureDatabase() {
}

TextureDatabase* TextureDatabase::use() {
	if (classPointer == nullptr) {
		classPointer = new TextureDatabase();
		return classPointer;
	}
	return classPointer;
}

Texture* TextureDatabase::add(std::string filename) {
	for (mapIterator = textureMap.begin(); mapIterator != textureMap.end(); mapIterator++) {
		if (mapIterator->first != filename) {
			texture = new Texture(filename);
			textureMap.insert(std::pair<std::string, Texture*>(filename, texture));
			texture = nullptr;
		}
	}
	mapIterator->first.find(filename);
	return mapIterator->second;
}

/* MANTAS */

#include "TTF.h"

TTF* TTF::ttfPointer = nullptr;

TTF::TTF(){
	TTF_Init();
}
TTF::~TTF(){
}
TTF* TTF::useTTF(){
	if(ttfPointer == nullptr){
		ttfPointer = new TTF();
		return ttfPointer;
	}
	return ttfPointer;
}
void TTF::addText(SDL_Renderer* renderer, std::string font, std::string text, int fontSize, int r, int g, int b){
	textColour = {0, 0, 0};
	tempFont = TTF_OpenFont(("fonts\\"+font+".ttf").c_str(), fontSize);
	tempSurface = TTF_RenderText_Solid(tempFont, text.c_str(), textColour);
	tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	//test.insert(std::pair<int, TTF_Font*>(fontSize, tempFont));
	//test2.insert(std::pair<int, SDL_Texture*>(fontSize, tempTexture));
	fontIt2 = fontList.find(std::pair<std::string, int>(font, fontSize));
	if(fontIt2 == fontList.end()){
		fontList.insert(std::make_pair(std::pair<std::string, int>(font, fontSize), tempFont));
		std::cout<<"font created"<<std::endl;
	}
	if(fontIt2 != fontList.end()){
		std::cout<<"font exists"<<std::endl;
	}
	textureIt2 = textureList.find(std::pair<std::pair<std::string, std::string>, int>(std::pair<std::string, std::string>(text, font), fontSize));
	if(textureIt2 == textureList.end()){
		textureList.insert(std::make_pair(std::pair<std::pair<std::string, std::string>, int>(std::pair<std::string, std::string>(text, font), fontSize), tempTexture));
		std::cout<<"texture created"<<std::endl;
	}
	if(textureIt2 != textureList.end()){
		std::cout<<"texture exists"<<std::endl;
	}
	//textureFinder = textureList.insert(std::make_pair(std::pair<std::pair<std::string, std::string>, int>(std::pair<std::string, std::string>(text, font), fontSize), tempTexture));
	/*if(fontFinder.second == true){
		std::cout<<"font created"<<std::endl;
	}
	if(fontFinder.second == false){
		std::cout<<"font exists"<<std::endl;
	}
	if(textureFinder.second == true){
		std::cout<<"texture created"<<std::endl;
	}
	if(textureFinder.second == false){
		std::cout<<"texture exists"<<std::endl;
	}*/
	for(fontIt = fontList.begin(); fontIt != fontList.end(); fontIt++){
		std::cout<<fontIt->first.first<<" "<<fontIt->first.second<<" "<<fontIt->second<<std::endl;
	}
	for(textureIt = textureList.begin(); textureIt != textureList.end(); textureIt++){
		std::cout<<textureIt->first.first.first<<" "<<textureIt->first.first.second<<" "<<textureIt->first.second<<" "<<textureIt->second<<std::endl;
	}
	for(Test = test.begin(); Test != test.end(); Test++){
		std::cout<<Test->first<<" "<<Test->second<<std::endl;
	}
	for(Test2 = test2.begin(); Test2 != test2.end(); Test2++){
		std::cout<<Test2->first<<" "<<Test2->second<<std::endl;
	}
}

TTF_Font* TTF::getFont(std::string font, int fontSize){
	for(fontIt = fontList.begin(); fontIt != fontList.end(); fontIt++){
		if(fontIt->first == std::pair<std::string, int>(font, fontSize)){
			return fontIt->second;
		}
	}
}
SDL_Texture* TTF::getTexture(std::string text, std::string font, int fontSize){
	for(textureIt = textureList.begin(); textureIt != textureList.end(); textureIt++){
		if(textureIt->first == std::pair<std::pair<std::string, std::string>, int>(std::pair<std::string, std::string>(text, font), fontSize)){
			return textureIt->second;
		}
	}
}
void TTF::getLetterPositions(std::string text, std::vector<int>* minY, std::vector<int>* maxY, std::vector<int>* x){
	//int i = 0;
	for(fontIt = fontList.begin(); fontIt != fontList.end(); fontIt++){
	//for(Test = test.begin(); Test != test.end(); Test++){
		//i++;
		//std::cout<<i<<std::endl;
		//std::cout<<fontCheckList.size();
		//if(fontCheckList.at(i) == false){
			//std::cout<<text.size();
		minY->resize(text.size());
				maxY->resize(text.size());
				x->resize(text.size());
			for(int j = 0; j < text.size(); j++){
				
				TTF_GlyphMetrics(fontIt->second, text.at(j), NULL, NULL, &minY->at(j), &maxY->at(j), &x->at(j));
				//std::cout<<j<<std::endl;
			}
			//fontCheckList.at(i) = true;
		//}
	}
}
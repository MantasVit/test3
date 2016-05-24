/* MANTAS */

#include "EngineManager.h"

EngineManager* EngineManager::EngineManagerPointer = nullptr;

EngineManager::EngineManager(){
	SDL_INIT_EVERYTHING;
}

EngineManager::~EngineManager(){

}

EngineManager* EngineManager::getManager(){
	if(EngineManagerPointer == nullptr){
		EngineManagerPointer = new EngineManager();
		std::cout<<"Engine manager created."<<std::endl;
		return EngineManagerPointer;
	}
	//std::cout<<"SDL manager already exists."<<std::endl;
	return EngineManagerPointer;
}

void EngineManager::createWindow(std::string gameTitle, int resolutionWidth, int resolutionHeight){
	window.w = resolutionWidth;
	window.h = resolutionHeight;
	window.x = 0;
	window.y = 0;
	//gameWindow2 = new Window(gameTitle, resolutionWidth, resolutionHeight, "SHOWN");
	gameWindow = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, resolutionWidth, resolutionHeight, SDL_WINDOW_SHOWN);
	Renderer::useRenderer()->createRenderer(gameWindow);
	mine = new WorldSpace("mine");
	mainCamera.setCameraX(mine->getXCoordinates() / 2);
	mainCamera.setCameraY(mine->getYCoordinates() / 2);
	//myText->showText("lolktest", Renderer::useRenderer()->getRenderer());
	testText = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 200, 1, 1, 1, 0, 0);
	/*testText2 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 50, 1, 1, 1, 50, 50);
	testText3 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 10, 1, 1, 1, 100, 100);
	testText4 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 150, 1, 1, 1, 150, 150);
	testText5 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 200, 1, 1, 1, 200, 200);
	testText6 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 100, 1, 1, 1, 250, 250);
	testText7 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 30, 1, 1, 1, 300, 300);
	testText8 = new Text(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update(), "OpenSans-Regular", "dynamic", 70, 1, 1, 1, 350, 350);*/
	//std::cout<<"---------"<<std::endl;
	//testText2 = new Text(Renderer::useRenderer()->getRenderer(), "egfsg", "OpenSans-Regular", "dynamic", 100, 1, 1, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 100, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 1);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	//Text::getText()->newText(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	/*myText = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText2 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText3 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText4 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText5 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText6 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText7 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText8 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText9 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText10 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText11 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText12 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText13 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText14 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText15 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText16 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText17 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText18 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText19 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText20 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText21 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText22 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText23 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText24 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText25 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText26 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText27 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText28 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText29 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);
	myText30 = new Text(Renderer::useRenderer()->getRenderer(), "fonts\\OpenSans-Regular.ttf", 1000, 2);*/
	fps = new FPS();
	vector = new Vector2D();
}

SDL_Rect* EngineManager::getWindow(){
	return &window;
}

SDL_Event* EngineManager::getEvent(){
	return &gameEvent;
}

Camera* EngineManager::getCamera(){
	return &mainCamera;
}

void EngineManager::update(){
	/*Renderer::useRenderer()->clearRenderer(Renderer::useRenderer()->getRenderer());
	for(int i = 0; i < ResourceManager::useResources()->getSize(); i++){
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), ResourceManager::useResources()->getObjectList().at(i)->getTexture(), NULL, ResourceManager::useResources()->getObjectList().at(i)->getTextureRect());
	}*/
	//vector->draw(Renderer::useRenderer()->getRenderer());
	//testText->outputText(FPS::useFPS()->update());
	/*testText2->outputText(FPS::useFPS()->update());
	testText3->outputText(FPS::useFPS()->update());
	testText4->outputText(FPS::useFPS()->update());
	testText5->outputText(FPS::useFPS()->update());
	testText6->outputText(FPS::useFPS()->update());
	testText7->outputText(FPS::useFPS()->update());
	testText8->outputText(FPS::useFPS()->update());*/
	//testText2->outputText(FPS::useFPS()->update());
	//testText->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	/*myText2->outputText(FPS::useFPS()->update());
	//myText2->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText3->outputText(FPS::useFPS()->update());
	//myText3->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText4->outputText(FPS::useFPS()->update());
	//myText4->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText5->outputText(FPS::useFPS()->update());
	//myText5->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText6->outputText(FPS::useFPS()->update());
	//myText6->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText7->outputText(FPS::useFPS()->update());
	//myText7->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText8->outputText(FPS::useFPS()->update());
	//myText8->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText9->outputText(FPS::useFPS()->update());
	//myText9->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText10->outputText(FPS::useFPS()->update());
	//myText10->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText11->outputText(FPS::useFPS()->update());
	//myText11->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText12->outputText(FPS::useFPS()->update());
	//myText12->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText13->outputText(FPS::useFPS()->update());
	//myText13->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText14->outputText(FPS::useFPS()->update());
	//myText14->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText15->outputText(FPS::useFPS()->update());
	//myText15->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText16->outputText(FPS::useFPS()->update());
	//myText16->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText17->outputText(FPS::useFPS()->update());
	//myText17->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText18->outputText(FPS::useFPS()->update());
	//myText18->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText19->outputText(FPS::useFPS()->update());
	//myText19->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText20->outputText(FPS::useFPS()->update());
	//myText20->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText21->outputText(FPS::useFPS()->update());
	//myText21->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText22->outputText(FPS::useFPS()->update());
	//myText22->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText23->outputText(FPS::useFPS()->update());
	//myText23->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText24->outputText(FPS::useFPS()->update());
	//myText24->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText25->outputText(FPS::useFPS()->update());
	//myText25->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText26->outputText(FPS::useFPS()->update());
	//myText26->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText27->outputText(FPS::useFPS()->update());
	//myText27->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText28->outputText(FPS::useFPS()->update());
	//myText28->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText29->outputText(FPS::useFPS()->update());
	//myText29->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	myText30->outputText(FPS::useFPS()->update());*/
	//myText30->setText(Renderer::useRenderer()->getRenderer(), FPS::useFPS()->update());
	/*for (int i = 0; i < testText->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText->getTexture(), testText->getLetterSourceRect(i), testText->getLetterRect(i));
	}*/
	/*for (int i = 0; i < testText2->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText2->getTexture(), testText2->getLetterSourceRect(i), testText2->getLetterRect(i));
	}
	for (int i = 0; i < testText3->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText3->getTexture(), testText3->getLetterSourceRect(i), testText3->getLetterRect(i));
	}
	for (int i = 0; i < testText4->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText4->getTexture(), testText4->getLetterSourceRect(i), testText4->getLetterRect(i));
	}
	for (int i = 0; i < testText5->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText5->getTexture(), testText5->getLetterSourceRect(i), testText5->getLetterRect(i));
	}
	for (int i = 0; i < testText6->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText6->getTexture(), testText6->getLetterSourceRect(i), testText6->getLetterRect(i));
	}
	for (int i = 0; i < testText7->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText7->getTexture(), testText7->getLetterSourceRect(i), testText7->getLetterRect(i));
	}
	for (int i = 0; i < testText8->getLetter().size(); i++) {
		Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText8->getTexture(), testText8->getLetterSourceRect(i), testText8->getLetterRect(i));
	}*/
	//for (int i = 0; i < testText2->getLetter().size(); i++) {
		//Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), testText2->getTexture(), testText2->getLetterSourceRect(i), testText2->getLetterRect(i));
	//}
	//Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), myText->getTexture(), myText->getRect_3(), myText->getRect2());
	//Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), myText->getTexture(), myText->getRect_4(), myText->getRect3());
	//Renderer::useRenderer()->renderTexture(Renderer::useRenderer()->getRenderer(), myText->getTexture(), myText->getRect_5(), myText->getRect4());
	//std::cout<<"xD"<<std::endl;
	//std::cout<<fps->update() << std::endl;
	//Text::getText()->TEST(53);
	//Text::getText()->TEST(10);
	//Text::getText()->TEST(30);
	//Text::getText()->TEST(61);
	//Renderer::useRenderer()->updateRenderer(Renderer::useRenderer()->getRenderer());
	mainCamera.update();
	Renderer::useRenderer()->render();
}
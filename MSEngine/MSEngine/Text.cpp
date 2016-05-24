/* MANTAS */

#include "Text.h"

Text::Text(){
}

Text::Text(SDL_Renderer* renderer, std::string Text){
	text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	TTF::useTTF()->addText(renderer, "fonts\\OpenSans-Regular.ttf", text, 16, 0, 0, 0);
	//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
	for(int i = 0; i < text.size(); i++){
		if(i == 0){
			minX.at(i) = 0;
		}
		else{
			minX.at(i) = maxX.at(i-1);
		}
	}
}

Text::Text(SDL_Renderer* renderer, std::string Text, std::string font){
	text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	TTF::useTTF()->addText(renderer, font, text, 16, 0, 0, 0);
	//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
	for(int i = 0; i < text.size(); i++){
		if(i == 0){
			minX.at(i) = 0;
		}
		else{
			minX.at(i) = maxX.at(i-1);
		}
	}
}

Text::Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType){
	if(textType == "static"){
		text = Text;
		TTF::useTTF()->addText(renderer, font, text, 16, 0, 0, 0);
		//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
		for(int i = 0; i < text.size(); i++){
			if(i == 0){
				minX.at(i) = 0;
			}
			else{
				minX.at(i) = maxX.at(i-1);
			}
		}
	}
	if(textType == "dynamic"){
		text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		TTF::useTTF()->addText(renderer, font, text, 16, 0, 0, 0);
		//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
		for(int i = 0; i < text.size(); i++){
			if(i == 0){
				minX.at(i) = 0;
			}
			else{
				minX.at(i) = maxX.at(i-1);
			}
		}
	}
}

Text::Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType, int fontSize){
	if(textType == "static"){
		text = Text;
		TTF::useTTF()->addText(renderer, font, text, fontSize, 0, 0, 0);
		//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
		for(int i = 0; i < text.size(); i++){
			if(i == 0){
				minX.at(i) = 0;
			}
			else{
				minX.at(i) = maxX.at(i-1);
			}
		}
	}
	if(textType == "dynamic"){
		text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		TTF::useTTF()->addText(renderer, font, text, fontSize, 0, 0, 0);
		//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
		for(int i = 0; i < text.size(); i++){
			if(i == 0){
				minX.at(i) = 0;
			}
			else{
				minX.at(i) = maxX.at(i-1);
			}
		}
	}
}

Text::Text(SDL_Renderer* renderer, std::string Text, std::string font, std::string textType, int fontSize, int r, int g, int b, int x, int y){
	//std::cout<<"text"<<std::endl;
	x3 = x;
	y3 = y;
	if(textType == "static"){
		std::cout<<"!!!!"<<std::endl;
		text = Text;
		//TTF::useTTF()->addText(renderer, font, text, fontSize, r, g, b);
		//TTF::useTTF()->getLetterPositions(text, minY, maxY, maxX);
		/*for(int i = 0; i < text.size(); i++){
			if(i == 0){
				minX.at(i) = 0;
			}
			else{
				minX.at(i) = maxX.at(i-1);
			}
		}*/
	}
	//std::cout<<"?????????????"<<std::endl;
	if(textType == "dynamic"){
		//std::cout<<"?????????????"<<std::endl;
		text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		Font = font;
		FontSize = fontSize;
		//std::string lol = "123";
		//std::cout<<"ok"<<std::endl;
		maxX2.resize(text.size());
		TTF::useTTF()->addText(renderer, font, text, fontSize, r, g, b);
		SDL_QueryTexture(getTexture(), NULL, NULL, &w2, &h2);
		//std::cout<<"good"<<std::endl;
		TTF::useTTF()->getLetterPositions(text, &minY, &maxY, &maxX);
		//std::cout<<"wat"<<std::endl;
		for(int i = 0; i < text.size(); i++){
			//std::cout<<"for loop"<<std::endl;
			if(i == 0){
				//std::cout<<"1 = 0"<<std::endl;
				minX.push_back(0);
			}
			else if(i >= 1){
				maxX2.at(i) = maxX.at(i);
				maxX.at(i) = maxX.at(i) + maxX.at(i-1);
				minX.push_back(maxX.at(i-1));
				//std::cout<<minX.at(i)<<std::endl;
				//std::cout<<maxX.at(i)<<std::endl;
				
			}
		}
	}
}

Text::~Text()
{
}

SDL_Texture* Text::getTexture(){
	return TTF::useTTF()->getTexture(text, Font, FontSize);
}

SDL_Rect* Text::getRect() {
	//SDL_QueryTexture(finished, NULL, NULL, &w, &h);
	FPS::useFPS()->update();
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
			if (all.at(i) == FPS::useFPS()->update().at(j)) {
				//std::cout << all.at(i) << " = " << FPS::useFPS()->update().at(j) << std::endl;
				//std::cout << w / (all.size() - 9) << std::endl;
				ij = i;
				textRect.w = w;
				textRect.h = h;
				textRect.x = 0;
				textRect.y = 0;
				//textRect_2.w = (w / all.size()) * i;
				//textRect_2.x = (w / all.size()) * i;
				//std::cout << w / (all.size() - j) << std::endl;
				return &textRect;
			}
		}
	}
}

SDL_Rect* Text::getRect2() {
	FPS::useFPS()->update();
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
			if (all.at(i) == FPS::useFPS()->update().at(j)) {
				if (FPS::useFPS()->update().length() >= 2) {
					textRect3.w = (w / all.size()) * i;
					textRect3.h = h;
					textRect3.x = textRect.x + ((w / all.size()) * i);
					textRect_3.x = (w / all.size()) * i;
				}
				//std::cout << w / (all.size() - j) << std::endl;
				return &textRect3;
			}
		}
	}
}

SDL_Rect* Text::getRect3() {
	FPS::useFPS()->update();
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
			if (all.at(i) == FPS::useFPS()->update().at(j)) {
				if (FPS::useFPS()->update().length() >= 3) {
					textRect4.w = (w / all.size()) * i;
					textRect4.h = h;
					textRect4.x = textRect3.x + ((w / all.size()) * i);
					textRect_4.x = (w / all.size()) * i;
				}
				//std::cout << w / (all.size() - j) << std::endl;
				return &textRect4;
			}
		}
	}
}

SDL_Rect* Text::getRect4() {
	FPS::useFPS()->update();
	for (int i = 0; i < all.size(); i++) {
		for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
			if (all.at(i) == FPS::useFPS()->update().at(j)) {
				if (FPS::useFPS()->update().length() >= 4) {
					textRect5.w = (w / all.size()) * i;
					textRect5.h = h;
					textRect5.x = textRect4.x + ((w / all.size()) * i);
					textRect_5.x = (w / all.size()) * i;
				}
				//std::cout << w / (all.size() - j) << std::endl;
				return &textRect5;
			}
		}
	}
}

SDL_Rect* Text::getRect_2() {
	//SDL_QueryTexture(finished, NULL, NULL, &w, &h);
	//FPS::useFPS()->update();
	//for (int i = 0; i < all.size(); i++) {
		//for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
			//if (all.at(i) == FPS::useFPS()->update().at(j)) {
				//std::cout << all.at(i) << " = " << FPS::useFPS()->update().at(j) << std::endl;
				//std::cout << w / (all.size()) << std::endl;
				textRect_2.x = 0;
				textRect_2.y = 0;
				textRect_2.w = textRect.w;//(w / all.size()) * getI();
				textRect_2.x = textRect.w;//(w / all.size()) * getI();
				//std::cout << w / (all.size() - j) << std::endl;
				return &textRect_2;
}

SDL_Rect* Text::getRect_3() {
	//SDL_QueryTexture(finished, NULL, NULL, &w, &h);
	//FPS::useFPS()->update();
	//for (int i = 0; i < all.size(); i++) {
	//for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
	//if (all.at(i) == FPS::useFPS()->update().at(j)) {
	//std::cout << all.at(i) << " = " << FPS::useFPS()->update().at(j) << std::endl;
	//std::cout << w / (all.size()) << std::endl;
	//textRect_2.x = 0;
	//textRect_2.y = 0;
	//textRect_3.w = textRect3.w;
	//textRect_3.h = textRect3.h;
	//std::cout << w / (all.size() - j) << std::endl;
	return &textRect_3;
}

SDL_Rect* Text::getRect_4() {
	//SDL_QueryTexture(finished, NULL, NULL, &w, &h);
	//FPS::useFPS()->update();
	//for (int i = 0; i < all.size(); i++) {
	//for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
	//if (all.at(i) == FPS::useFPS()->update().at(j)) {
	//std::cout << all.at(i) << " = " << FPS::useFPS()->update().at(j) << std::endl;
	//std::cout << w / (all.size()) << std::endl;
	//textRect_2.x = 0;
	//textRect_2.y = 0;
	//textRect_4.w = textRect4.w;
	//textRect_4.h = textRect4.h;
	//std::cout << w / (all.size() - j) << std::endl;
	return &textRect_4;
}

SDL_Rect* Text::getRect_5() {
	//SDL_QueryTexture(finished, NULL, NULL, &w, &h);
	//FPS::useFPS()->update();
	//for (int i = 0; i < all.size(); i++) {
	//for (int j = 0; j < FPS::useFPS()->update().size(); j++) {
	//if (all.at(i) == FPS::useFPS()->update().at(j)) {
	//std::cout << all.at(i) << " = " << FPS::useFPS()->update().at(j) << std::endl;
	//std::cout << w / (all.size()) << std::endl;
	//textRect_2.x = 0;
	//textRect_2.y = 0;
	//textRect_5.w = textRect5.w;
	//textRect_5.h = textRect5.h;
	//std::cout << w / (all.size() - j) << std::endl;
	return &textRect_5;
}

void Text::outputText(std::string Text) {
	//if(perfTest == 1){
	checkList = text;
	lettersChecked = 0;
		//std::cout << checkList.at(i) << std::endl;
		for (j = 0; j < Text.size(); j++) {
			for (i = 0; i < checkList.size(); i++) {
				letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if (checkList.at(i) == Text.at(j)) {
					//std::cout<<i<<std::endl;
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for(Text.size(); Text.size() < letter.size(); letter.pop_back()){
						delete letter.back();
					}
					//for(Text.size(); Text.size() < letter.size(); letter.pop_back()) {
						//letter.shrink_to_fit();
					//}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					//letter.at(k)->h = h2;
					//letter.at(k)->w = w2;
					//letter.at(k)->x = 0;
					//letter.at(k)->y = 0;
					letter.at(k)->h = h2;
					letter.at(k)->w = maxX2.at(i);
					letter.at(k)->x = x3 + letter.at(k)->w * k;
					letter.at(k)->y = y3;
					if(letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
						//std::cout<<"new rect"<<std::endl;
					}
					for (letterSource.size(); letterSource.size() > letter.size(); letterSource.pop_back()){
						delete letterSource.back();
					}
					//std::cout<<letter.size()<<" "<<letterSource.size()<<std::endl;
					for (n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							//std::cout<<letterSource.at(n)->x;
							letterSource.at(n)->x = minX.at(i);
							//std::cout<<maxX.at(28)<<std::endl;
							letterSource.at(n)->y = minY.at(i);
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							//std::cout<<"letter checked"<<std::endl;
							lettersChecked += 1;
						}
					}
				//}
					if (letterChecked == true) {
						break;
					}
				}
				}
			}
		}
	//}
	/*if(perfTest == 2){
		bool letterChecked;
		int lettersChecked = 0;
		bool lowerCheck = true, upperCheck = true, numCheck = true;
		for(int i = 0; i < Text.size(); i++){
			if(Text.at(i) == 'a'||'b'||'c'||'d'||'e'||'f'||'g'||'h'||'i'||'j'||'k'||'l'||'m'||'n'||'o'||'p'||'q'||'r'||'s'||'t'||'u'||'v'||'w'||'x'||'y'||'z'){
				for(int j = 0; j < lowercases.size(); j++){
					if(Text.at(i) == lowercases.at(j)){
						letterChecked = false;
						if(letter.size() < Text.size()) {
							letter.push_back(new SDL_Rect);
						}
						for(int k = lettersChecked; k < letter.size(); k++){
							for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
							}
							letter.at(k)->h = h;
							letter.at(k)->w = w / lowercases.size();
							letter.at(k)->x = letter.at(k)->w * k;
							letter.at(k)->y = 0;
							if (letterSource.size() < letter.size()) {
								letterSource.push_back(new SDL_Rect);
							}
							for (int n = 0; n < letterSource.size(); n++){
								if (n == k) {
									//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
									letterSource.at(n)->h = letter.at(k)->h;
									letterSource.at(n)->w = letter.at(k)->w;
									letterSource.at(n)->x = (w / lowercases.size()) * (i);
									letterSource.at(n)->y = 0;
									//std::cout <<"N: "<< n << std::endl;
									//std::cout << "K: " << k << std::endl;
									//std::cout << "I: " << i << std::endl;
									//std::cout << "J: " << j << std::endl;
									letterChecked = true;
									lettersChecked += 1;
								}
							}
							if (letterChecked == true) {
								break;
							}
						}
					}
				}
			}
			if(Text.at(i) == 'A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'N'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z'){
				for(int j = 0; j < uppercases.size(); j++){
					if(Text.at(i) == uppercases.at(j)){
						letterChecked = false;
						if(letter.size() < Text.size()) {
							letter.push_back(new SDL_Rect);
						}
						for(int k = lettersChecked; k < letter.size(); k++){
							for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
							}
							letter.at(k)->h = h;
							letter.at(k)->w = w / uppercases.size();
							letter.at(k)->x = letter.at(k)->w * k;
							letter.at(k)->y = 0;
							if (letterSource.size() < letter.size()) {
								letterSource.push_back(new SDL_Rect);
							}
							for (int n = 0; n < letterSource.size(); n++){
								if (n == k) {
									//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
									letterSource.at(n)->h = letter.at(k)->h;
									letterSource.at(n)->w = letter.at(k)->w;
									letterSource.at(n)->x = (w / uppercases.size()) * (i);
									letterSource.at(n)->y = 0;
									//std::cout <<"N: "<< n << std::endl;
									//std::cout << "K: " << k << std::endl;
									//std::cout << "I: " << i << std::endl;
									//std::cout << "J: " << j << std::endl;
									letterChecked = true;
									lettersChecked += 1;
								}
							}
							if (letterChecked == true) {
								break;
							}
						}
					}
				}
			}
			if(Text.at(i) == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
				for(int j = 0; j < numbers.size(); j++){
					if(Text.at(i) == numbers.at(j)){
						letterChecked = false;
						if(letter.size() < Text.size()) {
							letter.push_back(new SDL_Rect);
						}
						for(int k = lettersChecked; k < letter.size(); k++){
							for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
							}
							letter.at(k)->h = h;
							letter.at(k)->w = w / numbers.size();
							letter.at(k)->x = letter.at(k)->w * k;
							letter.at(k)->y = 0;
							if (letterSource.size() < letter.size()) {
								letterSource.push_back(new SDL_Rect);
							}
							for (int n = 0; n < letterSource.size(); n++){
								if (n == k) {
									//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
									letterSource.at(n)->h = letter.at(k)->h;
									letterSource.at(n)->w = letter.at(k)->w;
									letterSource.at(n)->x = (w / numbers.size()) * (i);
									letterSource.at(n)->y = 0;
									//std::cout <<"N: "<< n << std::endl;
									//std::cout << "K: " << k << std::endl;
									//std::cout << "I: " << i << std::endl;
									//std::cout << "J: " << j << std::endl;
									letterChecked = true;
									lettersChecked += 1;
								}
							}
							if (letterChecked == true) {
								break;
							}
						}
					}
				}
			}
		}





		/*for (int j = 0; j < numbers.size(); j++) {
			for (int b = 0; b < uppercases.size(); b++) {
				for (int a = 0; a < lowercases.size(); a++) {
					for (int i = 0; i < Text.size(); i++) {
						if(Text.at(i) == lowercases.at(a)){
							letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if(lowerCheck == true){
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / lowercases.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / lowercases.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				}
				}
					if (letterChecked == true) {
						break;
					}
						}
				else if(Text.at(i) == uppercases.at(b)){
					letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if(lowerCheck == true){
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / lowercases.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / lowercases.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				}
				}
					if (letterChecked == true) {
						break;
					}
				}
				else if(Text.at(i) == numbers.at(j)){
					letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if(lowerCheck == true){
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / lowercases.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / lowercases.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				}
				}
					if (letterChecked == true) {
						break;
					}
				}
/*
		//std::cout << checkList.at(i) << std::endl;
		for (int j = 0; j < Text.size(); j++) {
			for (int i = 0; i < lowercases.size(); i++) {
			
			
				letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if(lowerCheck == true){
				if (lowercases.at(i) == Text.at(j)) {
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / lowercases.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / lowercases.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				//}
					if (letterChecked == true) {
						break;
					}
				}
				}
				}
				for (int i = 0; i < numbers.size(); i++) {
				if(numbers.at(i) == Text.at(j)){
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / numbers.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / numbers.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				//}
					if (letterChecked == true) {
						break;
					}
				}
				}
				for (int i = 0; i < uppercases.size(); i++) {
				if(uppercases.at(i) == Text.at(j)){
					//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / uppercases.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / uppercases.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				//}
					if (letterChecked == true) {
						break;
					}*/
				//}
				//}
			//}
		//}
	//}
	/*if(perfTest == 3){
		bool letterChecked;
		int lettersChecked = 0;
		//std::cout << checkList.at(i) << std::endl;
		for (int j = 0; j < Text.size(); j++) {
			for (int i = 0; i < soloLetter.size(); i++) {
				letterChecked = false;
			//std::cout << Text.at(j) << std::endl;
			//std::cout << "stuck in for loop" << std::endl;
				if (soloLetter.at(i) == Text.at(j)) {
				//std::cout << Text.at(j) << " = " << checkList.at(i) << std::endl;
				if (letter.size() < Text.size()) {
					letter.push_back(new SDL_Rect);
				}
				for (int k = lettersChecked; k < letter.size(); k++) {
					
				//if(k <= letter.size()){
					//std::cout << "stuck in letter" << std::endl;
					//std::cout << letter.size() << std::endl;
					for (Text.size(); Text.size() < letter.size(); letter.pop_back()) {
					}
					//for (int n = 0; n < 1; n++){
						//std::cout << "letter: " << letter.size() << std::endl;
					letter.at(k)->h = h;
					letter.at(k)->w = w / soloLetter.size();
					letter.at(k)->x = letter.at(k)->w * k;
					letter.at(k)->y = 0;
					if (letterSource.size() < letter.size()) {
						letterSource.push_back(new SDL_Rect);
					}
					for (int n = 0; n < letterSource.size(); n++){
						if (n == k) {
							//std::cout << "letterSource: "<<letterSource.size()<< std::endl;
							letterSource.at(n)->h = letter.at(k)->h;
							letterSource.at(n)->w = letter.at(k)->w;
							letterSource.at(n)->x = (w / soloLetter.size()) * (i);
							letterSource.at(n)->y = 0;
							//std::cout <<"N: "<< n << std::endl;
							//std::cout << "K: " << k << std::endl;
							//std::cout << "I: " << i << std::endl;
							//std::cout << "J: " << j << std::endl;
							letterChecked = true;
							lettersChecked += 1;
						}
					}
				//}
					if (letterChecked == true) {
						break;
					}
				}
				}
			}
		}
	}*/
}

std::vector<SDL_Rect*> Text::getLetter() {
	return letter;
}

SDL_Rect* Text::getLetterRect(int I) {
	return letter.at(I);
}
SDL_Rect* Text::getLetterSourceRect(int I) {
	return letterSource.at(I);
}

SDL_Rect* Text::getTextSheet() {
	return &textSheetRect;
}
SDL_Rect* Text::getTextSheet2() {
	return &textSheetRect2;
}

void Text::TEST(int i){
	//std::cout<<all.at(i)<<" ";
	//std::cout<<minX.at(i)<<" ";
	//std::cout<<maxX.at(i)<<" ";
	//std::cout<<minY2.at(i)<<" ";
	//std::cout<<maxY2.at(i)<<std::endl;
	std::cout<<"w2: "<<w2<<", w: "<<w<<std::endl;
}
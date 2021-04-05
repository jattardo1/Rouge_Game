#include "KeyboardListener.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <thread>
#include "scrolly.hpp"
	int trip = 0;
	int trip2 = 0;
KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid) : grid(_grid) {}

void KeyboardListener::run() {
	int path = 0;
	int hallucinate = 0;
	//grid->writeLine(3, "Press 'x' to exit");
	int i = startRoom;
	std::string a = (" a");
	std::string poop;
	std::vector<std::string> packItem;
	int packNum[] = {0};
	std::vector<char> packChar;
	running = true;
	char input;
	HandlerplayerX = HandlerstartX[i] + HandlerplayerX ;
	HandlerplayerY = HandlerstartY[i] + HandlerplayerY ;
	if(Dswordname != ""){
		    packItem.push_back(Dswordname);
		    packChar.push_back(')');
    }
	if(Darmorname != ""){
		    packItem.push_back(Darmorname);
		    packChar.push_back(']');
    }
	do {
		srand(time(0));
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());
		switch (input) {
		// press X to stop
		case 'x':
			running = false;
			grid->writeLine(2, "Exiting...");
			break;
		case 'h':
			if(hallucinate != 0){
				for(int y = 0; y < handlerWidth[i] - 1; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						trip = rand() %  10;
						grid->addObjectToDisplay(new GridChar((char)(x+y+trip + 40)), y, x+2);
					}
				}
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX2[i]+ HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
				hallucinate++;
				if(hallucinate == 7){
				for(int y = 0; y < handlerWidth[i]; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						if(y == handlerWidth[i] - 1 || x == handlerHeight[i] - 1 || x == 0 || y ==0){
							grid->addObjectToDisplay(new GridChar('X'), y, x + 2);
						}
						else{
							grid->addObjectToDisplay(new GridChar('.'), y, x + 2);
						}
					}
				}
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX2[i] + HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
					hallucinate = 0;

				}
			}
			else{
				trip = 0;
			}
			if((HandlerplayerX != HandlerstartX[i] + 1) || (HandlerplayerY == handlerDoorY[i] && HandlerplayerX == handlerDoorX[i] + 1) || (HandlerplayerY == handlerDoor2Y[i] && HandlerplayerX == handlerDoor2X[i] + 1)|| path == 1){
			movecount++;
			if(movecount / hpmoves >= 1){
				HandlerHP++;
				grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				movecount =0;
			}
			for(int u = 0; pathX[u] != 0; u++){
				if((HandlerplayerX - 1) != pathX[u] && (HandlerplayerY + 2 == pathY[u]) && (HandlerplayerX ) == pathX[u]) {
					movecount--;
				}
				if((HandlerplayerX - 1) == pathX[u] && HandlerplayerY + 2 == pathY[u]){
					grid->addObjectToDisplay(new GridChar('#'), HandlerplayerX, HandlerplayerY + 2);
					if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
						grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
					}
					HandlerplayerX--;
					grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
					path = 1;
				}
			}
			for(int y = 0; y < rooms; y++){
				if((HandlerplayerY == handlerDoorY[y] && HandlerplayerX == handlerDoorX[y] + 1) || (HandlerplayerY == handlerDoor2Y[y] && HandlerplayerX == handlerDoor2X[y] + 1)){
					i = y;
					path = 0;
				}
			}
			if(i == 3){
					i = 2;
			}
			if(path == 0){
			if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
			grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerswordX[i] && HandlerplayerY == HandlerstartY[i] + HandlerswordY[i]){
			grid->addObjectToDisplay(new GridChar(')'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if((HandlerplayerX == HandlerstartX[i] + HandlerarmorX[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY[i]) || (HandlerplayerX == HandlerstartX[i] + HandlerarmorX2[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY2[i])){
			grid->addObjectToDisplay(new GridChar(']'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX - 1 == HandlerstartX[i] + HandlersnakeX[i] && HandlerplayerY == HandlerstartY[i] + HandlersnakeY[i] ){
			HandlerplayerX++;
			movecount--;
				if(HandlersnakeHP[i] > 0){
					int num;
					num = (rand() % HandlersnakeHit[i] + 1);
					num = num + Handlersword;
					HandlersnakeHP[i] = HandlersnakeHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Snake for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlersnakeHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
					HandlerHP = HandlerHP - yonk;
				if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlersnakeHP[i] <= 0){
					HandlersnakeX[i] = 0;
					HandlersnakeY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX - 1 == HandlerstartX[i] + HandlerhobX[i] && HandlerplayerY == HandlerstartY[i] + HandlerhobY[i]){
				HandlerplayerX++;
				movecount--;
				if(HandlerhobHP[i] > 0){
					int num;
					num = (rand() % HandlerhobHit[i] + 1);
					num = num + Handlersword;
					HandlerhobHP[i] = HandlerhobHP[i] - num;
					grid->writeLine(-1, "Info: Hit Hobgoblin for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlerhobHP[i] > 0)
				{
									int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				packItem.erase(packItem.begin());
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlerhobHP[i] <= 0){
					HandlerhobX[i] = 0;
					HandlerhobY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX - 1 == HandlerstartX[i] + HandlertrollX[i] && HandlerplayerY == HandlerstartY[i] + HandlertrollY[i]){
				HandlerplayerX++;
				movecount--;
				if(playerac != 't'){
				if(HandlertrollHP[i] > 0){
					int num;
					num = (rand() % HandlertrollHit[i] + 1);
					num = num + Handlersword;
					HandlertrollHP[i] = HandlertrollHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Troll for " + std::to_string(num) + " damage");
					if(playerac == 'd'){
					if(1 > packItem.size()){
						grid->writeLine(infoline, "Info: INVALID NUMBER");
					}
					else{
					packItem.erase(packItem.begin() + 0);
					if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 
						grid->addObjectToDisplay(new GridChar(']'), HandlerarmorX2[i] + HandlerstartX[i], HandlerarmorY2[i]+ HandlerstartY[i] + 2);	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
						grid->addObjectToDisplay(new GridChar(']'), HandlerarmorX[i] + HandlerstartX[i], HandlerarmorY[i]+ HandlerstartY[i] + 2);
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
			}
				}
				}
				if(HandlerHP > 0 && HandlertrollHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlertrollHP[i] <= 0){
					HandlertrollX[i] = 0;
					HandlertrollY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
				}
				else{
					playerac = 'q';
					grid->addObjectToDisplay(new GridChar('.'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
					HandlertrollX[i] = 1;
					HandlertrollY[i] = 3;
					grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerobjX[i] && HandlerplayerY == HandlerstartY[i] + HandlerobjY[i]){
			grid->addObjectToDisplay(new GridChar('?'), HandlerplayerX, HandlerplayerY + 2);
			}
			else{
			grid->addObjectToDisplay(new GridChar( '.'), HandlerplayerX, HandlerplayerY + 2);
			}
			HandlerplayerX--;
			grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
			}
			}
			break;

		case 'l':
					if(hallucinate != 0){
				for(int y = 0; y < handlerWidth[i] - 1; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						trip = rand() %  10;
						grid->addObjectToDisplay(new GridChar((char)(x+y+trip + 40)), y, x+2);
					}
				}
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX2[i]+ HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
				hallucinate++;
				if(hallucinate == 7){
				for(int y = 0; y < handlerWidth[i]; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						if(y == handlerWidth[i] - 1 || x == handlerHeight[i] - 1 || x == 0 || y ==0){
							grid->addObjectToDisplay(new GridChar('X'), y, x + 2);
						}
						else{
							grid->addObjectToDisplay(new GridChar('.'), y, x + 2);
						}
					}
				}
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX2[i] + HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
					hallucinate = 0;

				}
			}
			else{
				trip = 0;
			}
			if((HandlerplayerX != HandlerstartX[i] + handlerWidth[i] - 2) || (HandlerplayerY == handlerDoorY[i] && HandlerplayerX == handlerDoorX[i] - 1) || (HandlerplayerY == handlerDoor2Y[i] && HandlerplayerX == handlerDoor2X[i] - 1)|| (HandlerplayerY == handlerDoorY[3] && HandlerplayerX == handlerDoorX[3] - 1)|| path == 1){
			movecount++;
			if(movecount / hpmoves >= 1){
				HandlerHP++;
				grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				movecount =0;
			}
			for(int u = 0; pathX[u] != 0; u++){
				if((HandlerplayerX + 1) != pathX[u] && (HandlerplayerY + 2 == pathY[u]) && (HandlerplayerX) == pathX[u]) {
					movecount--;
				}
				if((HandlerplayerX + 1) == pathX[u] && HandlerplayerY + 2 == pathY[u]){
					grid->addObjectToDisplay(new GridChar('#'), HandlerplayerX, HandlerplayerY + 2);
					if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
						grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
					}
					HandlerplayerX++;
					movecount++;
					grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
					path = 1;
					u = 282;
				}
			}
			for(int y = 0; y < rooms; y++){
				if((HandlerplayerY == handlerDoorY[y] && HandlerplayerX == handlerDoorX[y] - 1) || (HandlerplayerY == handlerDoor2Y[y] && HandlerplayerX == handlerDoor2X[y] - 1)){
					i = y;
					path = 0;
				
				}
			}
			if(path == 0){
			if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
			grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerswordX[i] && HandlerplayerY == HandlerstartY[i] + HandlerswordY[i]){
			grid->addObjectToDisplay(new GridChar(')'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if((HandlerplayerX == HandlerstartX[i] + HandlerarmorX[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY[i]) || (HandlerplayerX == HandlerstartX[i] + HandlerarmorX2[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY2[i])){
			grid->addObjectToDisplay(new GridChar(']'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX + 1 == HandlerstartX[i] + HandlersnakeX[i] && HandlerplayerY == HandlerstartY[i] + HandlersnakeY[i]){
			HandlerplayerX--;
			movecount--;
				if(HandlersnakeHP[i] > 0){
					int num;
					num = (rand() % HandlersnakeHit[i] + 1);
					num = num + Handlersword;
					HandlersnakeHP[i] = HandlersnakeHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Snake for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlersnakeHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlersnakeHP[i] <= 0){
					HandlersnakeX[i] = 0;
					HandlersnakeY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX + 1 == HandlerstartX[i] + HandlerhobX[i] && HandlerplayerY == HandlerstartY[i] + HandlerhobY[i]){
			HandlerplayerX--;
			movecount--;
				if(HandlerhobHP[i] > 0){
					int num;
					num = (rand() % HandlerhobHit[i] + 1);
					num = num + Handlersword;
					HandlerhobHP[i] = HandlerhobHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Hobgoblin for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlerhobHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlerhobHP[i] <= 0){
					HandlerhobX[i] = 0;
					HandlerhobY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX + 1 == HandlerstartX[i] + HandlertrollX[i] && HandlerplayerY == HandlerstartY[i] + HandlertrollY[i]){
			HandlerplayerX--;
			movecount--;
			if(playerac!='t'){
				if(HandlertrollHP[i] > 0){
					int num;
					num = (rand() % HandlertrollHit[i] + 1);
					num = num + Handlersword;
					HandlertrollHP[i] = HandlertrollHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Troll for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlertrollHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlertrollHP[i] <= 0){
					HandlertrollX[i] = 0;
					HandlertrollY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else{
				playerac = 'q';
					grid->addObjectToDisplay(new GridChar( '.'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
					HandlertrollX[i] = 1;
					HandlertrollY[i] = 3;
					grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerobjX[i] && HandlerplayerY == HandlerstartY[i] + HandlerobjY[i]){
			grid->addObjectToDisplay(new GridChar('?'), HandlerplayerX, HandlerplayerY + 2);
			}
			else{
			grid->addObjectToDisplay(new GridChar( '.'), HandlerplayerX, HandlerplayerY + 2);
			}
			HandlerplayerX++;
			grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
			}
			}
			break;
		case 'k':
					if(hallucinate != 0){
				for(int y = 0; y < handlerWidth[i] - 1; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						trip = rand() %  10;
						grid->addObjectToDisplay(new GridChar((char)(x+y+trip + 40)), y, x+2);
					}
				}
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX2[i]+ HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
				hallucinate++;
				if(hallucinate == 7){
				for(int y = 0; y < handlerWidth[i]; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						if(y == handlerWidth[i] - 1 || x == handlerHeight[i] - 1 || x == 0 || y ==0){
							grid->addObjectToDisplay(new GridChar('X'), y, x + 2);
						}
						else{
							grid->addObjectToDisplay(new GridChar('.'), y, x + 2);
						}
					}
				}
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX2[i] + HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
					hallucinate = 0;

				}
			}
			else{
				trip = 0;
			}
			if(movecount / hpmoves >= 1){
				HandlerHP++;
				grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				movecount =0;
			}
			if((HandlerplayerY != HandlerstartY[i]+1) || (HandlerplayerY == handlerDoorY[i] + 1 && HandlerplayerX == handlerDoorX[i]) || (HandlerplayerY == handlerDoor2Y[i] + 1 && HandlerplayerX == handlerDoor2X[i]) || path == 1){
				for(int u = 0; pathX[u] != 0; u++){
				if((HandlerplayerX) == pathX[u] && HandlerplayerY + 1 == pathY[u]){
					grid->addObjectToDisplay(new GridChar('#'), HandlerplayerX, HandlerplayerY + 2);
					if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
						grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
					}
					movecount++;
					HandlerplayerY--;
					grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
					path = 1;
				}
			}
			for(int y = 0; y < rooms; y++){
				if((HandlerplayerY == handlerDoorY[y] + 1 && HandlerplayerX == handlerDoorX[y]) || (HandlerplayerY == handlerDoor2Y[y] + 1 && HandlerplayerX == handlerDoor2X[y])){
					i = y;
					path = 0;
				
				}
			}
			if(path == 0){	
			if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
			grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerswordX[i] && HandlerplayerY == HandlerstartY[i] + HandlerswordY[i]){
			grid->addObjectToDisplay(new GridChar(')'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if((HandlerplayerX == HandlerstartX[i] + HandlerarmorX[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY[i]) || (HandlerplayerX == HandlerstartX[i] + HandlerarmorX2[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY2[i])){
			grid->addObjectToDisplay(new GridChar(']'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlersnakeX[i] && HandlerplayerY-1 == HandlerstartY[i] + HandlersnakeY[i]){
			HandlerplayerY++;
				if(HandlersnakeHP[i] > 0){
					int num;
					num = (rand() % HandlersnakeHit[i] + 1);
					num = num + Handlersword;
					HandlersnakeHP[i] = HandlersnakeHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Snake for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlersnakeHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlersnakeHP[i] <= 0){
					HandlersnakeX[i] = 0;
					HandlersnakeY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerhobX[i] && HandlerplayerY-1 == HandlerstartY[i] + HandlerhobY[i]){
			movecount++;
			HandlerplayerY++;
				if(HandlerhobHP[i] > 0){
					int num;
					num = (rand() % HandlerhobHit[i] + 1);
					num = num + Handlersword;
					HandlerhobHP[i] = HandlerhobHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Hobgoblin for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlerhobHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlerhobHP[i] <= 0){
					HandlerhobX[i] = 0;
					HandlerhobY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlertrollX[i] && HandlerplayerY-1 == HandlerstartY[i] + HandlertrollY[i]){
			movecount++;
			HandlerplayerY++;
			if(playerac != 't'){
				if(HandlertrollHP[i] > 0){
					int num;
					num = (rand() % HandlertrollHit[i] + 1);
					num = num + Handlersword;
					HandlertrollHP[i] = HandlertrollHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Troll for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlertrollHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlertrollHP[i] <= 0){
					HandlertrollX[i] = 0;
					HandlertrollY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
				else{
					playerac = 'q';
					grid->addObjectToDisplay(new GridChar( '.'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
					HandlertrollX[i] = 1;
					HandlertrollY[i] = 3;
					grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerobjX[i] && HandlerplayerY == HandlerstartY[i] + HandlerobjY[i]){
			grid->addObjectToDisplay(new GridChar('?'), HandlerplayerX, HandlerplayerY + 2);
			}
			else{
			grid->addObjectToDisplay(new GridChar( '.'), HandlerplayerX, HandlerplayerY + 2);
			}
			HandlerplayerY--;
			grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
			}
			}
			break;
		case 'j':
					if(hallucinate != 0){
				for(int y = 0; y < handlerWidth[i] - 1; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						trip = rand() %  10;
						grid->addObjectToDisplay(new GridChar((char)(x+y+trip + 40)), y, x+2);
					}
				}
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('T'+trip), HandlertrollX2[i]+ HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('S'+trip), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				trip = rand() %  10;
				grid->addObjectToDisplay(new GridChar('H'+trip), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
				hallucinate++;
				if(hallucinate == 7){
				for(int y = 0; y < handlerWidth[i]; y++){
					for(int x = 0;x < handlerHeight[i]; x++){
						if(y == handlerWidth[i] - 1 || x == handlerHeight[i] - 1 || x == 0 || y ==0){
							grid->addObjectToDisplay(new GridChar('X'), y, x + 2);
						}
						else{
							grid->addObjectToDisplay(new GridChar('.'), y, x + 2);
						}
					}
				}
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX[i]+ HandlerstartX[i], HandlersnakeY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX[i]+ HandlerstartX[i], HandlerhobY[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('T'), HandlertrollX2[i] + HandlerstartX[i], HandlertrollY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('S'), HandlersnakeX2[i]+ HandlerstartX[i], HandlersnakeY2[i]+ HandlerstartY[i] + 2);
				grid->addObjectToDisplay(new GridChar('H'), HandlerhobX2[i]+ HandlerstartX[i], HandlerhobY2[i]+ HandlerstartY[i] + 2);
					hallucinate = 0;

				}
			}
			else{
				trip = 0;
			}
			if((HandlerplayerY + 2 != HandlerstartY[i] + handlerHeight[i]) || (HandlerplayerY == handlerDoorY[i] - 1 && HandlerplayerX == handlerDoorX[i]) || (HandlerplayerY == handlerDoor2Y[i] - 1 && HandlerplayerX == handlerDoor2X[i]) || path == 1){
						movecount++;
			if(movecount / hpmoves >= 1){
				HandlerHP++;
				grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				movecount =0;
			}
			for(int u = 0; pathX[u] != 0; u++){
				if((HandlerplayerX) == pathX[u] && (HandlerplayerY + 3 != pathY[u]) && (HandlerplayerY) == pathY[u]) {
					movecount--;
				}
				if((HandlerplayerX) == pathX[u] && HandlerplayerY + 3 == pathY[u]){
					grid->addObjectToDisplay(new GridChar('#'), HandlerplayerX, HandlerplayerY + 2);
					if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
						grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
					}
					HandlerplayerY++;
					movecount++;
					grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
					path = 1;
					u = 282;
				}
			}
			for(int y = 0; y < rooms; y++){
				if((HandlerplayerY == handlerDoorY[y] - 1 && HandlerplayerX == handlerDoorX[y]) || (HandlerplayerY == handlerDoor2Y[y] - 1 && HandlerplayerX == handlerDoor2X[y])){
					i = y;
					path = 0;
				}
			}
			if(path == 0){
			if((HandlerplayerX == handlerDoorX[i] && HandlerplayerY == handlerDoorY[i]) || (HandlerplayerX == handlerDoor2X[i] && HandlerplayerY == handlerDoor2Y[i])){
			grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerswordX[i] && HandlerplayerY == HandlerstartY[i] + HandlerswordY[i]){
			grid->addObjectToDisplay(new GridChar(')'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if((HandlerplayerX == HandlerstartX[i] + HandlerarmorX[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY[i])|| (HandlerplayerX == HandlerstartX[i] + HandlerarmorX2[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY2[i])){
			grid->addObjectToDisplay(new GridChar(']'), HandlerplayerX, HandlerplayerY + 2);
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlersnakeX[i] && HandlerplayerY +1 == HandlerstartY[i] + HandlersnakeY[i]){
			HandlerplayerY--;
			movecount--;
			if(HandlersnakeHP[i] > 0){
					int num;
					num = (rand() % HandlersnakeHit[i] + 1);
					num = num + Handlersword;
					HandlersnakeHP[i] = HandlersnakeHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Snake for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlersnakeHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlersnakeHP[i] <= 0){
					HandlersnakeX[i] = 0;
					HandlersnakeY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerhobX[i] && HandlerplayerY+1 == HandlerstartY[i] + HandlerhobY[i]){
			HandlerplayerY--;
			movecount--;
			if(HandlerhobHP[i] > 0){
					int num;
					num = (rand() % HandlerhobHit[i] + 1);
					num = num + Handlersword;
					HandlerhobHP[i] = HandlerhobHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Hobgoblin for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlerhobHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
									else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlerhobHP[i] <= 0){
					HandlerhobX[i] = 0;
					HandlerhobY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlertrollX[i] && HandlerplayerY+1 == HandlerstartY[i] + HandlertrollY[i]){
			HandlerplayerY--;
			movecount--;
			if(playerac != 't'){
				if(HandlertrollHP[i] > 0){
					int num;
					num = (rand() % HandlertrollHit[i] + 1);
					num = num + Handlersword;
					HandlertrollHP[i] = HandlertrollHP[i] - num;
					grid->writeLine(infoline, "Info: Hit Troll for " + std::to_string(num) + " damage");
				}
				if(HandlerHP > 0 && HandlertrollHP[i] > 0)
				{
					int yonk = (rand() % HandlerHit + 1) - Handlerarmor;
					if(yonk <= 0){
						yonk = 0;
					}
					else if(playerac == 'd'){
					if(1 > packItem.size()){
					}
				else{
				 
				packItem.erase(packItem.begin() + 0);
				if(packChar[0] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[0] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[0] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + 0);
				}	
					}
					HandlerHP = HandlerHP - yonk;
									if(HandlerHP >= 0)
				{
					grid->writeLine(HPline, "HP: "+ std::to_string(HandlerHP) + "  core: 0");
				}
				}
				if(HandlertrollHP[i] <= 0){
					HandlertrollX[i] = 0;
					HandlertrollY[i] = 0;
				}
				if(HandlerHP <= 0)
				{
					grid->writeLine(infoline, "Info: YOU HAVE DIED. EXITTING GAME");
					running = false;
				}
			}
							else{
								playerac = 'q';
					grid->addObjectToDisplay(new GridChar( '.'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
					HandlertrollX[i] = 1;
					HandlertrollY[i] = 3;
					grid->addObjectToDisplay(new GridChar('T'), HandlertrollX[i] + HandlerstartX[i], HandlertrollY[i]+ HandlerstartY[i] + 2);
				}
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerobjX[i] && HandlerplayerY == HandlerstartY[i] + HandlerobjY[i]){
			grid->addObjectToDisplay(new GridChar('?'), HandlerplayerX, HandlerplayerY + 2);
			}
			else{
			grid->addObjectToDisplay(new GridChar( '.'), HandlerplayerX, HandlerplayerY + 2);
			}
			HandlerplayerY++;
			grid->addObjectToDisplay(new GridChar('@'), HandlerplayerX, HandlerplayerY + 2);
			}
			}
			break;
		case 'p':
			if(HandlerplayerX == HandlerstartX[i] + HandlerswordX[i] && HandlerplayerY == HandlerstartY[i] + HandlerswordY[i]){
				HandlerswordX[i] = 0;
				HandlerswordY[i] = 0;
				packItem.push_back(swordname);
				packChar.push_back(')');

			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerarmorX[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY[i]){
				HandlerarmorX[i] = 0;
				HandlerarmorY[i] = 0;
				packItem.push_back(armorname);
				packChar.push_back(']');
			}
			else if(HandlerplayerX == HandlerstartX[i] + HandlerarmorX2[i] && HandlerplayerY == HandlerstartY[i] + HandlerarmorY2[i]){
				HandlerarmorX2[i] = 0;
				HandlerarmorY2[i] = 0;
				packItem.push_back(armor2name);
				packChar.push_back(']');
			}
		    else if(HandlerplayerX == HandlerstartX[i] + HandlerobjX[i] && HandlerplayerY == HandlerstartY[i] + HandlerobjY[i]){
				HandlerobjX[i] = 0;
				HandlerobjY[i] = 0;
				packItem.push_back(objname);
				packChar.push_back('?');
			}
			break;
		case 'i':
			if(packItem.size() == 0){
				grid->writeLine(actionline, "Pack: No Items");
			}
			else{
			poop = " ";
			for(int r = 0; r < packItem.size(); r++){
				poop = poop + std::to_string(r + 1) + ": "+  packItem[r] +"  ";
			}
			grid->writeLine(actionline, "Pack: " + poop);
			}
			break;
		case 'd':
			char in;
			in = std::tolower(getchar());
			int doi;
			doi = (int)in - 48;
			if(doi > packItem.size()){
				grid->writeLine(infoline, "Info: INVALID NUMBER");
			}
			else{
				doi--;
				packItem.erase(packItem.begin() + doi);
				if(packChar[doi] == ']'){
					Handlerarmor = 0;
					if(HandlerarmorY[i] > 0){
						HandlerarmorY2[i] = HandlerplayerY; 
						HandlerarmorX2[i] = HandlerplayerX; 	
					}
					else{
						HandlerarmorY[i] = HandlerplayerY; 
						HandlerarmorX[i] = HandlerplayerX; 
					}
				}
				else if(packChar[doi] == ')'){
					Handlersword = 0;
					HandlerswordY[i] = HandlerplayerY; 
					HandlerswordX[i] = HandlerplayerX; 
				}
				else if(packChar[doi] == '?'){
					HandlerobjY[i] = HandlerplayerY; 
					HandlerobjX[i] = HandlerplayerX; 
				}
				packChar.erase(packChar.begin() + doi);
			}

		break;
		case 'w':
			char in2;
			in2 = std::tolower(getchar());
			int doi2;
			doi2 = (int)in2 - 49;
			if(doi2 > packItem.size() || packChar[doi2] != ']'){
				grid->writeLine(infoline, "Info: INVALID NUMBER");
			}
			else{
				if(Handlerarmor>0){
					Handlerarmor = 0;
				}
				Handlerarmor = armorVal;
				packItem.erase(packItem.begin() + doi2);
				packChar.erase(packChar.begin() + doi2);
				grid->writeLine(infoline, "Info: Armor Added + "+ std::to_string(armorVal));
				
			}
		break;
		case 't':
			char in3;
			in3 = std::tolower(getchar());
			int doi3;
			doi3 = (int)in3 - 49;
			if(doi3 > packItem.size() || packChar[doi3] != ')'){
				grid->writeLine(infoline, "Info: INVALID NUMBER");
			}
			else{
				if(Handlersword>0){
					Handlersword = 0;
				}
				Handlersword = swordVal;
				grid->writeLine(infoline, "Info: Sword Added + "+ std::to_string(swordVal));
			}

		break;
		case 'c':
			if(Handlerarmor > 0){
				Handlerarmor = 0;
				packItem.push_back(armorname);
				packChar.push_back(']');
			}
			else{
				grid->writeLine(-1, "Info: INVALID: NO ARMOR WORN");
			}
		break;
		case 'r':
			char in4;
			in4 = std::tolower(getchar());
			int doi4;
			doi4 = (int)in4 - 49;
			if(doi4 > packItem.size() || packChar[doi4] != '?'){
				grid->writeLine(infoline, "Info: INVALID NUMBER");
			}
			else{
				if(scrollChar == 'a'){
					grid->writeLine(infoline, "Info: You have picked up a scroll of weakened armor");
					armorVal = armorVal + scrollVal;
				}
				else if(scrollChar == 's'){
					swordVal = swordVal + scrollVal;
				}
				else if(scrollChar == 'h'){
					grid->writeLine(infoline, "Info: You have picked up a scroll of hallucination!");
					hallucinate = 1;
				}
				packItem.erase(packItem.begin() + doi4);
				packChar.erase(packChar.begin() + doi4);
				armorname = narmorname;
			}
		break;
		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
		if(running == false){
			grid->writeLine(infoline, "Info: Player is killed!");
			if(playerac == '+'){
				grid->addObjectToDisplay(new GridChar('+'), HandlerplayerX, HandlerplayerY + 2);
				grid->update();
				running = false;
			}
		}
		if(running == false){
		for(int p = 0; p < 1000000000; p++){

		}
		}
		
	} while (running && input != false);
}
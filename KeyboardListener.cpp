#include "KeyboardListener.hpp"
#include "Player.hpp"
#include "Scroll.hpp"
#include "Monster.hpp"
#include "Structure.hpp"
#include "Armor.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"
#include "ItemAction.hpp"
#include "Action.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid, Player* _players) : grid(_grid), player(_players) {}
int is_hallucinate = 0;
int actionVal = 0;
int is_wear_armor = 0;
int is_wield_sword = 0;
int packSwordNum = -1;
int is_game = 0;
int armor_strength = 0;
int changeHp = 0;
int is_player = 0;
int scroll_effect = 0;
int is_scroll = 0;
int swordHit = 0;


Item *tempArmor;
Item *tempSword;

void KeyboardListener::run() {
	int numMoves = 0;
	int hallucinateMoves = 0;

	//int is_hallucinate = 0;
	
	//grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	do {
		
		int playerHp = player->getHp();
		std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
		grid->writeLine(1, topMessage);	
		grid->update();
		
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		//input = std::tolower(getchar());
		input = getchar();


		switch (input) {
		// press X to stop

		case 'h':
			checkFuture(player, grid, 'h', &numMoves, &hallucinateMoves);
			if (is_player != 0){
				while (running && input != EOF){

				}
			}

			break;
		case 'j':
			checkFuture(player, grid, 'j', &numMoves, &hallucinateMoves);
			if (is_player != 0){
				while (running && input != EOF){

				}
			}
			break;

		case 'k':
			checkFuture(player, grid, 'k', &numMoves, &hallucinateMoves);
			if (is_player != 0){
				while (running && input != EOF){

				}
			}
			break;

		case 'l':
			checkFuture(player, grid, 'l', &numMoves, &hallucinateMoves);
			if (is_player != 0){
				while (running && input != EOF){

				}
			}
			break;

		case 'd':
			checkCurrent(player, grid, 'd');

			break;

		case 'p':
			checkCurrent(player, grid, 'p');

			break;	

		case 'i':
			checkCurrent(player, grid, 'i');
			break;

		case 'r':
			checkCurrent(player, grid, 'r');

			break;

		case 'w':
			checkCurrent(player, grid, 'w');
			break;
		
		case 'c':
			checkCurrent(player, grid, 'c');
			break;
		case 't':
			checkCurrent(player, grid, 't');
			break;
		case 'e':
			checkCurrent(player, grid, 'e');
			while (running && input != EOF){

			}
		case '?':
			checkCurrent(player, grid, '?');
			break;
		case 'H':
			checkCurrent(player, grid, 'H');
			break;	
		
		default:
			// C is not happy about appending a character to a string apparently
			//std::string message = "Unknown key '";
			//message += input;
			//grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (running && input != EOF && (is_game == 0));
}

int KeyboardListener::checkFuture(Player *player, ObjectDisplayGrid *grid, char direction, int *numMoves, int *hallucinateMoves){
	//clear the board
	grid->writeLine(2, "\n\n\n\n\n\n\n\n\n");

	int posX = player->GetCreaturePosX();
	int posY = player->GetCreaturePosY();

	int x = posX;
	int y = posY;
	int tempX = x;
	int tempY = y;

	int health = 0;
	if (*numMoves == player->getHpMove()){
		health = player->getHp();
		health = health + 1;
		player->setHp(health);
		*numMoves = 0;
	}
	else{
		*numMoves = *numMoves + 1;
	}

	if (is_hallucinate == 1){
		*hallucinateMoves = *hallucinateMoves + 1;
		
		if (*hallucinateMoves == actionVal){
			is_hallucinate = 0;
		
			int width = grid->getWidth();
			int gameHeight = grid->getHeight();

			for (int i = 0; i < width; i++) {
				for (int j = 0; j < gameHeight; j++) {
							
					char c = grid->topObjectFromDisplay(i,j);
					
					if (c != ' ' ){
						grid->removeObjectFromDisplay(i, j);
					}
				}
			}
		}	
	}

	if (direction == 'h'){
		tempX--;
	}
	else if (direction == 'j'){
		tempY++;
	}
	else if (direction == 'k'){
		tempY--;
	}
	else if (direction == 'l'){
		tempX++;
	}

	char a = grid->topObjectFromDisplay(tempX, tempY);

	if (is_hallucinate == 1){
		char b = grid->topObjectFromDisplay(tempX, tempY);
		if (b == ' '){
			return 0;
		}

		grid->removeObjectFromDisplay(tempX, tempY);
		char a = grid->topObjectFromDisplay(tempX, tempY);
		if (a == 'X' || a == ' ' || a == 'T' || a == 'H' || a == 'S'){

			grid->addObjectToDisplay(b, tempX, tempY);

			int width = grid->getWidth();
			int gameHeight = grid->getHeight();

			for (int i = 0; i < width; i++) {
				for (int j = 0; j < gameHeight; j++) {
							
					char c = grid->topObjectFromDisplay(i,j);
					if (c != ' '){

						grid->removeObjectFromDisplay(i, j);
					}

				}
			}

			std::vector<char> vec{'#', 'T', 'S', 'H', '.', '+', 'X', ')', ']', '?'};

			for (int i = 0; i < width; i++) {
				for (int j = 0; j < gameHeight; j++) {
					
					char c = grid->topObjectFromDisplay(i,j);
					
					if (c != ' '){
						int val = rand() % (vec.size()+1);
						char e = vec[val];

						grid->addObjectToDisplay(e, i, j);
					}
				}
			}
			return 0;
		}

		grid->addObjectToDisplay(b, tempX, tempY);
	}

	switch (a){
		case 'X':{

			return 0;
		}

		case ' ':{
			return 0;
		}

		case 'S':{
			if (is_hallucinate == 1){
				return 0;
			}
			Displayable *snake = grid->topObjStack(tempX, tempY);

			Creature *cSnake = dynamic_cast<Creature*>(snake);

			//std:: cout << cSnake->getDeathAction()[1]->toString();

			int snakeHp = snake->getHp();
			int playerHp = player->getHp();

			int randomHitFromSnake = rand() % (snake->getMaxHit()+1);

			if (is_hallucinate == 1){
				randomHitFromSnake = 0;
			}

			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			int newSnakeHp = snakeHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromSnake;

			//snake->setHp(newSnakeHp);
			player->setHp(newPlayerHp);
			snake->setHp(newSnakeHp);


			//monster hit actions
			//teleport the troll
			for (int r = 0; r < cSnake->getHitAction().size(); r++){
				//hit action for teleport
				//std::cout << "hiiii" << std::endl;
				if (cSnake->getHitAction()[r]->getActionName().compare("Teleport") == 0){

					char e = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					Displayable *tempMonster = grid->topObjStack(tempX, tempY);
					
					int gridHeight = grid->getHeight();
					int gridWidth = grid->getWidth();
					int newGridHeight = rand() % (gridHeight + 1);
					int newGridWidth = rand() % (gridWidth + 1);

					int flag = 1;
					while(flag == 1){
						char x = grid->topObjectFromDisplay(newGridWidth, newGridHeight);

						if (x != ' ' && x != 'X'){
							grid->addObjectToDisplay(e, newGridWidth, newGridHeight);
							grid->addObj(tempMonster, newGridWidth, newGridHeight);
							flag = 0;
							
						}
						else{
							newGridHeight = rand() % (gridHeight + 1);
							newGridWidth = rand() % (gridWidth + 1);
							flag = 1;
						}
					}
					std::string teleportMessage = cSnake->getHitAction()[r]->getMessage();
					
					grid->writeLine(2, teleportMessage);
					grid->update();

				} 
			}

			//player hit actions
			for (int r = 0; r < player->getHitAction().size(); r++){
		
				//std::cout << "hiiii" << std::endl;
				if (player->getHitAction()[r]->getActionName().compare("DropPack") == 0){
					
					for (int u = 0; u < player->getIteminPack().size(); u++){
						Item* tempItem = player->getIteminPack().at(u);

						if(dynamic_cast<Scroll*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('?', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());


							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();
							break;
						}
						else if(dynamic_cast<Armor*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay(']', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());



							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();	
							break;
						}
						else if(dynamic_cast<Sword*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay(')', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());


							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();	
							break;				
						}	
						else if (u == (player->getIteminPack().size() - 1)){
							std::string dropMessage = "No item to be dropped from hit action";
							grid->writeLine(2, dropMessage);
							grid->update();
							break;
						}
					}
				} 
			}

			if(newPlayerHp <= 0){
				//player die
				

				std::string message = "Player Dies\n";
				message += "Snake Hp: " + std::to_string(snakeHp) +
								 "  Snake got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Snake New Hp: " + std::to_string(newSnakeHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromSnake) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");

				//player->getDeathAction()[0]
			}
			
			if(newSnakeHp <= 0){
				//monster die
				for (int r = 0; r < cSnake->getDeathAction().size(); r++){
					if(cSnake->getDeathAction()[r]->getActionName().compare("YouWin") == 0){
						
						std::string endMessage = cSnake->getDeathAction()[r]->getMessage();
						grid->writeLine(2, endMessage);
						std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
						grid->writeLine(1, topMessage);	
						grid->update();
					}

					//std::string message = "Monster Dies\n";
					std::string message = "Snake Hp: " + std::to_string(snakeHp) +
									"  Snake got damaged: " + std::to_string(randomHitFromPlayer) +
									"  Snake New Hp: " + std::to_string(newSnakeHp) +
									"\nPlayer Hp: " + std::to_string(playerHp) +
									"  Player got damaged: " + std::to_string(randomHitFromSnake) +
									"  Player New Hp: " + std::to_string(newPlayerHp);
					grid->writeLine(2, message + "");

					//int addScore = snake->getDeathAction()[1]->getIntValue();

					grid->removeStackObj(tempX, tempY);
					//if (is_hallucinate == 1)
					if (is_hallucinate == 1){
						char e = grid->topObjectFromDisplay(tempX, tempY);
						grid->removeObjectFromDisplay(tempX, tempY);
						grid->removeObjectFromDisplay(tempX, tempY);
						grid->addObjectToDisplay(e, tempX, tempY);
					}					
										
					else{
						grid->removeObjectFromDisplay(tempX, tempY);
					}
				}
			}

			if(newSnakeHp > 0 && newPlayerHp > 0){
				std::string message = "Snake Hp: " + std::to_string(snakeHp) +
								 "  Snake got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Snake New Hp: " + std::to_string(newSnakeHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromSnake) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");
			}
			std::string message1 = "Score: X";
			message1 += "  ";
			message1 += "remain hp: ";
			message1 +=  std::to_string(player->getHp());
			grid->writeLine(1, message1 + "");

			return 0;
		}

		case 'T':{
			if (is_hallucinate == 1){
				return 0;
			}			
			Displayable *troll = grid->topObjStack(tempX, tempY);

			Creature *cTroll = dynamic_cast<Creature*>(troll);

			
			int trollHp = troll->getHp();
			int playerHp = player->getHp();

			int randomHitFromTroll = rand() % (troll->getMaxHit()+1);
			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			if (is_hallucinate == 1){
				randomHitFromTroll = 0;
			}

			int newTrollHp = trollHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromTroll;

			player->setHp(newPlayerHp);
			troll->setHp(newTrollHp);


			//monster hit actions
			//teleport the troll
			for (int r = 0; r < cTroll->getHitAction().size(); r++){
				//hit action for teleport
				//std::cout << "hiiii" << std::endl;
				if (cTroll->getHitAction()[r]->getActionName().compare("Teleport") == 0){

					char e = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					Displayable *tempMonster = grid->topObjStack(tempX, tempY);
					
					int gridHeight = grid->getHeight();
					int gridWidth = grid->getWidth();
					int newGridHeight = rand() % (gridHeight + 1);
					int newGridWidth = rand() % (gridWidth + 1);

					int flag = 1;
					while(flag == 1){
						char x = grid->topObjectFromDisplay(newGridWidth, newGridHeight);

						if (x != ' ' && x != 'X'){
							grid->addObjectToDisplay(e, newGridWidth, newGridHeight);
							grid->addObj(tempMonster, newGridWidth, newGridHeight);
							flag = 0;
							
						}
						else{
							newGridHeight = rand() % (gridHeight + 1);
							newGridWidth = rand() % (gridWidth + 1);
							flag = 1;
						}
					}
					std::string teleportMessage = cTroll->getHitAction()[r]->getMessage();
					
					grid->writeLine(2, teleportMessage);
					grid->update();

				} 
			}

			//player hit actions
			for (int r = 0; r < player->getHitAction().size(); r++){
		
				//std::cout << "hiiii" << std::endl;
				if (player->getHitAction()[r]->getActionName().compare("DropPack") == 0){
					
					for (int u = 0; u < player->getIteminPack().size(); u++){
						Item* tempItem = player->getIteminPack().at(u);

						if(dynamic_cast<Scroll*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('?', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());


							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();
							break;
						}
						else if(dynamic_cast<Armor*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay(']', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());



							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();	
							break;
						}
						else if(dynamic_cast<Sword*>(tempItem) != nullptr){
							player->dropItemfromPack(u);
							
							grid->removeObjectFromDisplay(player->getPosX(), player->getPosY());
							grid->addObjectToDisplay(')', player->getPosX(), player->getPosY());
							grid->addObjectToDisplay('@', player->getPosX(), player->getPosY());

							Displayable *playerTemp = grid->topObjStack(player->getPosX(), player->getPosY());

							grid->removeStackObj(player->getPosX(), player->getPosY());
							grid->addObj(static_cast<Displayable*>(tempItem), player->getPosX(), player->getPosY());
							grid->addObj(playerTemp, player->getPosX(), player->getPosY());


							std::string dropMessage = player->getHitAction()[r]->getMessage();
							grid->writeLine(2, dropMessage);
							grid->update();	
							break;				
						}	
						else if (u == (player->getIteminPack().size() - 1)){
							std::string dropMessage = "No item to be dropped from hit action";
							grid->writeLine(2, dropMessage);
							grid->update();
							break;
						}
					}
				} 
			}

			if(newPlayerHp <= 0){
				//player die
				char y = '\0';

				for (int r = 0; r < player->getDeathAction().size(); r++){
					if (player->getDeathAction()[r]->getActionName().compare("ChangeDisplayedType") == 0){
						
						if (player->getDeathAction()[r]->getCharValue() != '\0'){
							char y = player->getDeathAction()[r]->getCharValue();
							int posx = player->getPosX();
							int posy = player->getPosY();
							grid->removeObjectFromDisplay(posX, posY);
							grid->addObjectToDisplay(y, posx, posy);
							grid->update();
							//std::cout << "y val: " << y << std::endl;
						}
					}

					else if(player->getDeathAction()[r]->getActionName().compare("UpdateDisplay") == 0){
						if (y != '\0'){
							
							std::cout << "y 2 val: " << y << std::endl;

							//int posx = player->getPosX();
							//int posy = player->getPosY();
							grid->removeObjectFromDisplay(posX, posY);
							//grid->addObjectToDisplay(y, posx, posy);
							grid->update();
						}
					}

					else if(player->getDeathAction()[r]->getActionName().compare("EndGame") == 0){
						is_game = 1;
						//std::cout << "hey im in 3" << std::endl;
						std::string endMessage = player->getDeathAction()[r]->getMessage();
						grid->writeLine(2, endMessage);
						std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
						grid->writeLine(1, topMessage);	
						grid->update();
					}	
				}

				std::string message = "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(3, message + "");
				is_player = 1;
				return 0;

			}
			
			if(newTrollHp <= 0){
				//monster die
				//char y = '\0';

				for (int r = 0; r < cTroll->getDeathAction().size(); r++){

					if(cTroll->getDeathAction()[r]->getActionName().compare("YouWin") == 0){
						
						std::string endMessage = cTroll->getDeathAction()[r]->getMessage();
						grid->writeLine(2, endMessage);
						std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
						grid->writeLine(1, topMessage);	
						grid->update();
					}
				}

				//std::string message = "Monster Dies\n";
				std::string message = "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(3, message + "");

				grid->removeStackObj(tempX, tempY);

				if (is_hallucinate == 1){
					char e = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					grid->addObjectToDisplay(e, tempX, tempY);

				}
				
				else{
					grid->removeObjectFromDisplay(tempX, tempY);
				}

			}

			if(newTrollHp > 0 && newPlayerHp > 0){
				std::string message = "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(3, message + "");
			}
			/*
			std::string message1 = "Score: X";
			message1 += "  ";
			message1 += "remain hp: ";
			message1 +=  std::to_string(player->getHp());
			grid->writeLine(2, message1 + "");
			*/
			return 0;
		}

		case 'H':{
			if (is_hallucinate == 1){
				return 0;
			}			
			Displayable *hobgoblin = grid->topObjStack(tempX, tempY);

			Creature *cHob = dynamic_cast<Creature*>(hobgoblin);

			int hobgoblinHp = hobgoblin->getHp();
			int playerHp = player->getHp();

			int randomHitFromHobgoblin = rand() % (hobgoblin->getMaxHit()+1);
			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			if (is_hallucinate == 1){
				randomHitFromHobgoblin = 0;
			}
			
			int newHobgoblinHp = hobgoblinHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromHobgoblin;

			player->setHp(newPlayerHp);
			hobgoblin->setHp(newHobgoblinHp);

			if(newPlayerHp <= 0){
				//player die
				char y = '\0';

				for (int r = 0; r < player->getDeathAction().size(); r++){
					if (player->getDeathAction()[r]->getActionName().compare("ChangeDisplayedType") == 0){
						
						if (player->getDeathAction()[r]->getCharValue() != '\0'){
							char y = player->getDeathAction()[r]->getCharValue();
							int posx = player->getPosX();
							int posy = player->getPosY();
							grid->removeObjectFromDisplay(posX, posY);
							grid->addObjectToDisplay(y, posx, posy);
							grid->update();
							//std::cout << "y val: " << y << std::endl;
						}
					}

					else if(player->getDeathAction()[r]->getActionName().compare("UpdateDisplay") == 0){
						if (y != '\0'){
							
							std::cout << "y 2 val: " << y << std::endl;

							//int posx = player->getPosX();
							//int posy = player->getPosY();
							grid->removeObjectFromDisplay(posX, posY);
							//grid->addObjectToDisplay(y, posx, posy);
							grid->update();
						}
					}

					else if(player->getDeathAction()[r]->getActionName().compare("EndGame") == 0){
						is_game = 1;
						//std::cout << "hey im in 3" << std::endl;
						std::string endMessage = player->getDeathAction()[r]->getMessage();
						grid->writeLine(2, endMessage);
						std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
						grid->writeLine(1, topMessage);	
						grid->update();
					}	
				}

				std::string message = "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(3, message + "");
				is_player = 1;

				return 0;

				/*
				//player die
				std::string message = "Player Dies\n";
				message += "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");
				*/
			}
			
			  if(newHobgoblinHp <= 0){
				//monster die

				for (int r = 0; r < cHob->getDeathAction().size(); r++){

					if(cHob->getDeathAction()[r]->getActionName().compare("YouWin") == 0){
						
						std::string endMessage = cHob->getDeathAction()[r]->getMessage();
						grid->writeLine(2, endMessage);
						std::string topMessage = "HP: " + std::to_string(playerHp) + "     Score: 0";
						grid->writeLine(1, topMessage);	
						grid->update();
					}
				}				

				//std::string message = "Monster Dies\n";
				std::string message = "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");

				grid->removeStackObj(tempX, tempY);

				if (is_hallucinate == 1){
					char e = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					grid->addObjectToDisplay(e, tempX, tempY);
			//if (is_hallucinate == 1){
				}
				else{				
					grid->removeObjectFromDisplay(tempX, tempY);
				}
			}

			if(newHobgoblinHp > 0 && newPlayerHp > 0){
				std::string message = "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");
			}
			std::string message1 = "Score: X";
			message1 += "  ";
			message1 += "remain hp: ";
			message1 +=  std::to_string(player->getHp());
			grid->writeLine(1, message1 + "");

			return 0;
		}

		default:{
			if (is_hallucinate == 0){
				grid->addObjectToDisplay('@', tempX, tempY); //add the character display in the future positoin
				grid->addObj(player, tempX, tempY); //add the player on the object stack in the future place

				//std::cout << "before remove" <<std::endl;
				/*
				if (is_hallucinate == 1){
						std::cout << "hiiiiiiiiiiuuuu" << std::endl;
				}*/
				grid->removeObjectFromDisplay(x, y);
				grid->removeStackObj(x, y);

				//std::cout << "before set posx" <<std::endl;

				//player->
				player->SetPosX(tempX);

				//std::cout << "after set posx" <<std::endl;

				player->setPosY(tempY);
			}
			else if (is_hallucinate == 1){
				char d = grid->topObjectFromDisplay(tempX, tempY);
				grid->removeObjectFromDisplay(tempX, tempY);
				grid->addObjectToDisplay('@', tempX, tempY);
				grid->addObj(player, tempX, tempY);
				grid->addObjectToDisplay(d, tempX, tempY);

				char f = grid->topObjectFromDisplay(x, y);
				grid->removeObjectFromDisplay(x, y);
				grid->removeObjectFromDisplay(x, y);
				grid->addObjectToDisplay(f, x, y);
				grid->removeStackObj(x, y);

				int gameHeight = grid->getHeight();
				
				int width = grid->getWidth();
				//std::vector<Player*> players = handler->getPlayers();
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < gameHeight; j++) {
								
						char c = grid->topObjectFromDisplay(i,j);

						if (c != ' ' ){
						//if (c != ' ' && c!= '@'){
							grid->removeObjectFromDisplay(i, j);
						}
						/*
						else if (c == '@'){
							char c = grid->topObjectFromDisplay(i, j);
							grid->removeObjectFromDisplay(i, j);
							grid->removeObjectFromDisplay(i, j);
							grid->addObjectToDisplay(c, i, j);
						}*/

					}
				}				
				
				std::vector<char> vec{'#', 'T', 'S', 'H', '.', '+', 'X', ')', ']', '?'};
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < gameHeight; j++) {
						
						char c = grid->topObjectFromDisplay(i,j);
						
						if (c != ' '){
						//if (c != ' ' && c != '@'){
							int val = rand() % (vec.size()+1);
							char e = vec[val];

							grid->addObjectToDisplay(e, i, j);
						}
					}
    			}
			}
			
			return 1;
		}
	}
}


int KeyboardListener::checkCurrent(Player *player, ObjectDisplayGrid *grid, char action) {
	//clear the board
	grid->writeLine(2, "\n\n\n\n\n\n\n\n\n\n");

	int posX = player->GetCreaturePosX();
	int posY = player->GetCreaturePosY();

	int x = posX;
	int y = posY;

	int tempX = x;
	int tempY = y;

	//char a = grid->topObjectFromDisplay(tempX, tempY);

	switch (action){
		//for pick up, it only pick up all the items at the place
		case 'p':{
			//check if there is anything to pick up
			//use dynamic cast to make sure it's item
			
			/*
			//CHECK IF topObjectFromDisplay and topObjStack synchronous 
			char playerChar = grid->topObjectFromDisplay(tempX, tempY);
			
			if(dynamic_cast<Creature*>(grid->topObjStack(tempX, tempY)) != nullptr){//If it's creature, include player or monster
				if(playerChar == '@'){//If it's player
					std::cout << "Check player is synchronous";
					exit(3);
				}
			}else if(dynamic_cast<Item*>(grid->topObjStack(tempX, tempY)) != nullptr){//It it's Item
				if(playerChar == '@'){
					std::cout << "Check player is NOT synchronous";
					exit(3);
				}
			}
			*/
			
			//Jack's Code Don't Change

			char playerChar = grid->topObjectFromDisplay(tempX, tempY);
			

			grid->removeObjectFromDisplay(tempX, tempY);
			Displayable* playerPtr = grid->topObjStack(tempX, tempY);
			grid->removeStackObj(tempX, tempY);

			if(dynamic_cast<Item*>(grid->topObjStack(tempX, tempY)) != nullptr){
				int checkPackFull = 0;
				for(int i = 0; i < player->getIteminPack().size(); i++){//put it in the empty slot in pack
					if(player->getIteminPack().at(i) == nullptr){
						Displayable* itemTemp = grid->topObjStack(tempX, tempY);
						grid->removeStackObj(tempX, tempY);
						Item* tempItem = static_cast<Item*>(itemTemp);
						player->addItemintoPack(i, tempItem);
						grid->removeObjectFromDisplay(tempX, tempY);

						std::string message = "Item Pack\n";

						for(int i = 0; i < player->getIteminPack().size(); i++){
							Item* tempItem = player->getIteminPack().at(i);
							if(dynamic_cast<Scroll*>(tempItem) != nullptr){
								message += std::to_string(i);
								message += ": ";
								message += static_cast<Scroll*>(tempItem)->getName();
								message += " ";
							}
							
							else if(dynamic_cast<Armor*>(tempItem) != nullptr){
								message += std::to_string(i);
								message += ": ";
								message += static_cast<Armor*>(tempItem)->getName();
								message += " ";
							}
							
							else if(dynamic_cast<Sword*>(tempItem) != nullptr){
								message += std::to_string(i);
								message += ": ";
								message += static_cast<Sword*>(tempItem)->getName();
								message += " ";
							}
							
							else{
								message += std::to_string(i);
								message += ": ";
								message += "empty";
								message += " ";
							}
						}
						grid->writeLine(2, message + "");
						
						break;
					}
					if(i == player->getIteminPack().size()-1){
						checkPackFull = 1;
					}
				}
				if(checkPackFull == 1){//pack is full
					std::string message = "Bro, your pack is full!";
					grid->writeLine(2, message + "");
					break;
				}
				
			} else{
				break;
			}
			
			grid->addObjectToDisplay(playerChar, tempX, tempY);
			grid->addObj(playerPtr, tempX, tempY);
			
			break;
		}

		case 'd':{//for drop off, it only drop one item
			//Show the inventory
			std::string message = "Choose one item to drop(press other keys to exit): \n";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				}else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}else if(dynamic_cast<Sword*>(tempItem) != nullptr){


					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";
				}else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			grid->writeLine(2, message);
			grid->update();
			//Wait for user to choose one to throw
			char input = std::tolower(getchar());
			
			Item* droppedItem = nullptr;
			int dropNum = -1;
			switch(input){
				case '0':
					droppedItem = player->dropItemfromPack(0);
					dropNum = 0;
					break;
				case '1':
					droppedItem = player->dropItemfromPack(1);
					dropNum = 1;
					break;
				case '2':
					droppedItem = player->dropItemfromPack(2);
					dropNum = 2;
					break;
				case '3':
					droppedItem = player->dropItemfromPack(3);
					dropNum = 3;
					break;
				case '4':
					droppedItem = player->dropItemfromPack(4);
					dropNum = 4;
					break;
				case '5':
					droppedItem = player->dropItemfromPack(5);
					dropNum = 5;
					break;
				case '6':
					droppedItem = player->dropItemfromPack(6);
					dropNum = 6;
					break;
				case '7':
					droppedItem = player->dropItemfromPack(7);
					dropNum = 7;
					break;
				case '8':
					droppedItem = player->dropItemfromPack(8);
					dropNum = 8;
					break;
				case '9':
					droppedItem = player->dropItemfromPack(9);
					dropNum = 9;
					break;
				default:
					break;
			}

			//Print out the new invertory
			grid->writeLine(2, "\n\n\n\n\n");
			//Show the inventory
			if(droppedItem == nullptr){
				message = "No item is dropped, try again with another key\n";
				return 1;
			}

			else{
				message = "Item: ";
				if(dynamic_cast<Scroll*>(droppedItem) != nullptr){
					//pop out player first
					message += static_cast<Scroll*>(droppedItem)->getName();
					char playerChar = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					Displayable* playerPtr = grid->topObjStack(tempX, tempY);
					grid->removeStackObj(tempX, tempY);
					//push in item
					grid->addObj(static_cast<Displayable*>(droppedItem), x, y);
            		grid->addObjectToDisplay('?', x, y);
					//push back player
					grid->addObjectToDisplay(playerChar, tempX, tempY);
					grid->addObj(playerPtr, tempX, tempY);
				}

				else if(dynamic_cast<Armor*>(droppedItem) != nullptr){
					//pop out player first
					if(is_wear_armor == 1){
						is_wear_armor = 0;
					}

					message += static_cast<Armor*>(droppedItem)->getName();
					char playerChar = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					Displayable* playerPtr = grid->topObjStack(tempX, tempY);
					grid->removeStackObj(tempX, tempY);
					//push in item
					grid->addObj(static_cast<Displayable*>(droppedItem), x, y);
            		grid->addObjectToDisplay(']', x, y);
					//push back player
					grid->addObjectToDisplay(playerChar, tempX, tempY);
					grid->addObj(playerPtr, tempX, tempY);
				}

				else if(dynamic_cast<Sword*>(droppedItem) != nullptr){

					if (is_wield_sword == 1 && (packSwordNum == dropNum)){
						is_wield_sword = 0;
						int reduceHit = tempSword->getIntValue();
						int currHit = player->getMaxHit();
						currHit = currHit - reduceHit;
						player->setMaxHit(currHit);
					}

					//pop out player first
					message += static_cast<Sword*>(droppedItem)->getName();
					char playerChar = grid->topObjectFromDisplay(tempX, tempY);
					grid->removeObjectFromDisplay(tempX, tempY);
					Displayable* playerPtr = grid->topObjStack(tempX, tempY);
					grid->removeStackObj(tempX, tempY);
					//push in item
					grid->addObj(static_cast<Displayable*>(droppedItem), x, y);
            		grid->addObjectToDisplay(')', x, y);
					//push back player
					grid->addObjectToDisplay(playerChar, tempX, tempY);
					grid->addObj(playerPtr, tempX, tempY);
				}
				message += " is dropped\n";
			}

			message += "new inventory: \n";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				}
				
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}
				
				else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";
				}
				
				else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			grid->update();
			grid->writeLine(2, message + "");

			//when q update the info and push it back to stacks
			break;
		}

		case 'i':{
			//std::cout << "pressed i" << std::endl;
			std::string message = "Inventory: ";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				}
				
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){

					message += std::to_string(i);
					message += ": Armor - Strength: ";

					if(is_scroll == 1 && is_wear_armor == 1){
						//std::cout << "in is scroll" << std::endl;
						int x = static_cast<Armor*>(tempItem)->getIntValue();
						//std::cout << "x vaal: change hp:  " << x << " " << changeHp << std::endl;
						x = x + changeHp;
						message += std::to_string(x);
					}
					else{
						int x = static_cast<Armor*>(tempItem)->getIntValue();
						message += std::to_string(x);
					}

//					message += 
					//message += static_cast<Armor*>(tempItem)->getName();
					if (is_wear_armor == 1){
						if(dynamic_cast<Armor*>(tempItem) == tempArmor){
							message += "(a)";
						}
						//message += "(a)";
					}
					message += " ";
				}
				
				else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": Sword - Strength: ";

					if(is_wield_sword == 1){
						//std::cout << "in is scroll" << std::endl;
						//int x = static_cast<Sword*>(tempItem)->getIntValue();

						//std::cout << "x vaal: change hp:  " << x << " " << changeHp << std::endl;
						//x = x + changeHp;
						message += std::to_string(swordHit);
					}
					else{
						int x = static_cast<Sword*>(tempItem)->getIntValue();
						message += std::to_string(x);




					}

					//static_cast<Sword*>(tempItem)->getMaxHit
				//	message += static_cast<Sword*>(tempItem)->getName();
					if (is_wield_sword == 1){
						message += "(w)";
					}
					message += " ";
				}
				
				else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			grid->writeLine(2, message + "");
			break;
		}

		case 'r':{
			//for drop off, it only drop one item
			//Show the inventory
			std::string message = "Choose one item to read(press other keys to exit): \n";

			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				//	std::cout << " " << tempItem.  <<std::endl;


				}else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";
				}else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}

			grid->writeLine(2, message);
			grid->update();

			//Wait for user to choose one to read
			char input = std::tolower(getchar());
			
			Item* readItem = nullptr;
			switch(input){
				case '0':
					readItem = player->dropItemfromPack(0);
					break;
				case '1':
					readItem = player->dropItemfromPack(1);
					break;
				case '2':
					readItem = player->dropItemfromPack(2);
					break;
				case '3':
					readItem = player->dropItemfromPack(3);
					break;
				case '4':
					readItem = player->dropItemfromPack(4);
					break;
				case '5':
					readItem = player->dropItemfromPack(5);
					break;
				case '6':
					readItem = player->dropItemfromPack(6);
					break;
				case '7':
					readItem = player->dropItemfromPack(7);
					break;
				case '8':
					readItem = player->dropItemfromPack(8);
					break;
				case '9':
					readItem = player->dropItemfromPack(9);
					break;
				default:
					break;
			}

			//Print out the new invertory
			grid->writeLine(2, "\n\n\n\n\n");
			//Show the inventory

			if(readItem == nullptr){
				message = "No item is read \n";
				grid->writeLine(2, message);
				return 1;
			}
			
			//std::cout << "read Item ction" << readItem->getItemAction().at(0)->getActionName() << std::endl ;
			std::string action_name = readItem->getItemAction().at(0)->getActionName();
			actionVal = readItem->getItemAction().at(0)->getIntValue();
			
			if(action_name.compare("BlessArmor") == 0){
				char typeBless = readItem->getItemAction().at(0)->getCharValue();
				if(typeBless == 'a'){ 
					if (is_wear_armor == 1){

						is_scroll = 1;
						changeHp = readItem->getItemAction().at(0)->getIntValue();
						armor_strength = changeHp;
						int currHp = player->getHp();
						currHp = currHp + changeHp;
						player->setHp(currHp);
						//message += readItem->getItemAction()[0]->getMessage();
						//grid->update();
						message += "\n";
						//grid->writeLine(2, "\n\n\n\n\n");
					}
					else if (is_wear_armor == 0){
						message += "\nArmor not being worn!\n";
						grid->writeLine(2, message);
					}	
				}
			}
			else if(action_name.compare("Hallucinate") == 0){
				is_hallucinate = 1;
				int gameHeight = grid->getHeight();
				
				int width = grid->getWidth();
				//std::vector<Player*> players = handler->getPlayers();

				std::vector<char> vec{'#', 'T', 'S', 'H', '.', '+', 'X', ')', ']', '?'};

				for (int i = 0; i < width; i++) {
					for (int j = 0; j < gameHeight; j++) {
						
						char c = grid->topObjectFromDisplay(i,j);
						
						if (c != ' '){
						//if (c != ' ' && c != '@'){
							int val = rand() % (vec.size()+1);
							char e = vec[val];


							grid->addObjectToDisplay(e, i, j);
						}
					}
    			}
			}
			else{
				message = "Item: ";
				message += static_cast<Scroll*>(readItem)->getName();

				message += " is used up but wasn't applied\n";
			}

			//grid->update();
			grid->writeLine(2, "\n\n\n\n\n");
			grid->update();
			message+= "\n";
			message += readItem->getItemAction()[0]->getMessage();
			grid->update();
			message += " \nNew inventory: \n";

			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				}
				
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}
				
				else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";
				}
				
				else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}

			grid->writeLine(2, message + "");
			//when q update the info and push it back to stacks
			break;
		}

		case 'w':{
			//Show the inventory
			std::string message = "Choose Armor item to wear(press other keys to exit): \n";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);

				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				//	std::cout << " " << tempItem.  <<std::endl;
				}else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";				
				}
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			grid->writeLine(2, message);
			grid->update();
			//Wait for user to choose one to throw
			char input = std::tolower(getchar());
			
			Item* wearArmor = nullptr;
			int packNum = -1;
			switch(input){
				case '0':
					wearArmor = player->getItemfromPack(0);
					packNum = 0;
					break;
				case '1':
					wearArmor = player->getItemfromPack(1);
					packNum = 1;
					break;
				case '2':
					wearArmor = player->getItemfromPack(2);
					packNum = 2;
					break;
				case '3':
					wearArmor = player->getItemfromPack(3);
					packNum = 3;
					break;
				case '4':
					wearArmor = player->getItemfromPack(4);
					packNum = 4;
					break;
				case '5':
					wearArmor = player->getItemfromPack(5);
					packNum = 5;
					break;
				case '6':
					wearArmor = player->getItemfromPack(6);
					packNum = 6;
					break;
				case '7':
					wearArmor = player->getItemfromPack(7);
					packNum = 7;
					break;
				case '8':
					wearArmor = player->getItemfromPack(8);
					packNum = 8;
					break;
				case '9':
					wearArmor = player->getItemfromPack(9);
					packNum = 9;
					break;
				default:
					break;
			}

			//Print out the new invertory
			grid->writeLine(2, "\n\n\n\n\n");
			//Show the inventory
			if(wearArmor == nullptr){
				message = "\nNo armor is worn \n";
				grid->writeLine(2, message);
				grid->update();
				return 1;
			}
			else if (is_wear_armor == 0){
				

				if(dynamic_cast<Armor*>(wearArmor) != nullptr){
					if (is_wear_armor == 0){
						//pop out player first
						message += "\n";
						message += static_cast<Armor*>(wearArmor)->getName();
						tempArmor = wearArmor;

						
						int addHp = wearArmor->getIntValue();
						//int addHp = 8;

						int currHp = player->getHp();
						addHp = addHp + currHp;
						player->setHp(addHp);
						is_wear_armor = 1;
						//player->dropItemfromPack(packNum);
				
					}
					message += " is worn\n";
				}
				else if(dynamic_cast<Sword*>(wearArmor) != nullptr){
					message += "\nCannot wear a sword! ";
					grid->writeLine(2, message);
					grid->update();
					return 1;
				}

				message += "new inventory: \n";
				for(int i = 0; i < player->getIteminPack().size(); i++){
					Item* tempItem = player->getIteminPack().at(i);
					if(dynamic_cast<Scroll*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Scroll*>(tempItem)->getName();
						message += " ";
					}
					else if(dynamic_cast<Armor*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Armor*>(tempItem)->getName();
						message += " ";
					}
					else if(dynamic_cast<Sword*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Sword*>(tempItem)->getName();
						message += " ";
					}	
					else{
						message += std::to_string(i);
						message += ": ";
						message += "empty";
						message += " ";
					}
				}
			}
			else{
					message += "An armor is already being worn!";
			}
			
			grid->writeLine(2, message + "");
			//when q update the info and push it back to stacks
			break;			
		}
	
		case 'c':{
			//Show the inventory
			std::string message = "Armor will move back to the pack \n";
			if (is_wear_armor == 1){
/*
				for(int i = 0; i < player->getIteminPack().size(); i++){//put it in the empty slot in pack
					if(player->getIteminPack().at(i) == nullptr){
						//Item* tempItem = static_cast<Item*>(tempArmor);
						player->addItemintoPack(i, tempArmor);
						int tempHp = player->getHp();
						int armorHp = tempArmor->getIntValue();
						tempHp = tempHp - armorHp;
						player->setHp(tempHp);
						is_wear_armor = 0;
						armor_strength = 0;
						break;
					}
				}
*/
				int tempHp = player->getHp();
				int armorHp = tempArmor->getIntValue();
				tempHp = tempHp - armorHp;
				player->setHp(tempHp);
				is_wear_armor = 0;
				armor_strength = 0;
			}	
			else{
				message += "No armor is being worn! \n";
				grid->writeLine(2, message);
			}

			message += "Inventory: \n";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);
				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				}
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}
				else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";
				}	
				else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			
			grid->writeLine(2, message + "");
			break;			
		}

		case 't':{
			//Show the inventory
			std::string message = "Choose Sword to wield (press other keys to exit): \n";
			for(int i = 0; i < player->getIteminPack().size(); i++){
				Item* tempItem = player->getIteminPack().at(i);

				if(dynamic_cast<Scroll*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Scroll*>(tempItem)->getName();
					message += " ";
				//	std::cout << " " << tempItem.  <<std::endl;
				}else if(dynamic_cast<Sword*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Sword*>(tempItem)->getName();
					message += " ";				
				}
				else if(dynamic_cast<Armor*>(tempItem) != nullptr){
					message += std::to_string(i);
					message += ": ";
					message += static_cast<Armor*>(tempItem)->getName();
					message += " ";
				}else{
					message += std::to_string(i);
					message += ": ";
					message += "empty";
					message += " ";
				}
			}
			grid->writeLine(2, message);
			grid->update();
			//Wait for user to choose one to throw
			char input = std::tolower(getchar());
			
			Item* wieldSword = nullptr;
			//int packNum = -1;
			switch(input){
				case '0':
					wieldSword = player->getItemfromPack(0);
					packSwordNum = 0;
					break;
				case '1':
					wieldSword = player->getItemfromPack(1);
					packSwordNum = 1;
					break;
				case '2':
					wieldSword = player->getItemfromPack(2);
					packSwordNum = 2;
					break;
				case '3':
					wieldSword = player->getItemfromPack(3);
					packSwordNum = 3;
					break;
				case '4':
					wieldSword = player->getItemfromPack(4);
					packSwordNum = 4;
					break;
				case '5':
					wieldSword = player->getItemfromPack(5);
					packSwordNum = 5;
					break;
				case '6':
					wieldSword = player->getItemfromPack(6);
					packSwordNum = 6;
					break;
				case '7':
					wieldSword = player->getItemfromPack(7);
					packSwordNum = 7;
					break;
				case '8':
					wieldSword = player->getItemfromPack(8);
					packSwordNum = 8;
					break;
				case '9':
					wieldSword = player->getItemfromPack(9);
					packSwordNum = 9;
					break;
				default:
					break;
			}
			//std::cout << "heyy" << std::endl;

			//Print out the new invertory
			grid->writeLine(2, "\n\n\n\n\n");
			//Show the inventory
			if(wieldSword == nullptr){
				message = "No sword is wielded \n";
				return 1;
			}
			else if (is_wield_sword == 0){
				
				if(dynamic_cast<Sword*>(wieldSword) != nullptr){
					if (is_wield_sword == 0){

						tempSword = wieldSword;
						//pop out player first
						message += "\n";
						message += static_cast<Sword*>(wieldSword)->getName();

						
						int addHit = wieldSword->getIntValue();
						swordHit = addHit;

						int currHit = player->getMaxHit();
						addHit = addHit + currHit;
						player->setMaxHit(addHit);

						is_wield_sword = 1;
						//player->dropItemfromPack(packNum);
					}
					message += " is wielded\n";
				}
				else if(dynamic_cast<Armor*>(wieldSword) != nullptr){
					message = "Armor cannot be wielded! \n";
					grid->writeLine(2, message);
					grid->update();
					return 1;	
				}

				message += "new inventory: \n";
				for(int i = 0; i < player->getIteminPack().size(); i++){
					Item* tempItem = player->getIteminPack().at(i);
					if(dynamic_cast<Scroll*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Scroll*>(tempItem)->getName();
						message += " ";
					}
					else if(dynamic_cast<Armor*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Armor*>(tempItem)->getName();
						message += " ";
					}
					else if(dynamic_cast<Sword*>(tempItem) != nullptr){
						message += std::to_string(i);
						message += ": ";
						message += static_cast<Sword*>(tempItem)->getName();
						message += " ";
					}	
					else{
						message += std::to_string(i);
						message += ": ";
						message += "empty";
						message += " ";
					}
				}
			}
			else{
				std::cout << "in else" << std::endl;
					message += "A sword is already wielded!";
			}
			
			grid->writeLine(2, message + "\n");
			//when q update the info and push it back to stacks
			break;			
		}
		case 'e':{
			char input = std::tolower(getchar());
			std::string message = "Game over, player pressed 'e'!";
			grid->writeLine(2, "Press 'y' or 'Y' to end the game");

			switch(input){
				case 'y':
					is_game = 1;
					//std::string message = "Game over, player pressed 'e'!";
					grid->writeLine(2, message);
					grid->update();					
					
					break;
				case 'Y':
					grid->writeLine(2, message);
					grid->update();						

					break;

				default:
					grid->writeLine(2, "'e' pressed but not confirmed with y/Y");
					grid->update();				
					break;
			}
			break;
		}

		case '?':{
			std::string message = "Possible Commands: 'h', 'j', 'k', 'l', 'w', 't', 'r', 'i', 'd', 'p', 'e', 'H', 'c', '?'";
			grid->writeLine(2, message);
			grid->update();
			break;
		}

		case 'H':{
			std::string message = "Press possible key to get more information!\n";
			grid->writeLine(2, message);
			grid->update();

			char input = getchar();

			switch(input){
				case 'h':
					message = "h: Move left";
					grid->writeLine(2, message);
					grid->update();
					break;
				case 'j':
					message = "j: Move down";
					grid->writeLine(2, message);					
					grid->update();
					break;

				case 'k':
					message = "k: Move up";
					grid->writeLine(2, message);					
					grid->update();

					break;

				case 'l':
					message = "l: Move right";
					grid->writeLine(2, message);					
					grid->update();

					break;

				case 'd':
					message = "d: Drop item";
					grid->writeLine(2, message);					
					grid->update();
					break;

				case 'p':
					message = "p: Pick item";
					grid->writeLine(2, message);					
					grid->update();
					break;	

				case 'i':
				message = "j: Move down";
					grid->writeLine(2, message);					
					grid->update();
					break;
				
				
				case 'r':
						message = "r: Read item";
					grid->writeLine(2, message);					
					grid->update();
					break;

				case 'w':
					message = "w: Wear item";
					grid->writeLine(2, message);					
					grid->update();					
					break;
				
				case 'c':
					message = "c: Change Armor";
					grid->writeLine(2, message);					
					grid->update();					
					break;
				case 't':
					message = "t: Take out a weapon";
					grid->writeLine(2, message);					
					grid->update();					
					break;
				case 'e':
					message = "e: End Game";
					grid->writeLine(2, message);					
					grid->update();					
					break;
				case '?':
					message = "?: List of possible key commands";
					grid->writeLine(2, message);					
					grid->update();					
					break;
				case 'H':
					message = "H: More detailed information about key command";
					grid->writeLine(2, message);					
					grid->update();
					break;	
				
				default:
					message = "Key does not exist! Press '?' for list of possible keys!";
					grid->writeLine(2, message);
					grid->update();

					break;
			}
				
			
			break;
		}		

	}
}
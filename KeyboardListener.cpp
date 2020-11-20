#include "KeyboardListener.hpp"
#include "Player.hpp"
#include "Scroll.hpp"
#include "Structure.hpp"
#include "Armor.hpp"
#include <sstream>
#include <iostream>
#include <stdio.h>

KeyboardListener::KeyboardListener(ObjectDisplayGrid* _grid, Player* _players) : grid(_grid), player(_players) {}

void KeyboardListener::run() {
	
	//grid->writeLine(0, "Press 'x' to exit");
	running = true;
	char input;
	do {
		// wait for next input
		// lowercase so 'x' and 'X' are treated as the same
		input = std::tolower(getchar());


		switch (input) {
		// press X to stop

		case 'h':
			checkFuture(player, grid, 'h');
			break;
		case 'j':
			checkFuture(player, grid, 'j');

			break;

		case 'k':
			checkFuture(player, grid, 'k');

			break;

		case 'l':
			checkFuture(player, grid, 'l');

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

		default:
			// C is not happy about appending a character to a string apparently
			std::string message = "Unknown key '";
			message += input;
			grid->writeLine(2, message + "'");
			break;
		}
		grid->update();
	} while (running && input != EOF);
}




int KeyboardListener::checkFuture(Player *player, ObjectDisplayGrid *grid, char direction){
	//clear the board
	grid->writeLine(2, "\n\n\n\n\n\n\n\n\n\n");

	int posX = player->GetCreaturePosX();
	int posY = player->GetCreaturePosY();

	int x = posX;
	int y = posY;

	//std::cout << "x and y pos: " << x << y << std::endl;

	int tempX = x;
	int tempY = y;

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
	//char a = 'j';
	//std::cout << "char a: " << a << std::endl;

	

	switch (a){
		case 'X':{

			return 0;
		}

		case ' ':{
			return 0;
		}

		case 'S':{
			Displayable *snake = grid->topObjStack(tempX, tempY);
			int snakeHp = snake->getHp();
			int playerHp = player->getHp();

			int randomHitFromSnake = rand() % (snake->getMaxHit()+1);
			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			int newSnakeHp = snakeHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromSnake;

			//snake->setHp(newSnakeHp);
			player->setHp(newPlayerHp);
			snake->setHp(newSnakeHp);

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
			}
			
			if(newSnakeHp <= 0){
				//monster die
				std::string message = "Monster Dies\n";
				message += "Snake Hp: " + std::to_string(snakeHp) +
								 "  Snake got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Snake New Hp: " + std::to_string(newSnakeHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromSnake) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");

				grid->removeStackObj(tempX, tempY);
				grid->removeObjectFromDisplay(tempX, tempY);
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
			Displayable *troll = grid->topObjStack(tempX, tempY);
			int trollHp = troll->getHp();
			int playerHp = player->getHp();

			int randomHitFromTroll = rand() % (troll->getMaxHit()+1);
			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			int newTrollHp = trollHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromTroll;

			player->setHp(newPlayerHp);
			troll->setHp(newTrollHp);

			if(newPlayerHp <= 0){
				//player die
				std::string message = "Player Dies\n";
				message += "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");
			}
			
			if(newTrollHp <= 0){
				//monster die
				std::string message = "Monster Dies\n";
				message += "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");

				grid->removeStackObj(tempX, tempY);
				grid->removeObjectFromDisplay(tempX, tempY);
			}

			if(newTrollHp > 0 && newPlayerHp > 0){
				std::string message = "Troll Hp: " + std::to_string(trollHp) +
								 "  Troll got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Troll New Hp: " + std::to_string(newTrollHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromTroll) +
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

		case 'H':{
			Displayable *hobgoblin = grid->topObjStack(tempX, tempY);
			int hobgoblinHp = hobgoblin->getHp();
			int playerHp = player->getHp();

			int randomHitFromHobgoblin = rand() % (hobgoblin->getMaxHit()+1);
			int randomHitFromPlayer = rand() % (player->getMaxHit()+1);

			int newHobgoblinHp = hobgoblinHp - randomHitFromPlayer;
			int newPlayerHp = playerHp - randomHitFromHobgoblin;

			player->setHp(newPlayerHp);
			hobgoblin->setHp(newHobgoblinHp);

			if(newPlayerHp <= 0){
				//player die
				std::string message = "Player Dies\n";
				message += "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");
			}
			
			if(newHobgoblinHp <= 0){
				//monster die
				std::string message = "Monster Dies\n";
				message += "Hobgoblin Hp: " + std::to_string(hobgoblinHp) +
								 "  Hobgoblin got damaged: " + std::to_string(randomHitFromPlayer) +
								 "  Hobgoblin New Hp: " + std::to_string(newHobgoblinHp) +
								 "\nPlayer Hp: " + std::to_string(playerHp) +
								 "  Player got damaged: " + std::to_string(randomHitFromHobgoblin) +
								 "  Player New Hp: " + std::to_string(newPlayerHp);
				grid->writeLine(2, message + "");

				grid->removeStackObj(tempX, tempY);
				grid->removeObjectFromDisplay(tempX, tempY);
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
			grid->addObjectToDisplay('@', tempX, tempY); //add the character display in the future positoin
			grid->addObj(player, tempX, tempY); //add the player on the object stack in the future place

			//std::cout << "before remove" <<std::endl;

			grid->removeObjectFromDisplay(x, y);
			grid->removeStackObj(x, y);

			//std::cout << "before set posx" <<std::endl;

			//player->
			player->SetPosX(tempX);

			//std::cout << "after set posx" <<std::endl;

			player->setPosY(tempY);
			
			return 1;
		}
	}
}

int KeyboardListener::checkCurrent(Player *player, ObjectDisplayGrid *grid, char action){
	//clear the board
	grid->writeLine(2, "\n\n\n\n\n\n\n\n\n\n");

	int posX = player->GetCreaturePosX();
	int posY = player->GetCreaturePosY();

	int x = posX;
	int y = posY;

	int tempX = x;
	int tempY = y;

	char a = grid->topObjectFromDisplay(tempX, tempY);

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
				}else{
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
			switch(input){
				case '0':
					droppedItem = player->dropItemfromPack(0);
					break;
				case '1':
					droppedItem = player->dropItemfromPack(1);
					break;
				case '2':
					droppedItem = player->dropItemfromPack(2);
					break;
				case '3':
					droppedItem = player->dropItemfromPack(3);
					break;
				case '4':
					droppedItem = player->dropItemfromPack(4);
					break;
				case '5':
					droppedItem = player->dropItemfromPack(5);
					break;
				case '6':
					droppedItem = player->dropItemfromPack(6);
					break;
				case '7':
					droppedItem = player->dropItemfromPack(7);
					break;
				case '8':
					droppedItem = player->dropItemfromPack(8);
					break;
				case '9':
					droppedItem = player->dropItemfromPack(9);
					break;
				default:
					break;
			}

			//Print out the new invertory
			grid->writeLine(2, "\n\n\n\n\n");
			//Show the inventory
			if(droppedItem == nullptr){
				message = "No item is dropped \n";
			}else{
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
				}else if(dynamic_cast<Armor*>(droppedItem) != nullptr){
					//pop out player first
					message += static_cast<Armor*>(droppedItem)->getName();
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
				}else if(dynamic_cast<Sword*>(droppedItem) != nullptr){
					//pop out player first
					message += static_cast<Sword*>(droppedItem)->getName();
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

			grid->writeLine(2, message + "");

			//when q update the info and push it back to stacks
			break;
		}

		case 'i':{
			std::string message = "";
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
			grid->writeLine(2, message + "");
		}
	}
}
#include "KeyboardListener.hpp"
#include "Player.hpp"
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
		case 'X':
			return 0;

		case ' ':
			return 0;

		case 'S':
			return 0;

		case 'T':
			return 0;

		case 'H':
			return 0;

		default:
			grid->addObjectToDisplay('@', tempX, tempY); 
			//std::cout << "before remove" <<std::endl;

			grid->removeObjectFromDisplay(x, y);

			//std::cout << "before set posx" <<std::endl;

			//player->
			player->SetPosX(tempX);

			//std::cout << "after set posx" <<std::endl;

			player->setPosY(tempY);
			
			return 1;

	}
/*
	grid->addObjectToDisplay('@', tempX, tempY); 
	//std::cout << "before remove" <<std::endl;

	grid->removeObjectFromDisplay(x, y);

	std::cout << "before set posx" <<std::endl;

	//player->
	player->SetPosX(tempX);

	std::cout << "after set posx" <<std::endl;

	player->setPosY(tempY);
	
	return 1;
*/
}
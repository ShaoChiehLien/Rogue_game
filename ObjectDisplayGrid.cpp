#include <iostream>
#include <string>
#include <curses.h>
#include "ObjectDisplayGrid.hpp"


//ObjectDisplayGrid::ObjectDisplayGrid(int _topHeight, int _width, int _topHeight) : width(_width), gameHeight(_gameHeight), topHeight(_topHeight){

ObjectDisplayGrid::ObjectDisplayGrid(int _gameHeight, int _width, int _topHeight) : width(_width), gameHeight(_gameHeight), topHeight(_topHeight){
 
 	// create the 2D array of grid characters
	// note if you want to write messages instead, ncurses
	objectGrid = new GridChar**[width];
	for (int i = 0; i < width; i++) {
		objectGrid[i] = new GridChar*[gameHeight];
		for (int j = 0; j < gameHeight; j++) {
			objectGrid[i][j] = NULL;
		}
	}

	// initialize ncurses

	// set command window size if running on windows, useful when running in Visual Studio
	// as far as I am aware, no way to do this on linux
    /*
	#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD size = { (short)width, (short)(height + messages) };
		SMALL_RECT DisplayArea = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1) };
		SetConsoleScreenBufferSize(handle, size);
		SetConsoleWindowInfo(handle, TRUE, &DisplayArea);
	#endif
	*/
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak(); 
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
 
    std::cout << "get gameheight: "<< _gameHeight << std::endl;
    std::cout << "get width: "<< _width << std::endl;
    std::cout << "get topHeight: "<< _topHeight << std::endl;

}

ObjectDisplayGrid::ObjectDisplayGrid(int _gameHeight, int _width, int _posX, int _posY) : width(_width), gameHeight(_gameHeight), posX(_posX), posY(_posY){
 
 	// create the 2D array of grid characters
	// note if you want to write messages instead, ncurses
	objectGrid = new GridChar**[width];
	for (int i = posX; i < width; i++) {
		objectGrid[i] = new GridChar*[gameHeight];
		for (int j = posY; j < gameHeight; j++) {
			objectGrid[i][j] = NULL;
		}
	}

	// initialize ncurses

	// set command window size if running on windows, useful when running in Visual Studio
	// as far as I am aware, no way to do this on linux
    /*
	#ifdef _WIN32
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD size = { (short)width, (short)(height + messages) };
		SMALL_RECT DisplayArea = { 0, 0, (short)(size.X - 1), (short)(size.Y - 1) };
		SetConsoleScreenBufferSize(handle, size);
		SetConsoleWindowInfo(handle, TRUE, &DisplayArea);
	#endif
	*/
	// initializes ncurses
	initscr();
	// makes characters typed immediately available, instead of waiting for enter to be pressed
	cbreak(); 
	// stops typed characters from being shown, makes it easier to get keypresses
	noecho();
	// clears the screen to start
	clear();
 
    std::cout << "get gameheight: "<< _gameHeight << std::endl;
    std::cout << "get width: "<< _width << std::endl;
   // std::cout << "get topHeight: "<< _topHeight << std::endl;

}







void ObjectDisplayGrid::setTopMessageHeight(int _topHeight){
     std::cout << "setting topHeight: "<< _topHeight << std::endl;
}

/*
ObjectDisplayGrid::ObjectDisplayGrid(int _gameHeight, int _width, int _topHeight){
    gameHeight = _gameHeight;
    width = _width;
    topHeight = _topHeight;
}
*/

ObjectDisplayGrid::~ObjectDisplayGrid() {
	// free memory from the dynamically sized object grid
	for (int i = 0; i < width; i++) {
		// delete all character objects in the grid
		for (int j = 0; j < gameHeight; j++) {
			delete objectGrid[i][j];
		}
		// delete the column
		delete[] objectGrid[i];
	}
	// delete the array of columns
	delete[] objectGrid;
	objectGrid = NULL;

	// free ncurses data
	endwin();
}

//void ObjectDisplayGrid::addObjectToDisplay(GridChar* ch, int x, int y, std::vector<Player*> players) {

void ObjectDisplayGrid::addObjectToDisplay(char ch, int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < width)) {
		// y between 0 and height
		if ((0 <= y) && (y < gameHeight)) {
			// delete existing character if present
			//if (objectGrid[x][y] != NULL) {
			//	delete objectGrid[x][y];
			//}

			if (objectGrid[x][y] == NULL) {
				objectGrid[x][y] = new GridChar;
			}

			// add new character to the internal character list
			//push char to objectgrid
			objectGrid[x][y]->pushChar(ch);


			//objectGrid[x][y]->pushObj(Obj);

			//objectGrid[x][y] = ch;
			// draws the character on the screen, note it is relative to 0,0 of the terminal
			mvaddch(y, x, ch);
		}
	}
}

void ObjectDisplayGrid::removeObjectFromDisplay(int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < width)) {
		// y between 0 and height
		if ((0 <= y) && (y < gameHeight)) {
			// delete existing character if present

			if (objectGrid[x][y] == NULL) {
				return;
				
			}
			
		
			

			// add new character to the internal character list
			//push char to objectgrid
			//std::cout << "before pop char" <<std::endl;

			objectGrid[x][y]->popChar();
			//std::cout << "before finding top" <<std::endl;

			bool check = objectGrid[x][y]->checkEmpty();
			char ch = ' ';

			if (check == false){ 
				ch = objectGrid[x][y]->findTop();
			}

			//objectGrid[x][y] = ch;
			// draws the character on the screen, note it is relative to 0,0 of the terminal
			mvaddch(y, x, ch);
		}
	}
}

char ObjectDisplayGrid::topObjectFromDisplay(int x, int y) {
	// note grid objects start from 0,0 and go until width,height
	// x between 0 and width
	if ((0 <= x) && (x < width)) {
		//std::cout << "Under first if statement" << std::endl;

		// y between 0 and height
		if ((0 <= y) && (y < gameHeight)) {
			// delete existing character if present
			//std::cout << "Before checking null" << std::endl;
			if (objectGrid[x][y] == NULL) {
							
				//std::cout << "inside null" << std::endl;

				return '\0';
				
			}
			
		
			

			// add new character to the internal character list
			//push char to objectgrid
			
			char ch = objectGrid[x][y]->findTop();
			return ch;
	
		}
	}
}

void ObjectDisplayGrid::update() {
	// refreshes ncurses
	refresh();
}

void ObjectDisplayGrid::writeLine(int line, std::string message) {
	// messages start from 0, height and go until width,(height + messages)
	mvaddstr(gameHeight + line, 0, message.c_str());
	// clear after what we wrote to EOL
	clrtoeol();
}

void ObjectDisplayGrid::addObj(Displayable *obj, int x, int y) {

	objectGrid[x][y]->pushObj(obj);
}


void ObjectDisplayGrid::removeStackObj(int x, int y) {


	bool check = objectGrid[x][y]->checkObjEmpty();
	if (check == false){
		objectGrid[x][y]->popObj();

	}
	//std::cout << "before finding top" <<std::endl;

	//bool check = objectGrid[x][y]->checkObjEmpty();
}

Displayable* ObjectDisplayGrid::topObjStack(int x, int y) {

	if (objectGrid[x][y] == NULL) {
					
		//std::cout << "inside null" << std::endl;

		return NULL;
		
	}
			
	// add new character to the internal character list
	//push char to objectgrid
			
	Displayable *obj = objectGrid[x][y]->findObjTop();
	return obj;
	
}

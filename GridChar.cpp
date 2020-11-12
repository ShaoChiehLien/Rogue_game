#include <iostream>
#include "GridChar.hpp"

//GridChar::GridChar(char _display) : display(_display) {}

GridChar::GridChar() {}

GridChar::~GridChar(){}

/*
char GridChar::getChar() {
	return display;
}
*/

void GridChar::pushChar(char charDisplay){
	stackDisplay.push(charDisplay);

}


char GridChar::findTop(){

	if (stackDisplay.empty() == true){
		std::cout << "stack is empty!" << std::endl;
	}
	char ch = stackDisplay.top();
	

	return ch;
}

bool GridChar::checkEmpty(){
	if (stackDisplay.empty() == true){
		return true;
	}
	return false;
}

void GridChar::popChar(){
	stackDisplay.pop();

}
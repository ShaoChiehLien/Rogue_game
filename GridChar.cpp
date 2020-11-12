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

//object stack functions

void GridChar::pushObj(Displayable *object){
	stackObj.push(object);

}



Displayable* GridChar::findObjTop(){

	if (stackObj.empty() == true){
		std::cout << "stack of objects is empty!" << std::endl;
	}
	Displayable *obj = stackObj.top();
	

	return obj;
}

bool GridChar::checkObjEmpty(){
	if (stackObj.empty() == true){
		return true;
	}
	return false;
}

void GridChar::popObj(){
	stackObj.pop();

}
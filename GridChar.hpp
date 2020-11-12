#include <stack>

#pragma once

/**
 * This class in its current form is simply a wrapper around a character.
 * However, it can easily be expanded to include other behaviors for a grid character.
 */
class GridChar {
private:
	//char display;
	std::stack <char> stackDisplay;

public:
	/**
	 * Creates a new grid character
	 * @param display Character to use for display
	 */

	GridChar();
	~GridChar();

	void pushChar(char charDisplay);
	char findTop();
	void popChar();
	bool checkEmpty();

	/**
	 * Gets the character used to display this grid character
	 * @return  Character to display
	 */
	//virtual char getChar();
};
#pragma once
#include <string>
#include "GridChar.h"

class ObjectDisplayGrid {
private:
	/** Keeps track of the characters on the screen */
	GridChar*** objectGrid;
	/** Keeps track of the consoles width and height */
	int height, width;

	/** Number of lines for message writing */
	int messages;

public:
	/**
	 * Creates a new display grid using the given parameters and initializes ncurses.
	 * Screen height will be grid height + messages
	 * @param width     Screen width
	 * @param height    Grid height
	 * @param messages  Number of lines to reserve in the message area
	 */
	ObjectDisplayGrid(int width, int height, int messages);

	/** Object deconstructor, to delete the grid character matrix and free ncurses data */
	~ObjectDisplayGrid();

	/**
	 * Refreshes the grid display
	 */
	virtual void update();

	/**
	 * Adds an object to the display grid
	 * @param ch  Object to display
	 * @param x   X position
	 * @param y   Y position
	 */
	virtual void addObjectToDisplay(GridChar* ch, int x, int y);

	/**
	 * Writes a line of text to the screen at the given line relative to the bottom
	 * @param line    line number
	 * @param message message to write
	 * @param update  If true, immediately updates the screen
	 */
	virtual void writeLine(int line, std::string message);
};


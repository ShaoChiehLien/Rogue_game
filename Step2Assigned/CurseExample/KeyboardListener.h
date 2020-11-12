#pragma once
#include "ObjectDisplayGrid.h"

class KeyboardListener {
private:
    /** Object display grid reference to write errors */
    ObjectDisplayGrid* grid;

    /** set to false to stop running the keyboard listener */
    bool running = false;

public:
    /**
     * Creates a new keyboard listener, you can pass in extra objects here to interact with them during the game if you wish
     * @param grid  Object display grid reference
     */
    KeyboardListener(ObjectDisplayGrid* grid);

    /**
     * Runs the keyboard listener in a thread
     */
    void run();
};


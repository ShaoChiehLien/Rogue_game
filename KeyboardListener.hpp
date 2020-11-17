#pragma once
#include "ObjectDisplayGrid.hpp"

class KeyboardListener {
private:
    /** Object display grid reference to write errors */
    ObjectDisplayGrid* grid;

    /** set to false to stop running the keyboard listener */
    bool running = false;

    Player* player;

public:
    /**
     * Creates a new keyboard listener, you can pass in extra objects here to interact with them during the game if you wish
     * @param grid  Object display grid reference
     */
    KeyboardListener(ObjectDisplayGrid* grid, Player* players);
    int checkFuture(Player *player, ObjectDisplayGrid *grid, char direction);
    int checkCurrent(Player *player, ObjectDisplayGrid *grid, char action);


    /**
     * Runs the keyboard listener in a thread
     */
    void run();
};


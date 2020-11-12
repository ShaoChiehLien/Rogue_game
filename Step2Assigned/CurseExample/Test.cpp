#include <atomic> 
#include <thread>
#include <sstream>
#include "ObjectDisplayGrid.h"
#include "GridChar.h"
#include "KeyboardListener.h"

// set to false when done running
std::atomic_bool isRunning(true);

// grid properties
int WIDTH = 150;
int HEIGHT = 40;
int MESSAGES = 5;

void runDisplay(ObjectDisplayGrid* grid) {

    // loop over each step, doubling each time
    // stop loop if isRunning is swapped to false
    for (int step = 1; (isRunning && step < WIDTH / 2); step *= 2) {
        // write a message, but don't update yet
        grid->writeLine(1, "Step " + std::to_string(step));

        // print characters to the screen
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                char c;
                if (i % step == 0 && j % step == 0) {
                    c = 'X';
                }
                else {
                    c = '.';
                }
                grid->addObjectToDisplay(new GridChar(c), i, j);
            }
        }

        // update the grid
        grid->update();

        // wait a bit to rejoin
        // wait in a few steps to update faster on keypress
        for (int i = 0; (isRunning && i < 5); i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
    }
}

int main() {
    // create an initialize the object display grid
    ObjectDisplayGrid grid(WIDTH, HEIGHT, MESSAGES);
    ObjectDisplayGrid* pGrid = &grid;

    // thread to wait for key press
    KeyboardListener listener(pGrid);
    std::thread keyboardThread(&KeyboardListener::run, &listener);

    // thread to update display
    std::thread displayThread(runDisplay, pGrid);

    // wait for the keyboard thread to finish, then notify the display to stop
    keyboardThread.join();
    isRunning = false;

    // wait for the display thread to finish
    displayThread.join();

    return 0;
}

#include <atomic> 
#include <thread>
#include <sstream>

#include <iostream>
#include <string>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "DungeonXMLHandler.hpp"
#include "KeyboardListener.hpp"
#include <exception>

std::atomic_bool isRunning(true);

int WIDTH;
int TOPHEIGHT;
int BOTTOMHEIGHT;
int GAMEHEIGHT;

void runNewDisplay(Dungeon* dObj, ObjectDisplayGrid *grid, DungeonXMLHandler *handler) {
    //get dungeon width and height
    //create the dungeon matrix

    grid->writeTop(1, "HP: 1000");


    int gameHeight = dObj->getHeight();
    int width = dObj->getWidth();
    //std::vector<Player*> players = handler->getPlayers();

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < gameHeight; j++) {

            char c = ' ';

            //grid->addObjectToDisplay(new GridChar(c), i, j);
            grid->addObjectToDisplay(c, i, j);
        }
    }
            //std::cout << "ibefore vector of player" << std::endl;

    
    //create room vector
    //create for loops to display each room from the vector
    std::vector<Room*> rooms = handler->getRooms();
/*
    for (int i = 0; i < rooms.size(); i++){
        Room *temp = rooms[i];
        std::cout << "room[i]: " <<  temp->toString() << std::endl;
    }
*/

    for (int i = 0; i < rooms.size(); i++){
        Room *temp = rooms[i];
      //  std::cout << "room[i]: " <<  temp->toString() << std::endl;

        std::vector<int> temp_posX = temp->GetPosX();
        std::vector<int> temp_posY = temp->GetPosY();

        int temp_width = temp->GetWidth();
        int temp_height = temp->GetHeight();

        //build interior of room
        for (int x = temp_posX[0] + 1; x < temp_posX[0] + temp_width - 1; x++) {
            for (int y = temp_posY[0] + 1; y < temp_posY[0] + temp_height - 1; y++) {
                char c = '.';

                //grid->addObjectToDisplay(new GridChar(c), x, y);
                grid->addObjectToDisplay(c, x, y);
            }
        }

        //build left wall
        for (int x = temp_posY[0]; x < temp_height + temp_posY[0]; x++) {
            int y = temp_posX[0];
            char c = 'X';

            //grid->addObjectToDisplay(new GridChar(c), y, x); 
            grid->addObjectToDisplay(c, y, x);
        }

        //build top wall
        for (int x = temp_posX[0]; x < temp_width + temp_posX[0]; x++) {
            int y = temp_posY[0];
            char c = 'X';

            //grid->addObjectToDisplay(new GridChar(c), x, y); 
            grid->addObjectToDisplay(c, x, y);
        }

        //build bottom wall

        for (int x = temp_posX[0]; x < temp_width + temp_posX[0]; x++) {
        
            int y = temp_posY[0] + temp_height - 1;
            char c = 'X';

            //grid->addObjectToDisplay(new GridChar(c), x, y); 
            grid->addObjectToDisplay(c, x, y);
        }

        //build right wall

        for (int x = temp_posY[0]; x < temp_height + temp_posY[0]; x++) {
            int y = temp_posX[0] + temp_width - 1;
            char c = 'X';

            //grid->addObjectToDisplay(new GridChar(c), y, x); 
            grid->addObjectToDisplay(c, y, x);
        }

    }

    //repeat previous calls for every item that needs to be displayed
    std::vector<Passage*> passages = handler->getPassages();

    for (int i = 0; i < passages.size(); i++){
        Passage *temp = passages[i];
      //  std::cout << "room[i]: " <<  temp->toString() << std::endl;

        std::vector<int> temp_posX = temp->GetPosX();
        std::vector<int> temp_posY = temp->GetPosY();

        for(int var = 0; var < temp_posX.size(); var++){
            //vertical line
            if (temp_posX[var] == temp_posX[var + 1]){

                if (temp_posY[var] < temp_posY[var + 1]){
                    for (int y = temp_posY[var]; y < temp_posY[var] + (temp_posY[var + 1] - temp_posY[var] + 1); y++){

                        char a = grid->topObjectFromDisplay(temp_posX[var], y);
                        char c;
                        if (a == 'X'){
                            c = '+';
                        }
                        else{
                            c = '#';
                        }
                        //grid->addObjectToDisplay(new GridChar(c), temp_posX[var], y); 
                        grid->addObjectToDisplay(c, temp_posX[var], y);
                    }
                }

                else{
                    // y = 5; y > 10 + 5 - 1; y--
                    for (int y = temp_posY[var + 1]; y < temp_posY[var]; y++){
                        //char c = '#';
                        char a = grid->topObjectFromDisplay(temp_posX[var], y);
                        char c;
                        if (a == 'X'){
                            c = '+';
                        }
                        else{
                            c = '#';
                        }

                        //grid->addObjectToDisplay(new GridChar(c), temp_posX[var], y); 
                        grid->addObjectToDisplay(c, temp_posX[var], y);
                    }
                }

            }

            //horizontal line
            else if (temp_posY[var] == temp_posY[var + 1]){

                if (temp_posX[var] < temp_posX[var + 1]){
                    for (int x = temp_posX[var]; x < temp_posX[var] + (temp_posX[var + 1] - temp_posX[var] + 1); x++){
                        char a = grid->topObjectFromDisplay(x, temp_posY[var]);

                        char c;
                        if (a == 'X'){
                            c = '+';
                        }
                        else{
                            c = '#';
                        }
                        //char c = '#';

                        //grid->addObjectToDisplay(new GridChar(c), x, temp_posY[var]); 
                        grid->addObjectToDisplay(c, x, temp_posY[var]);
                    }
                }

                else{
                    for (int x = temp_posX[var + 1]; x < temp_posX[var]; x++){
                        //char c = '#';
                        char a = grid->topObjectFromDisplay(x, temp_posY[var]);
                        char c;
                        if (a == 'X'){
                            c = '+';
                        }
                        else{
                            c = '#';
                        }

                        //grid->addObjectToDisplay(new GridChar(c), x, temp_posY[var]); 
                        grid->addObjectToDisplay(c, x, temp_posY[var]);
                    } 
                }
            }
        }
    }

    std::vector<Monster*> monsters = handler->getMonsters();

    for (int i = 0; i < monsters.size(); i++){
        Monster *temp_monster = monsters[i];
        int x;
        int y;

        if (temp_monster->getName() == "Troll"){
            int room_id = temp_monster->getRoomID();

            Room *temp_room = rooms[room_id - 1];

            std::vector<int> temp_room_posX = temp_room->GetPosX();
            std::vector<int> temp_room_posY = temp_room->GetPosY();

            //std::vector<int> temp_monst_posX = temp_monster->GetPosX();
            //;
            //std::vector<int> temp_monst_posY = temp_monster->GetPosY();
            int temp_monst_posX = temp_monster->GetCreaturePosX();
            int temp_monst_posY = temp_monster->GetCreaturePosY();

            ///////////////
/*
            for (int r = 0; r < temp_monster->getDeathAction().size(); r++){
                std::cout << temp_monster->getDeathAction()[r]->getActionName();
                std::cout << temp_monster->getDeathAction()[r]->getMessage();
            }
           // std::cout << temp_monster->getDeathAction()[1]->toString();
            exit(3);
*/

            x = temp_room_posX[0] + temp_monst_posX;
            y = temp_room_posY[0] + temp_monst_posY;

            char c = 'T';

            //grid->addObjectToDisplay(new GridChar(c), x, y); 
            grid->addObjectToDisplay(c, x, y);

            //new add obj to stack
            grid->addObj(temp_monster, x, y);
        }

        else if (temp_monster->getName() == "Snake"){
            int room_id = temp_monster->getRoomID();

            Room *temp_room = rooms[room_id - 1];

            std::vector<int> temp_room_posX = temp_room->GetPosX();
            std::vector<int> temp_room_posY = temp_room->GetPosY();
/*
            std::vector<int> temp_monst_posX = temp_monster->GetPosX();
            std::vector<int> temp_monst_posY = temp_monster->GetPosY();

            x = temp_room_posX[0] + temp_monst_posX[0];
            y = temp_room_posY[0] + temp_monst_posY[0];
*/
            int temp_monst_posX = temp_monster->GetCreaturePosX();
            int temp_monst_posY = temp_monster->GetCreaturePosY();

            //std::cout << temp_monster->getDeathAction()[1]->toString();
            //exit(3);


            x = temp_room_posX[0] + temp_monst_posX;
            y = temp_room_posY[0] + temp_monst_posY;

            char c = 'S';

            //grid->addObjectToDisplay(new GridChar(c), x, y); 
            grid->addObjectToDisplay(c, x, y);

            grid->addObj(temp_monster, x, y);

        }

        else if (temp_monster->getName() == "Hobgoblin"){
            int room_id = temp_monster->getRoomID();

            Room *temp_room = rooms[room_id - 1];

            std::vector<int> temp_room_posX = temp_room->GetPosX();
            std::vector<int> temp_room_posY = temp_room->GetPosY();
/*
            std::vector<int> temp_monst_posX = temp_monster->GetPosX();
            std::vector<int> temp_monst_posY = temp_monster->GetPosY();

            x = temp_room_posX[0] + temp_monst_posX[0];
            y = temp_room_posY[0] + temp_monst_posY[0];
*/

            int temp_monst_posX = temp_monster->GetCreaturePosX();
            int temp_monst_posY = temp_monster->GetCreaturePosY();



            x = temp_room_posX[0] + temp_monst_posX;
            y = temp_room_posY[0] + temp_monst_posY;

            char c = 'H';

            //grid->addObjectToDisplay(new GridChar(c), x, y); 
            grid->addObjectToDisplay(c, x, y);

            grid->addObj(temp_monster, x, y);

        }
    }

    //temp_player->setPosY(y);

   std::vector<Armor*> armors = handler->getArmors();

    for (int i = 0; i < armors.size(); i++){
        Armor *temp_armor = armors[i];
        int x;
        int y;
        int room_id = temp_armor->getRoomID();

        Room *temp_room = rooms[room_id - 1];

        std::vector<int> temp_room_posX = temp_room->GetPosX();
        std::vector<int> temp_room_posY = temp_room->GetPosY();

        //std::vector<int> temp_monst_posX = temp_monster->GetPosX();
        ;
        //std::vector<int> temp_monst_posY = temp_monster->GetPosY();
        int temp_armor_posX = temp_armor->GetItemPosX();
        int temp_armor_posY = temp_armor->GetItemPosY();

        x = temp_room_posX[0] + temp_armor_posX;
        y = temp_room_posY[0] + temp_armor_posY;

        char c = ']';


       // std::cout << "hii" << std::endl;
        //std::cout << " " << temp_armor->getItemAction()[0]->getIntValue() << std::endl;
        //grid->addObjectToDisplay(new GridChar(c), x, y); 
        grid->addObjectToDisplay(c, x, y);

        //new add obj to stack
        grid->addObj(temp_armor, x, y);


    }

    std::vector<Sword*> swords = handler->getSwords();

    for (int i = 0; i < swords.size(); i++){
        Sword *temp_sword = swords[i];
        int x;
        int y;
        int room_id = temp_sword->getRoomID();

        Room *temp_room = rooms[room_id - 1];

        std::vector<int> temp_room_posX = temp_room->GetPosX();
        std::vector<int> temp_room_posY = temp_room->GetPosY();

        //std::vector<int> temp_monst_posX = temp_monster->GetPosX();
        ;
        //std::vector<int> temp_monst_posY = temp_monster->GetPosY();
        int temp_sword_posX = temp_sword->GetItemPosX();
        int temp_sword_posY = temp_sword->GetItemPosY();

        x = temp_room_posX[0] + temp_sword_posX;
        y = temp_room_posY[0] + temp_sword_posY;

        char c = ')';

        //grid->addObjectToDisplay(new GridChar(c), x, y); 
        grid->addObjectToDisplay(c, x, y);

        //new add obj to stack
        grid->addObj(temp_sword, x, y);
        

    }

    std::vector<Scroll*> scrolls = handler->getScrolls();

    for (int i = 0; i < scrolls.size(); i++){
        Scroll *temp_scrolls = scrolls[i];
        int x;
        int y;
        int room_id = temp_scrolls->getRoomID();

        Room *temp_room = rooms[room_id - 1];

        std::vector<int> temp_room_posX = temp_room->GetPosX();
        std::vector<int> temp_room_posY = temp_room->GetPosY();

        //std::vector<int> temp_monst_posX = temp_monster->GetPosX();
        ;
        //std::vector<int> temp_monst_posY = temp_monster->GetPosY();
        int temp_scrolls_posX = temp_scrolls->GetItemPosX();
        int temp_scrolls_posY = temp_scrolls->GetItemPosY();

        x = temp_room_posX[0] + temp_scrolls_posX;
        y = temp_room_posY[0] + temp_scrolls_posY;

        char c = '?';

        //grid->addObjectToDisplay(new GridChar(c), x, y); 
        grid->addObjectToDisplay(c, x, y);

        //new add obj to stack
        grid->addObj(temp_scrolls, x, y);
        
    }

    //player
    Player* player = handler->getPlayer();



    Player *temp_player =player;
    int x;
    int y;

    int room_id = temp_player->getRoomID();
    
    //std::cout << "room id: " << room_id <<std::endl;
    Room *temp_room = rooms[room_id - 1];

    std::vector<int> temp_room_posX = temp_room->GetPosX();
    std::vector<int> temp_room_posY = temp_room->GetPosY();


    int temp_player_posX = temp_player->GetCreaturePosX();
    int temp_player_posY = temp_player->GetCreaturePosY();


    x = temp_room_posX[0] + temp_player_posX;
    y = temp_room_posY[0] + temp_player_posY;

    
    //std::cout << "i am right befor ethe @" << std::endl;
    char c = '@';

    //grid->addObjectToDisplay(new GridChar(c), x, y); 
    grid->addObjectToDisplay(c, x, y);
    grid->addObj(temp_player, x, y);
    
    temp_player->SetPosX(x);
    temp_player->setPosY(y);
    
    
    
    // update the grid
    grid->update();

    // wait a bit to rejoin
    // wait in a few steps to update faster on keypress
    /*
    for (int i = 0; (isRunning && i < 5); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    */
} 


int main(int argc, char* argv[]) {

    std::string fileName;
    try{
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
             << message << "\n";    
        xercesc::XMLString::release(&message);
        return 1;
    }
    switch (argc) {
        case 2:
            fileName = "./xmlfiles/" + ((std::string) argv[1]);
            break;
        default:
            std::cout << "C++ Test <xmlfilename>" << std::endl;
    }
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();

    try {
        DungeonXMLHandler* handler = new DungeonXMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);

      //  std::cout << "handler problem";

        XMLCh * fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
    

        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);
        std::cout << std::endl << std::endl << std::endl<< std::endl << std::endl;

        Dungeon *dungeonObject = handler->getDungeon();

        
        WIDTH = handler->getWidth();
        TOPHEIGHT = handler->getTopHeight();
        BOTTOMHEIGHT = handler->getBottomHeight();
        GAMEHEIGHT = handler->getGameHeight();


        std::vector<std::thread> threads;
        std::vector<std::thread> keyboard_threads;

        ObjectDisplayGrid grid(GAMEHEIGHT, WIDTH, TOPHEIGHT);
        ObjectDisplayGrid* pGrid = &grid;


        Player * player = handler->getPlayer();

        // thread to wait for key press
        KeyboardListener listener(pGrid, player);

        std::thread keyboardThread(&KeyboardListener::run, &listener);

        // thread to update display
        std::thread displayThread(runNewDisplay, dungeonObject, pGrid, handler);

        // wait for the keyboard thread to finish, then notify the display to stop
        keyboardThread.join();
        isRunning = false;

        // wait for the display thread to finish
        displayThread.join();

   
		delete parser;
		delete handler;
        
    } catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cout << "Exception message is: \n"
                 << message << "\n";
            xercesc::XMLString::release(&message);
            return -1;
    }
    catch (const xercesc::SAXParseException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
	catch(std::exception& e){
	    std::cout << e.what() << '\n';
	}
	catch(...){
        std::cout << "Unexpected Exception \n" ;
        return -1;
	}


    //call the values from the xml file


    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included
	return 0;
}


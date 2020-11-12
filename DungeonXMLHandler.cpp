#include <atomic> 
#include <thread>
#include <sstream>
#include "DungeonXMLHandler.hpp"
#include "ObjectDisplayGrid.hpp"
#include "GridChar.hpp"
#include "KeyboardListener.hpp"

//From https://www.tutorialspoint.com/case-insensitive-string-comparison-in-cplusplus
int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue){
    return booleanValue ? "true": "false";
}

std::vector<Room*> DungeonXMLHandler::getRooms() {
    return rooms;
}

std::vector<Passage*> DungeonXMLHandler::getPassages() {
    return passages;
}

std::vector<Monster*> DungeonXMLHandler::getMonsters() {
    return monsters;
}

std::vector<Scroll*> DungeonXMLHandler::getScrolls() {
    return scrolls;
}

std::vector<Armor*> DungeonXMLHandler::getArmors() {
    return armors;
}

std::vector<Sword*> DungeonXMLHandler::getSwords() {
    return swords;
}


DungeonXMLHandler::DungeonXMLHandler() {

}

std::string xmlChToString(const XMLCh* xmlChName, int length = -1){
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char * chStarName = xercesc::XMLString::transcode(xmlChName); 
    if(length == -1){
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else{
        std::string StrName(chStarName,0,length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char * strGet){
    XMLCh * xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh * xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}

void DungeonXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){
        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }

        //!!!!!!!! becuase of action
        Creature * creature = nullptr;
        Action * action = nullptr;
        if (case_insensitive_match(qNameStr,"Dungeon")) {
            //WHAT TO DO IN DUNGEON???
            std::string stwidth = xmlChToString(getXMLChAttributeFromString(attributes, "width"));
            std::string sttopHeight = xmlChToString(getXMLChAttributeFromString(attributes, "topHeight")); 
            std::string stbottomHeight = xmlChToString(getXMLChAttributeFromString(attributes, "bottomHeight")); 
            std::string stgameHeight = xmlChToString(getXMLChAttributeFromString(attributes, "gameHeight")); 
            
            std::string stName = xmlChToString(getXMLChAttributeFromString(attributes, "name"));

    
            
            width = std::stoi(stwidth);
            topHeight = std::stoi(sttopHeight);
            bottomHeight = std::stoi(stbottomHeight);
            gameHeight = std::stoi(stgameHeight);

            crDungeon = new Dungeon(stName, width, gameHeight);



            std::cout<< "Pass Dungeon" << std::endl;
            
        }else if (case_insensitive_match(qNameStr,"Rooms")) {
            std::cout<< "Pass Rooms" << std::endl;
        }else if (case_insensitive_match(qNameStr,"Room")) {
            std::cout<< "Pass Room" << std::endl;
            std::string roomNum = xmlChToString(getXMLChAttributeFromString(attributes,"room")); 
           
            Room * room = new Room(roomNum);   



            //crDungeon->addRoom(room);


            std::cout <<"after add room"<<std::endl;

            
            //rooms.push_back(room);
            displayableBeingParsed = nullptr;
            displayableBeingParsed = (Displayable *)room;
            displayableBeingParseds.push_back(displayableBeingParsed);
            
        }else if (case_insensitive_match(qNameStr,"Passages")){
            std::cout<< "Pass Passages" << std::endl;
        }else if (case_insensitive_match(qNameStr,"Passage")) {
            std::cout<< "Pass Passage" << std::endl;
            int roomNum1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room1"))); 
            int roomNum2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room2"))); 
            Passage * passage = new Passage(roomNum1, roomNum2);
            //passages.push_back(room);
            displayableBeingParsed = nullptr;
            displayableBeingParsed = (Displayable *)passage;
            displayableBeingParseds.push_back(displayableBeingParsed);

        }else if (case_insensitive_match(qNameStr,"Monster") | case_insensitive_match(qNameStr,"Player")) {
            if(case_insensitive_match(qNameStr,"Monster")){
                Monster * monster = new Monster();
                std::string monster_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int monster_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int monster_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 
                monster->setName(monster_name);
                monster->setID(monster_room, monster_serial);
                displayableBeingParsed = nullptr;
                displayableBeingParsed = (Displayable *)monster;
            }else if(case_insensitive_match(qNameStr,"Player")){
                Player * player = new Player();
                std::string player_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int player_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int player_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 
                player->setName(player_name);
                player->setID(player_room, player_serial);
                displayableBeingParsed = nullptr;
                displayableBeingParsed = (Displayable *)player;
            }else { 
                std::cout << "Unknown creature: " /*+ type*/ << std::endl; creature = NULL; 
            }
            displayableBeingParseds.push_back(displayableBeingParsed);

        }else if (case_insensitive_match(qNameStr,"Scroll") | case_insensitive_match(qNameStr,"Armor") | case_insensitive_match(qNameStr,"Sword")) {
            Item * item;
            if(case_insensitive_match(qNameStr,"Scroll")){
                std::string scroll_name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));  
                int scroll_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int scroll_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 

                Scroll * scroll = new Scroll(scroll_name);
                scroll->setID(scroll_room, scroll_serial);
                displayableBeingParsed = nullptr;
                displayableBeingParsed = (Displayable * )scroll;

            }else if(case_insensitive_match(qNameStr,"Armor")){
                std::string armor_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int armor_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int armor_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 

                Armor * armor = new Armor(armor_name);
                armor->setID(armor_room, armor_serial);
                displayableBeingParsed = nullptr;
                displayableBeingParsed = (Displayable * )armor;

            }else if(case_insensitive_match(qNameStr,"Sword")){
                std::string sword_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int sword_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int sword_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));

                Sword * sword = new Sword(sword_name);
                sword->setID(sword_room, sword_serial);
                displayableBeingParsed = nullptr;
                displayableBeingParsed = (Displayable * )sword;

            }else { 
                std::cout << "Unknown item: " /*+ type*/ << std::endl; item = NULL; 
            }
            displayableBeingParseds.push_back(displayableBeingParsed);
        }else if (case_insensitive_match(qNameStr,"CreatureAction") | case_insensitive_match(qNameStr,"ItemAction")) {
            //Action * action;
            if(case_insensitive_match(qNameStr,"CreatureAction")){
                std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                std::string type = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
                CreatureAction * creatureAction = nullptr;
                if(name == "Remove"){
                    creatureAction = new Remove("Remove", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); // !!!!!!!!!CREATURE??? WHERE TO GET THE CREATURE
                    creatureAction->setActionName("Remove");
                }else if(name == "YouWin"){
                    creatureAction = new YouWin("YouWin", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("YouWin");
                }else if(name == "UpdateDisplay"){
                    creatureAction = new UpdateDisplay("UpdateDisplay", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("UpdateDisplay");
                }else if(name == "Teleport"){
                    creatureAction = new Teleport("Teleport", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("Teleport");
                }else if(name == "ChangeDisplayedType"){
                    creatureAction = new ChangeDisplayedType("ChangeDisplayedType", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("ChangeDisplayedType");
                }else if(name == "EndGame"){
                    creatureAction = new EndGame("EndGame", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("EndGame");
                }else if(name == "DropPack"){
                    creatureAction = new DropPack("DropPack", static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size() - 1])); 
                    creatureAction->setActionName("DropPack");
                }
                
                Creature* topCreature = static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size()-1]);
                if (type == "hit"){
                    topCreature->setHitAction(creatureAction);
                }else{
                    topCreature->setDeathAction(creatureAction);
                }
                /*
                std::cout << "displayableBeingParseds[displayableBeingParseds.size()-1]";
                std::cout << static_cast<Creature*>(displayableBeingParseds[displayableBeingParseds.size()-1])->getDeathAction()->toString();
                std::cout << "displayableBeingParseds[displayableBeingParseds.size()-1] end";
                */
                

                actionBeingParsed = static_cast<Action*>(creatureAction);
                actionBeingParseds.push_back(actionBeingParsed);

            }else if(case_insensitive_match(qNameStr,"ItemAction")){
                std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                std::string type = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
                ItemAction * itemAction = nullptr;
                if(name == "BlessArmor"){
                    itemAction = new BlessCurseOwner(static_cast<Item*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
                    itemAction->setActionName("BlessArmor");
                }else if(name == "Hallucinate"){
                    itemAction = new Hallucinate(static_cast<Item*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
                    itemAction->setActionName("BlessArmor");
                }

                Item* topItem = static_cast<Item*>(displayableBeingParseds[displayableBeingParseds.size()-1]);
                if (type == "item"){
                    topItem->setItemAction(itemAction);
                }
                
                actionBeingParsed = static_cast<Action*>(itemAction);
                actionBeingParseds.push_back(actionBeingParsed);
            }else { 
                std::cout << "Unknown action: " << std::endl; action = NULL; 
            }
            
        }else if (case_insensitive_match(qNameStr,"visible")) {
            bVisible = true;
        }else if (case_insensitive_match(qNameStr,"maxhit")) {
            bMaxhit = true;
        }else if (case_insensitive_match(qNameStr,"hpMoves")) {
            bHpmoves = true;
        }else if (case_insensitive_match(qNameStr,"hp")) {
            bHp = true;
        }else if (case_insensitive_match(qNameStr,"type")) {
            bType = true;
        }else if (case_insensitive_match(qNameStr,"actionIntValue")) {
            bActionIntValue = true;
        }else if (case_insensitive_match(qNameStr,"actionCharValue")) {
            bActionCharValue = true;
        }else if (case_insensitive_match(qNameStr,"actionMessage")) {
            bActionMessage = true;
        }else if (case_insensitive_match(qNameStr,"posX")) {
            bPosx = true;
        }else if (case_insensitive_match(qNameStr,"ItemIntValue")) {
            bItemIntValue = true;
        }else if (case_insensitive_match(qNameStr,"posY")) {
            bPosy = true;
        }else if (case_insensitive_match(qNameStr,"width")) {
            bWidth = true;
        }else if (case_insensitive_match(qNameStr,"height")) {
            bHeight = true;
        }else {
            std::cout <<"Unknown qname: " /*<< qNameStr*/ << std::endl;
        }
        xercesc::XMLString::release(&qNameStr);
}

void DungeonXMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName)  {
        if (bVisible){
            if(std::stoi(data) == 1){
                displayableBeingParseds[displayableBeingParseds.size() - 1]->setVisible();
            }else{
                displayableBeingParseds[displayableBeingParseds.size() - 1]->setInvisible();
            }
            bVisible = false;
        }else if(bMaxhit){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setMaxHit(std::stoi(data));
            bMaxhit = false;
        }else if(bHpmoves){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setHpMove(std::stoi(data));
            bHpmoves = false;
        }else if(bHp){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setHp(std::stoi(data));
            bHp = false;
        }else if(bItemIntValue){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setIntValue(std::stoi(data));
            bItemIntValue = false;
        }else if(bType){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setType(data[0]);
            bType = false;
        }else if(bPosx){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->SetPosX(std::stoi(data));
            bPosx = false;
        }else if(bPosy){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setPosY(std::stoi(data));
            bPosy = false;
        }else if(bWidth){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->SetWidth(std::stoi(data));
            bWidth = false;
        }else if(bHeight){
            displayableBeingParseds[displayableBeingParseds.size() - 1]->setHeight(std::stoi(data));
            bHeight = false;
        }else if(bActionIntValue){
            actionBeingParseds[actionBeingParseds.size() - 1]->setIntValue(std::stoi(data));
            bActionIntValue = false;
        }else if(bActionMessage){
            actionBeingParseds[actionBeingParseds.size() - 1]->setMessage(data);
            bActionMessage = false;
        }else if(bActionCharValue){
            actionBeingParseds[actionBeingParseds.size() - 1]->setCharValue(data[0]);
            bActionCharValue = false;
        }
        
        char *  qNameStr = xercesc::XMLString::transcode(qName);
        if (case_insensitive_match(qNameStr,"Dungeon")) {        
            std::cout << "Dungeon out" << std::endl;
            //displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Rooms")) {
            std::cout << "Rooms out" << std::endl;
            if (roomCount != maxRooms) {
                std::cout <<"wrong number of rooms parsed, should be " << maxRooms << ", is " << roomCount << std::endl;
            }
        }else if (case_insensitive_match(qNameStr,"Passages")) {
            std::cout << "Passages out" << std::endl;
            if (passageCount != maxPassages) {
                std::cout <<"wrong number of passages parsed, should be " << maxPassages << ", is " << passageCount << std::endl;
            }  
        }else if (case_insensitive_match(qNameStr,"Room")) {  //structure
            rooms.push_back(static_cast<Room*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Room out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Passage")) {
            passages.push_back(static_cast<Passage*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Passage out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Player")) {  //creature
            players.push_back(static_cast<Player*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Player out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Monster")) {
            monsters.push_back(static_cast<Monster*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Monster out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Scroll")) {  //items
            scrolls.push_back(static_cast<Scroll*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Scroll out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Armor")) {
            armors.push_back(static_cast<Armor*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Armor out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"Sword")) {
            swords.push_back(static_cast<Sword*>(displayableBeingParseds[displayableBeingParseds.size() - 1]));
            std::cout << "Sword out" << std::endl;
            displayableBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"CreatureAction")) {
            creatureActions.push_back(static_cast<CreatureAction*>(actionBeingParseds[actionBeingParseds.size() - 1]));
            std::cout << "CreatureAction out" << std::endl;
            actionBeingParseds.pop_back();
        }else if (case_insensitive_match(qNameStr,"ItemAction")) {
            itemActions.push_back(static_cast<ItemAction*>(actionBeingParseds[actionBeingParseds.size() - 1]));
            std::cout << "ItemAction out" << std::endl;
            actionBeingParseds.pop_back();
        }
        xercesc::XMLString::release(&qNameStr);
}

void DungeonXMLHandler::addRoom(Room room) {
    //std::cout<< sizeof(room) << sizeof(rooms[roomCount]) << std::endl;
    //rooms[roomCount++] = room;
    //std::cout<< "2.5" << std::endl;
}

void DungeonXMLHandler::addPassage(Passage passage) {
    //passages[passageCount++] = passage;
}

void DungeonXMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;   
        if (DEBUG > 1) {
			std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

void DungeonXMLHandler::fatalError(const xercesc::SAXParseException& exception){
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "kartik Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}

std::string DungeonXMLHandler::toString() {
    std::string str = "DungeonXMLHandler\n";

    for (Room* room : rooms) {
        str += "room: \n";
        str += room->toString() + "\n";
    }
    for (Passage* passage : passages) {
        str += "passage: \n";
        str += passage->toString() + "\n";
    }
    for (Player* player : players) {
        str += "player: \n";
        str += player->toString() + "\n";

        if(!(player->getDeathAction()).empty()){
            for (CreatureAction* creatureActionsForCreatureDa_temp : player->getDeathAction()) {
                str += "   player death action: \n";
                str += creatureActionsForCreatureDa_temp->toString();
            }
        }
        if(!(player->getHitAction()).empty()){
            for (CreatureAction* creatureActionsForCreatureHa_temp : player->getHitAction()) {
                str += "   player hit action: \n";
                str += creatureActionsForCreatureHa_temp->toString();
            }
        }
    }
    for (Monster* monster : monsters) {
        str += "monster: \n";
        str += monster->toString() + "\n";
        if(!(monster->getDeathAction()).empty()){
            for (CreatureAction* creatureActionsForCreatureDa_temp : monster->getDeathAction()) {
                str += "   monster death action: \n";
                str += creatureActionsForCreatureDa_temp->toString();
            }
        }
        if(!(monster->getHitAction()).empty()){
            for (CreatureAction* creatureActionsForCreatureHa_temp : monster->getHitAction()) {
                str += "   monster hit action: \n";
                str += creatureActionsForCreatureHa_temp->toString();
            }
        }
    }
    for (Scroll* scroll : scrolls) {
        str += "scroll: \n";
        str += scroll->toString() + "\n";

        if(!(scroll->getItemAction()).empty()){
            for (ItemAction* itemActions_temp : scroll->getItemAction()) {
                str += "   scroll item action: \n";
                str += itemActions_temp->toString();
            }
        }
    }
    for (Armor* armor : armors) {
        str += "armor: \n";
        str += armor->toString() + "\n";

        if(!(armor->getItemAction()).empty()){
            for (ItemAction* itemActions_temp : armor->getItemAction()) {
                str += "   armor item action: \n";
                str += itemActions_temp->toString();
            }
        }                                               
    }

    for (Sword* sword : swords) {
        str += "sword: \n";
        str += sword->toString() + "\n";

        if(!(sword->getItemAction()).empty()){
            for (ItemAction* itemActions_temp : sword->getItemAction()) {
                str += "   sword item action: \n";
                str += itemActions_temp->toString();
            }
        }
    }
    return str;
}
/*
void DungeonXMLHandler::buildDisplay(){
   // std::string str = "DungeonXMLHandler\n";

   // set to false when done running
    std::atomic_bool isRunning(true);

    int WIDTH, HEIGHT, TOPHEIGHT;

    for (Room* room : rooms) {
        str += "room: \n";
        str += room->toString() + "\n";
    }

    for(ObjectDisplayGrid* grid) : grids){
        WIDTH = ObjectDisplayGrid->width;
        HEIGHT = ObjectDisplayGrid->gameHeight;
        TOPHEIGHT = ObjectDisplayGrid->topHeight;
    }
    

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

}
*/
    int DungeonXMLHandler::getTopHeight() {  
        
        return topHeight;
    }


    int DungeonXMLHandler::getBottomHeight() {  
        
        return bottomHeight;
    }

    int DungeonXMLHandler::getWidth() {
    
        return width;
    }

     int DungeonXMLHandler::getGameHeight() {
    
        return gameHeight;
    }

    Dungeon * DungeonXMLHandler::getDungeon(){
        return crDungeon;
    }

    std::vector<Player*> DungeonXMLHandler::getPlayers(){
        return players; 
    }

    /*
    for (CreatureAction* creatureAction : creatureActions) {
        str += "creatureAction: \n";
        str += creatureAction->toString() + "\n";
    }
    for (ItemAction* itemAction : itemActions) {
        str += "itemAction: \n";
        str += itemAction->toString() + "\n";
    }
    */
    /*
    str += "   bVisible: " + boolToString(bVisible)  + "\n";
    str += "   bMaxhit: " + boolToString(bMaxhit) + "\n";
    str += "   bHpmoves: " + boolToString(bHpmoves) + "\n";
    str += "   bHp: " + boolToString(bHp) + "\n";
    str += "   bType: " + boolToString(bType) + "\n";
    str += "   bActionIntValue: " + boolToString(bActionIntValue) + "\n";
    str += "   bactionCharValue: " + boolToString(bActionCharValue) + "\n";
    str += "   bActionMessage: " + boolToString(bActionMessage) + "\n";
    str += "   bPosx: " + boolToString(bPosx) + "\n";
    str += "   bPosy: " + boolToString(bPosy) + "\n";
    str += "   bWidth: " + boolToString(bWidth) + "\n";
    str += "   bHeight: " + boolToString(bHeight) + "\n";
    */
 

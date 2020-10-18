#include "DungeonXMLHandler.hpp"

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

std::vector<Room> DungeonXMLHandler::getRooms() {
    return rooms;
}

std::vector<Passage> DungeonXMLHandler::getPassages() {
    return passages;
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
        //Item * item = nullptr;
        if (case_insensitive_match(qNameStr,"Dungeon")) {
            //WHAT TO DO IN DUNGEON???
            std::cout<< "Pass Dungeon" << std::endl;
            
        }else if (case_insensitive_match(qNameStr,"Rooms")) {
            std::cout<< "Pass Rooms" << std::endl;
        }else if (case_insensitive_match(qNameStr,"Room")) {
            std::cout<< "Pass Room" << std::endl;
            maxRooms += 1;
            //rooms.resize(maxRooms);

            std::string roomNum = xmlChToString(getXMLChAttributeFromString(attributes,"room")); 
            Room room = Room(roomNum); 
            //addRoom(room);
            rooms.push_back(room);
            roomCount++;
            roomBeingParsed = &rooms[roomCount-1];

            displayableBeingParsed = (Structure *)roomBeingParsed;
            
        }else if (case_insensitive_match(qNameStr,"Passages")){
            std::cout<< "Pass Passages" << std::endl;
        }else if (case_insensitive_match(qNameStr,"Passage")) {
            std::cout<< "Pass Passage" << std::endl;
            maxPassages += 1;
            //passages.resize(maxPassages);

            int roomNum1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room1"))); 
            int roomNum2 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room2"))); 
            Passage passage = Passage(roomNum1, roomNum2); 
            //addPassage(passage);
            passages.push_back(passage);
            passageCount++;
            passageBeingParsed = &passages[passageCount-1];//!!!????

            displayableBeingParsed = (Structure *)passageBeingParsed;

        }else if (case_insensitive_match(qNameStr,"Monster") | case_insensitive_match(qNameStr,"Player")) {
            //Creature * creature;
            if(case_insensitive_match(qNameStr,"Monster")){
                Monster * monster = new Monster();

                std::string monster_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int monster_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int monster_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 
                monster->setName(monster_name);
                monster->setID(monster_room, monster_serial);
                creature = (Creature *) monster;

                dungeonBeingParsed->addCreature((Creature *) monster);
            }else if(case_insensitive_match(qNameStr,"Player")){
                Player * player = new Player();
                creature = (Creature *) player;

                dungeonBeingParsed->addCreature((Creature *) player);
            }else { 
                std::cout << "Unknown creature: " /*+ type*/ << std::endl; creature = NULL; 
            }
            displayableBeingParsed = (Displayable * )creature;
        }else if (case_insensitive_match(qNameStr,"Scroll") | case_insensitive_match(qNameStr,"Armor") | case_insensitive_match(qNameStr,"Sword")) {
            Item * item;
            if(case_insensitive_match(qNameStr,"Scroll")){

                std::string scroll_name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));  
                int scroll_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int scroll_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 

                Scroll * scroll = new Scroll(scroll_name);

                scroll->setID(scroll_room, scroll_serial);
                item = (Item *) scroll;

                dungeonBeingParsed->addItem((Item *) scroll);
            }else if(case_insensitive_match(qNameStr,"Armor")){
                std::string armor_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int armor_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int armor_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 

                Armor * armor = new Armor(armor_name);
                armor->setID(armor_room, armor_serial);
                item = (Item *) armor;

                dungeonBeingParsed->addItem((Item *) armor);
            }else if(case_insensitive_match(qNameStr,"Sword")){
                std::string sword_name = xmlChToString(getXMLChAttributeFromString(attributes,"name")); 
                int sword_room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
                int sword_serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));

                Sword * sword = new Sword(sword_name);
                sword->setID(sword_room, sword_serial);
                item = (Item *) sword;

                dungeonBeingParsed->addItem((Item *) sword);
            }else { 
                std::cout << "Unknown item: " /*+ type*/ << std::endl; item = NULL; 
            }
            displayableBeingParsed = (Displayable * )item;
        }else if (case_insensitive_match(qNameStr,"CreatureAction") | case_insensitive_match(qNameStr,"ItemAction")) {
            //Action * action;
            if(case_insensitive_match(qNameStr,"CreatureAction")){
                CreatureAction * creatureAction = new CreatureAction(creature); // !!!!!!!!!CREATURE??? WHERE TO GET THE CREATURE
                actionBeingParsed = (Action * )creatureAction;
            }else if(case_insensitive_match(qNameStr,"ItemAction")){
                ItemAction * itemAction = new ItemAction(creature);// !!!!!!!!!ITEM??? WHERE TO GET THE ITEM
                actionBeingParsed = (Action * )itemAction;
            }else { 
                std::cout << "Unknown action: " /*+ type*/ << std::endl; action = NULL; 
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
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            if(std::stoi(data) == 1){
                displayable->setVisible();
            }else{
                displayable->setInvisible();
            }
            bVisible = false;
        }else if(bMaxhit){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setMaxHit(std::stoi(data));
            bMaxhit = false;
        }else if(bHpmoves){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setHpMove(std::stoi(data));
            bHpmoves = false;
        }else if(bHp){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setHp(std::stoi(data));
            bHp = false;
        }else if(bItemIntValue){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setIntValue(std::stoi(data));
            bItemIntValue = false;
        }else if(bType){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setType(data[0]);
            bType = false;
        }else if(bPosx){
            Displayable * displayable = (Displayable *) displayableBeingParsed; 
            displayable->SetPosX(std::stoi(data));
            bPosx = false;
        }else if(bPosy){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setPosY(std::stoi(data));
            bPosy = false;
        }else if(bWidth){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->SetWidth(std::stoi(data));
            bWidth = false;
        }else if(bHeight){
            Displayable * displayable = (Displayable *) displayableBeingParsed;
            displayable->setHeight(std::stoi(data));
            bHeight = false;
        }else if(bActionIntValue){
            Action * action = (Action *) actionBeingParsed;
            action->setIntValue(std::stoi(data));
            bActionIntValue = false;
        }else if(bActionMessage){
            Action * action = (Action *) actionBeingParsed;
            action->setMessage(data);
            bActionMessage = false;
        }else if(bActionCharValue){
            Action * action = (Action *) actionBeingParsed;

            int n = data.length(); 
            char char_array[n + 1]; 
            strcpy(char_array, data.c_str()); 
            action->setCharValue('?');
            //std::cout << "TEST!!! bactionCharValue ENDDD" << std::endl;

            bActionCharValue = false;
        }
        
        char *  qNameStr = xercesc::XMLString::transcode(qName);
        //std::cout << qNameStr << "\n\n\n";
        if (case_insensitive_match(qNameStr,"Dungeon")) {
            std::cout << "Dungeon out" << std::endl;
            displayableBeingParsed = nullptr;
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
        }else if (case_insensitive_match(qNameStr,"Room")) {
            std::cout << "Room out" << std::endl;
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Passage")) {
            std::cout << "Passage out" << std::endl;
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Monster")) {
            std::cout << "Monster out" << std::endl;
            //displayableBeingParsed->toString();
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Player")) {
            std::cout << "Player out" << std::endl;
            //displayableBeingParsed->toString();
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Scroll")) {
            std::cout << "Scroll out" << std::endl;
            //displayableBeingParsed->toString();
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Armor")) {
            std::cout << "Armor out" << std::endl;
            displayableBeingParsed->toString();
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"Sword")) {
            std::cout << "Sword out" << std::endl;
            //displayableBeingParsed->toString();
            displayableBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"CreatureAction")) {
            std::cout << "CreatureAction out" << std::endl;
            //actionBeingParsed->toString();
            actionBeingParsed = nullptr;
        }else if (case_insensitive_match(qNameStr,"ItemAction")) {
            std::cout << "ItemAction out" << std::endl;
            //actionBeingParsed->toString();
            actionBeingParsed = nullptr;
        }
        xercesc::XMLString::release(&qNameStr);
}

void DungeonXMLHandler::addRoom(Room room) {
    //std::cout<< sizeof(room) << sizeof(rooms[roomCount]) << std::endl;
    rooms[roomCount++] = room;
    //std::cout<< "2.5" << std::endl;
}

void DungeonXMLHandler::addPassage(Passage passage) {
    passages[passageCount++] = passage;
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
    std::cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}

std::string DungeonXMLHandler::toString() {
    std::string str = "DungeonXMLHandler\n";
    str += "   maxRoom: " + std::to_string(maxRooms) + "\n";
    str += "   roomCount: " + std::to_string(roomCount) + "\n";
    str += "   maxPassage: " + std::to_string(maxPassages) + "\n";
    str += "   passageCount: " + std::to_string(passageCount) + "\n";

    for (Room room : rooms) {
        str += room.toString() + "\n";
    }
    for (Passage passage : passages) {
        str += passage.toString() + "\n";
    }
    str += "   dungeonBeingParsed: " + dungeonBeingParsed->toString() + "\n";
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
    return str;
}

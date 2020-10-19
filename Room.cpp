#include <iostream>
#include <string>
#include "Structure.hpp"
#include "Room.hpp"
#include "Monster.hpp"
#include "Creature.hpp"

Room::Room(std::string _roomName): Structure(){
    roomName = _roomName;
    std::cout<< "Room::Room(std::string roomName) :  " << roomName << std::endl;
}

void Room::setId(int _room){
    room = _room;
    std::cout<< "Room::setI : " << room << std::endl;

}

void Room::setCreature(Creature _monster){
    monster = _monster;
    std::cout<< "Room::setCreature : " << monster << std::endl;
}

std::string Room::toString(){
    std::string str;
    /*+ "Creature : " + monster.toString()*!!!!*/;
    str = "Room Name: " + roomName + " room: " + std::to_string(room) + "\n";

    //Print all Info, same as all print in .cpp classes
    str += "   Maxhit: " + std::to_string(maxHit) + "\n";
    str += "   Hpmoves: " + std::to_string(hpMoves) + "\n";
    str += "   Hp: " + std::to_string(Hp) + "\n";
    //str += "   Type: " + t + "\n";
    //str += "   ActionIntValue: " + boolToString(bActionIntValue) + "\n";
    //str += "   actionCharValue: " + boolToString(bActionCharValue) + "\n";
    //str += "   ActionMessage: " + boolToString(bActionMessage) + "\n";
    str += "   Posx: \n";
    for (int posx : posX) {
        str += "   ";
        str += std::to_string(posx) + "\n";
    }
    str += "   Posy: \n";
    for (int posy : posY) {
        str += "   ";
        str += std::to_string(posy) + "\n";
    }
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
    //End of print all Info, same as all print in .cpp classes

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

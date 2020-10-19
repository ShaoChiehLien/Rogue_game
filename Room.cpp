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
    str += "   Posx: " + std::to_string(x) + "\n";
    str += "   Posy: " + std::to_string(y) + "\n";
    str += "   Width: " + std::to_string(x) + "\n";
    str += "   Height: " + std::to_string(y) + "\n";
    //End of print all Info, same as all print in .cpp classes

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

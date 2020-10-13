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
    str = "Room Name : " + roomName + "room : " + std::to_string(room) /*+ "Creature : " + monster.toString()*/;
    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

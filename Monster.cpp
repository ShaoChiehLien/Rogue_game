#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Monster.hpp"

void Monster::setName(std::string _monsterName){
    monsterName = _monsterName;
    std::cout << "Monster::setName :   " << monsterName << std::endl;
}

void Monster::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Monster::setID  room: " << room << "serial:  "<< serial << std::endl;
}

std::string Monster::toString(){
    std::string str;
    str = "room : " + std::to_string(room) + "serial : " + std::to_string(serial) + "monsterName : " + monsterName;
    return str;
}



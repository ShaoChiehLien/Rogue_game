#include <iostream>
#include <string>
#include "Item.hpp"
#include "Armor.hpp"

Armor::Armor(std::string _armorName){
    armorName = _armorName;
    std::cout << "Armor::Armor name: " << armorName << std::endl;

}

void Armor::setName(std::string _armorSetName){
    armorSetName = _armorSetName;
    std::cout << "Armor::setName : " << armorSetName << std::endl;
}

void Armor::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Armor::setID  room: " << room <<"Serial: " << serial << std::endl;
}


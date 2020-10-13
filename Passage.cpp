#include <iostream>
#include <string>
#include "Structure.hpp"
#include "Passage.hpp"

Passage::Passage(int _room1, int _room2){
    room1 = _room1;
    room2 = _room2;
}


void Passage::setName(std::string _passageName){
    passageName = _passageName;
}

void Passage::setID(int _room1, int _room2){
    room1 = _room1;
    room2 = _room2;
}

std::string Passage::toString(){
    std::string str;
    str = "passageName: " + passageName + "room1: " + std::to_string(room1) + "room2: " + std::to_string(room2) + "\n";
    return str;
}


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
    str = "passageName: " + passageName + " room1: " + std::to_string(room1) + " room2: " + std::to_string(room2) + "\n";
    
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

    return str;
}


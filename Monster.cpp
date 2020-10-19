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
    str = "room: " + std::to_string(room) + " serial : " + std::to_string(serial) + " monsterName : " + monsterName + "\n";
    
    //Print all Info, same as all print in .cpp classes    
    str += "   Visible: " + std::to_string(visible) + "\n";
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
    std::string type_string{t};
    str += "   Type: " + type_string + "\n";
    str += "   Hp: " + std::to_string(Hp) + "\n";
    str += "   Hpmoves: " + std::to_string(hpMoves) + "\n";
    str += "   Maxhit: " + std::to_string(maxHit) + "\n";
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
    //End of print all Info, same as all print in .cpp classes
    
    return str;
}



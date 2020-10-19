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
    
    return str;
}



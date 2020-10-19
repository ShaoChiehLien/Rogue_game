#include <iostream>
#include <string>
#include "Item.hpp"
#include "Armor.hpp"

Armor::Armor(std::string _armorName){
    armorName = _armorName;
    std::cout << "Armor::Armor name: " << armorName << std::endl;

}

void Armor::setName(std::string _armorSetName){
    armorName = _armorSetName;
    std::cout << "Armor::setName : " << armorName << std::endl;
}

void Armor::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Armor::setID  room: " << room <<"Serial: " << serial << std::endl;
}

std::string Armor::toString(){
    std::string str;
    str = "Name: " + armorName + " room: " + std::to_string(room) + " Serial: " + std::to_string(serial) + "\n";
    
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
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
    //End of print all Info, same as all print in .cpp classes

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

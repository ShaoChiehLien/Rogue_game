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

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

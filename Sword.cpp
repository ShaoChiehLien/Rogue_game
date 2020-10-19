#include <iostream>
#include "Item.hpp"
#include "Sword.hpp"


Sword::Sword(std::string _name){
    name = _name;
    std::cout << "Sword::Sword(std::string name) : " << name << std::endl;
}


void Sword::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Room: " << room << "Serial: " << serial << std::endl;
}

std::string Sword::getName( ) const {return name; }

int Sword::getRoom( ) const {return room; }

int Sword::getSerial( ) const {return serial; }

std::ostream& operator<<(std::ostream& os, const Sword& arg) {
    
    std::string name = arg.getName( );
    int room = arg.getRoom( );
    int serial = arg.getSerial( );
    
   os << "name: " << name << "room: " << room << "serial" << serial<< std::endl;
   return os;
}


std::string Sword::toString(){
    std::string str;
    str = "Name: " + name + " room: " + std::to_string(room) + " Serial: " + std::to_string(serial) + "\n";
    
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

#include <iostream>
#include "Item.hpp"
#include "Sword.hpp"


Sword::Sword(std::string _name){
    name = _name;
}


void Sword::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
}

int Sword::getRoomID(){
    return room;
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
    str += "   ItemIntValue: " + std::to_string(v) + "\n";
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

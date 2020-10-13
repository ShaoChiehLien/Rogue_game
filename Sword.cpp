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

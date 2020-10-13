#include <iostream>
#include <string>
#include "Item.hpp"
#include "Scroll.hpp"

Scroll::Scroll(std::string _name){
    name = _name;
    std::cout << "Scroll::Scroll(std::string name) : " << name << std::endl;
}

void Scroll::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Room: " << room << "Serial: " << serial << std::endl;
}



#ifndef ARMOR_HPP
#define ARMOR_HPP
#include <iostream>
#include <string>
#include "Item.hpp"


class Armor : public Item{
    public:
        Armor(std::string _armorName );
        void setName(std::string _armorSetName);
        void setID(int _room, int _serial);
        std::string toString();
    
    private:
       std::string armorName;
       int room;
       int serial;

};




#endif /* SCROLL_HPP */
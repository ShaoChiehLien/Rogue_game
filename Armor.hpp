#ifndef ARMOR_HPP
#define ARMOR_HPP
#include <iostream>
#include <string>
#include "Item.hpp"


class Armor : public Item{
    public:
        Armor(std::string _armorName );
        virtual void setName(std::string _armorSetName);
        virtual void setID(int _room, int _serial);
        virtual std::string toString();
        virtual int getRoomID();
        virtual std::string getName();

    
    private:
       std::string armorName;
       int room;
       int serial;

};




#endif /* SCROLL_HPP */
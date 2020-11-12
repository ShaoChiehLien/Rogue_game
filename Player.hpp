#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"


class Player : public Creature{
    public:
        virtual void setName (std::string _playerName);
        virtual void setID(int _room, int _serial);
        virtual void setWeapon(Item _sword);
        virtual void setArmor(Item _armor);
        virtual int getRoomID();
        std::string toString();

    private:
        Item sword;
        Item armor;
        std::string playerName;
        int room;
        int serial;

        

};




#endif /* PLAYER_HPP */
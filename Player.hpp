#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"


class Player : public Creature{
    public:
        void setName (std::string _playerName);
        void setID(int _room, int _serial);
        void setWeapon(Item _sword);
        void setArmor(Item _armor);

        std::string toString();
    private:
        Item sword;
        Item armor;
        std::string playerName;
        int room;
        int serial;

};




#endif /* PLAYER_HPP */
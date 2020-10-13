#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"


class Player : public Creature{
    public:
        void setWeapon(Item _sword);
        void setArmor(Item _armor);
    private:
        Item sword;
        Item armor;
    

};




#endif /* PLAYER_HPP */
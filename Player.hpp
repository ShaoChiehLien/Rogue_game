#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"


class Player : public Creature{
    public:
        Player();
        virtual void setName (std::string _playerName);
        virtual void setID(int _room, int _serial);
        virtual void setWeapon(Item _sword);
        virtual void setArmor(Item _armor);
        virtual void addItemintoPack(int _placeToAdd, Item* _item);
        Item* dropItemfromPack(int _placeToThrow);
        std::vector<Item*> getIteminPack();
        virtual int getRoomID();
        std::string toString();

    private:
        std::vector<Item*> pack;
        Item sword;
        Item armor;
        std::string playerName;
        int room;
        int serial;

        

};




#endif /* PLAYER_HPP */
#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <iostream>
#include <string>
#include "Creature.hpp"


class Monster : public Creature{
    public:
        void setName (std::string _monsterName);
        void setID(int _room, int _serial);
        std::string toString();
    private:
        int room;
        int serial;
        std::string monsterName;
};




#endif /* MONSTER_HPP */

#ifndef ITEMACTION_HPP
#define ITEMACTION_HPP
#include <iostream>
#include <string>
#include "Action.hpp"
#include "Creature.hpp"


class ItemAction : public Action{
    public:
       ItemAction(Creature *_owner);
       std::string toString();
    private:
        Creature *owner;

};




#endif /* ITEMACTION_HPP */
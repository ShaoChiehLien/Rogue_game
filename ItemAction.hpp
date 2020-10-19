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
       void setActionName(std::string _actionName);
       std::string getActionName();
    private:
        Creature *owner;
        std::string actionName;

};




#endif /* ITEMACTION_HPP */
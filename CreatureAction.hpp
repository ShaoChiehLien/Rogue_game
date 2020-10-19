#ifndef CREATUREACTION_HPP
#define CREATUREACTION_HPP

#include <iostream>
#include "Action.hpp"
//#include "Creature.hpp"

class Creature;
class CreatureAction : public Action{
    public:
        CreatureAction(Creature *_owner);
        std::string toString();
        void setActionName(std::string _actionName);
        std::string getActionName();
    private:
        Creature* owner;
        std::string actionName;
        // Creature owner;
};

#endif /* CREATUREACTION_HPP */

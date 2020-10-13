#ifndef CREATUREACTION_HPP
#define CREATUREACTION_HPP

#include <iostream>
#include "Action.hpp"
//#include "Creature.hpp"

class Creature;
class CreatureAction : public Action{
    public:
        CreatureAction(Creature *_owner);
    private:
        Creature* owner;
        // Creature owner;
};

#endif /* CREATUREACTION_HPP */

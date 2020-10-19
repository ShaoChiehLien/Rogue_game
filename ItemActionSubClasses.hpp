#ifndef ITEMACTIONSUBCLASSES_HPP
#define ITEMACTIONSUBCLASSES_HPP
#include <iostream>
#include "ItemAction.hpp"
#include "Creature.hpp"

class BlessCurseOwner : public ItemAction{
    public:
        BlessCurseOwner(Creature* _owner);
    private:
        Creature* owner;

};

class Hallucinate : public ItemAction{
    public:
        Hallucinate(Creature* _owner);
    private:
        Creature* owner;

};




#endif /* ITEMACTIONSUBCLASSES_HPP */
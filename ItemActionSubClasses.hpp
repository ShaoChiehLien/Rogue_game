#ifndef ITEMACTIONSUBCLASSES_HPP
#define ITEMACTIONSUBCLASSES_HPP
#include <iostream>
#include "ItemAction.hpp"
#include "Creature.hpp"

class BlessCurseOwner : public ItemAction{
    public:
        BlessCurseOwner(Item* _owner);
    private:
        Item* owner;

};

class Hallucinate : public ItemAction{
    public:
        Hallucinate(Item* _owner);
    private:
        Item* owner;

};




#endif /* ITEMACTIONSUBCLASSES_HPP */
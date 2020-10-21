#include <iostream>
#include <string>
#include "ItemActionSubClasses.hpp"
#include "ItemAction.hpp"
#include "Action.hpp"
#include "Creature.hpp"



BlessCurseOwner::BlessCurseOwner(Item* _owner) : ItemAction(_owner){
    owner = _owner;
    std::cout << "BlessCurseOwner::BlessCurseOwner(Creature owner) :  " << owner << std::endl;
}

Hallucinate::Hallucinate(Item* _owner) : ItemAction(_owner){
    owner = _owner;
    std::cout << "Hallucinate::Hallucinate(Creature owner) :  " << owner << std::endl;
}





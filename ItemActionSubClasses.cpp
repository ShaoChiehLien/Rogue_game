#include <iostream>
#include <string>
#include "ItemActionSubClasses.hpp"
#include "ItemAction.hpp"
#include "Action.hpp"
#include "Creature.hpp"



BlessCurseOwner::BlessCurseOwner(Creature* _owner) : ItemAction(_owner){
    owner = _owner;
    std::cout << "BlessCurseOwner::BlessCurseOwner(Creature owner) :  " << owner << std::endl;
}

Hallucinate::Hallucinate(Creature* _owner) : ItemAction(_owner){
    owner = _owner;
    std::cout << "Hallucinate::Hallucinate(Creature owner) :  " << owner << std::endl;
}





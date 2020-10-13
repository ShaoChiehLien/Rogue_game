#include <iostream>
#include <string>
#include "Action.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"

//CreatureAction::CreatureAction(Creature _owner){
CreatureAction::CreatureAction(Creature* _owner){
    owner = _owner;
    std::cout << "owner: " << owner << std::endl;
}

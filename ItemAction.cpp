#include <iostream>
#include <string>
#include "Action.hpp"
#include "Creature.hpp"
#include "ItemAction.hpp"

ItemAction::ItemAction(Creature *_owner){
    owner = _owner;
    std::cout << " ItemAction::ItemAction(creature owner): " << owner << std::endl;
}


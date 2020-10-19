#include <iostream>
#include <string>
#include "Action.hpp"
#include "Creature.hpp"
#include "ItemAction.hpp"
#include "Monster.hpp"
#include "Player.hpp"

ItemAction::ItemAction(Creature *_owner){
    owner = _owner;
    std::cout << " ItemAction::ItemAction(creature owner): " << owner << std::endl;
}

std::string ItemAction::toString(){
    std::string str;
    str = "Message: " + msg + " Int Value: " + std::to_string(v) + " Char Value: " + c + "\n";
    
    str += "   Item owner: ";
    //str += (owner->toString());

    if(dynamic_cast<Player*>(owner) == nullptr){
        //std::cout << dynamic_cast<Monster*>(owner)->toString() << "!!!!" << std::endl;
    }else{
        //std::cout << dynamic_cast<Player*>(owner)->toString() << "!!!!" << std::endl;
    }
    str += "\n";

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}
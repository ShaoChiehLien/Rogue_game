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
    str = "   Action Name: " + actionName + "\n";
    str = "   Message: " + msg + "\n   Int Value: " + std::to_string(v) + "\n   Char Value: " + c + "\n";
    str += "   Creature owner: \n";
    //str += (owner->toString());
    if(dynamic_cast<Player*>(owner) == nullptr && (dynamic_cast<Monster*>(owner) == nullptr)){
        str += "????\n";
    }
    else if(dynamic_cast<Player*>(owner) == nullptr){
        str += dynamic_cast<Monster*>(owner)->toString();
    }else{
        str += dynamic_cast<Player*>(owner)->toString();
    }
    str += "\n";

    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}

void ItemAction::setActionName(std::string _actionName){
    actionName = _actionName;
}

std::string ItemAction:: getActionName(){
    return actionName;
}
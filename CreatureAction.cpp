#include <iostream>
#include <string>
#include "Action.hpp"
#include "Creature.hpp"
#include "CreatureAction.hpp"
#include "Monster.hpp"
#include "Player.hpp"

//CreatureAction::CreatureAction(Creature _owner){
CreatureAction::CreatureAction(Creature* _owner){
    owner = _owner;
    std::cout << "owner: " << owner << std::endl;
}

void CreatureAction::setActionName(std::string _actionName){
    actionName = _actionName;
}

std::string CreatureAction:: getActionName(){
    return actionName;
}

std::string CreatureAction::toString(){
    std::string str;
    str = "      Action Name: " + actionName + "\n";
    str += "      Message: " + msg + "\n      Int Value: " + std::to_string(v) + "\n      Char Value: " + c + "\n\n";
    /* If need access creature from here, could reference the code below
    str += "   Creature owner: \n   ";
    if(dynamic_cast<Player*>(owner) == nullptr && (dynamic_cast<Monster*>(owner) == nullptr)){
        str += "????\n";
    }
    else if(dynamic_cast<Player*>(owner) == nullptr){
        str += dynamic_cast<Monster*>(owner)->toString();
    }else{
        str += dynamic_cast<Player*>(owner)->toString();
    }
    str += "\n";
    */
    return str;
}
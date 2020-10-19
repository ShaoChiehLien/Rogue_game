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

std::string CreatureAction::toString(){
    std::string str;
    str = "Message: " + msg + " Int Value: " + std::to_string(v) + " Char Value: " + c + "\n";
    
    str += "   Creature owner: ";
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
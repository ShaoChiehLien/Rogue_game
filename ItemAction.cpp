#include <iostream>
#include <string>
#include "Action.hpp"
#include "Item.hpp"
#include "ItemAction.hpp"
#include "Armor.hpp"
#include "Scroll.hpp"
#include "Sword.hpp"

ItemAction::ItemAction(Item *_owner){
    owner = _owner;
}

std::string ItemAction::toString(){
    std::string str;
    str = "   Action Name: " + actionName + "\n";
    str = "   Message: " + msg + "\n   Int Value: " + std::to_string(v) + "\n   Char Value: " + c + "\n\n";
    /* If need access creature from here, could reference the code below
    str += "   Item owner: \n";
    //str += (owner->toString());
    if(dynamic_cast<Sword*>(owner) == nullptr && (dynamic_cast<Scroll*>(owner) == nullptr) && (dynamic_cast<Armor*>(owner) == nullptr)){
        str += "????\n";
    }else if(dynamic_cast<Sword*>(owner) == nullptr && (dynamic_cast<Scroll*>(owner) == nullptr)){
        str += dynamic_cast<Armor*>(owner)->toString();
    }else if((dynamic_cast<Scroll*>(owner) == nullptr) && (dynamic_cast<Armor*>(owner) == nullptr)){
        str += dynamic_cast<Sword*>(owner)->toString();
    }else{
        str += dynamic_cast<Scroll*>(owner)->toString();
    }
    str += "\n";
    */

    return str;
}

void ItemAction::setActionName(std::string _actionName){
    actionName = _actionName;
}

std::string ItemAction::getActionName(){
    return actionName;
}
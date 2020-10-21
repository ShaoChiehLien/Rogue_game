#include <iostream>
#include <string>
#include "Displayable.hpp"
#include "Item.hpp"
#include "ItemAction.hpp"

void Item::setOwner(Creature* _owner){
    owner = _owner;
}

Creature* Item::getOwner( ) const {return owner; }

std::vector<ItemAction*> Item::getItemAction(){
    return itemActionsForItem;
}

std::ostream& operator<<(std::ostream& os, const Item& arg) {
    Creature* owner = arg.getOwner( );
   os << "owner: " << owner << std::endl;
   return os;
}

void Item::setItemAction(ItemAction *_item){
    itemActionsForItem.push_back(_item);
    std::cout << "setItemAction item: " << _item <<std::endl;
}
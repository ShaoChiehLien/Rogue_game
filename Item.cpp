#include <iostream>
#include <string>
#include "Displayable.hpp"
#include "Creature.hpp"
#include "Item.hpp"

void Item::setOwner(Creature _owner){
    owner = _owner;
}

Creature Item::getOwner( ) const {return owner; }

std::ostream& operator<<(std::ostream& os, const Item& arg) {
    Creature owner = arg.getOwner( );
   os << "owner: " << owner << std::endl;
   return os;
}

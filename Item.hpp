#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
#include "Displayable.hpp"
#include "Creature.hpp"

class Item : public Displayable{
    public:
        void setOwner(Creature _owner);
        virtual Creature getOwner( ) const;
        //std::string toString();
    private:
        Creature owner;
    
};

std::ostream& operator<<(std::ostream&, const Item&);


#endif /* ITEM_HPP */

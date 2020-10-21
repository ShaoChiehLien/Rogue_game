#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
#include "Displayable.hpp"
#include "Creature.hpp"
#include <vector>


class ItemAction;
class Item : public Displayable{
    public:
        void setOwner(Creature* _owner);
        virtual Creature* getOwner( ) const;
        void setItemAction(ItemAction *_item);
        std::vector<ItemAction*> getItemAction();
    protected:
        std::vector<ItemAction*> itemActionsForItem;
        Creature* owner = nullptr;

};

#endif /* ITEM_HPP */

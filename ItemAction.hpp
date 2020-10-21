#ifndef ITEMACTION_HPP
#define ITEMACTION_HPP
#include <iostream>
#include <string>
#include "Action.hpp"


class Item;
class ItemAction : public Action{
    public:
       ItemAction(Item *_owner);
       std::string toString();
       void setActionName(std::string _actionName);
       std::string getActionName();
    private:
        Item *owner;
        std::string actionName;

};




#endif /* ITEMACTION_HPP */
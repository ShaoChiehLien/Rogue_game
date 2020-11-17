#ifndef SCROLL_HPP
#define SCROLL_HPP
#include <iostream>
#include <string>
#include "Item.hpp"


class Scroll : public Item{
    public:
        Scroll(std::string _name);
        virtual void setID(int _room, int _serial);
        virtual std::string toString();
        virtual int getRoomID();
        virtual std::string getName();
        
    
    private:
        std::string name;
        int room;
        int serial;

};




#endif /* SCROLL_HPP */
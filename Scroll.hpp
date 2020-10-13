#ifndef SCROLL_HPP
#define SCROLL_HPP
#include <iostream>
#include <string>
#include "Item.hpp"


class Scroll : public Item{
    public:
        Scroll(std::string _name);
        void setID(int _room, int _serial);
    
    private:
        std::string name;
        int room;
        int serial;

};




#endif /* SCROLL_HPP */
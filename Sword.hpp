#ifndef SWORD_HPP
#define SWORD_HPP
#include <iostream>
#include "Item.hpp"

class Sword: public Item{
    public:
        Sword(std::string _name);

        void setID(int _room, int _serial);
        virtual std::string getName( ) const;
        virtual int getRoom( ) const;
        virtual int getSerial( ) const;
    private:
        std::string name;
        int room;
        int serial;
};

std::ostream& operator<<(std::ostream&, const Sword&);

#endif /* SWORD_HPP */

#ifndef ROOM_HPP
#define ROOM_HPP
#include <iostream>
#include <string>

#include "Structure.hpp"
#include "Creature.hpp"

class Room : public Structure{
    public:
        Room(std::string _roomName);
        void setId(int _room);
        void setCreature(Creature _monster);

        std::string toString();
    
    private:
        std::string roomName;
        int room;
        Creature monster;
        
};

#endif /* ROOM_HPP */

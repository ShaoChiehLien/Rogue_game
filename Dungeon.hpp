#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include <iostream>
#include <string>
#include "Room.hpp"
#include "Passage.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include <vector>


class Dungeon{
    public:
        Dungeon(std::string _name, int _width ,int _gameHeight);  //constructor
        void getDungeon(std::string _name, int _width, int _gameHeight);  //getter
        void addRoom(Room * _room);
        void addCreature(Creature *  _creature);
        void addPassage(Passage * name);
        void addItem(Item * _item);
        std::string toString();
           
        std::string getName();
     
        int getWidth();
        int getHeight();

        std::vector<Room*> getRooms();
       
    
    private:
    
        std::vector<Room *> rooms;
        std::vector<Passage *> passages;

        int maxPassages;
        int passageCount;
        int maxRooms;
        int roomCount;
       // Room room;
    
        std::string name;
        int width;
        int gameHeight;
};


#endif /* DUNGEON_HPP */

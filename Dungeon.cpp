#include <iostream>
#include <string>
#include "Dungeon.hpp"
#include "Room.hpp"
#include "Creature.hpp"
#include "Passage.hpp"
#include "Item.hpp"



Dungeon::Dungeon(std::string _name, int _width ,int _gameHeight) {
    name = _name;
    width = _width;
    gameHeight = _gameHeight;
    
    maxPassages = 0;
    passageCount = 0;
    maxRooms = 0;
    roomCount = 0;
    
    std::cout << "Dungeon::Dungeon(std::string _name, int _width ,int _gameHeight)" << std::endl;
}

void Dungeon::getDungeon(std::string _name, int _width, int _gameHeight){
    name = _name;
    width = _width;
    gameHeight = _gameHeight;

    std::cout << "Dungeon::getDungeon" << std::endl;
    std::cout << "Name: " << name << "Width: " << width << "gameHeight:" << "gameHeight" << std::endl;
    
}

void Dungeon::addRoom (Room * _room) {
    rooms[roomCount++] = _room;
    std::cout << "Dungeon::addRoom" << std::endl;
}

void Dungeon::addCreature (Creature * _creature) {
    //NEED TO ADD CREATURE!!
    std::cout << "Dungeon::addCreature" << std::endl;
}

void Dungeon::addPassage (Passage * _passage) {
    passages[passageCount++] = _passage;
    std::cout << "Dungeon::addPassage" << std::endl;
}

void Dungeon::addItem (Item * _item) {
    //NEED TO ADD CREATURE!!
    std::cout << "Dungeon::addItem" << std::endl;
}

std::string Dungeon::toString(){
    std::string str = "maxPassages:" + std::to_string(maxPassages) + 
    "passageCount:" + std::to_string(passageCount) + 
    "maxRooms:" + std::to_string(maxRooms) + 
    "roomCount:" + std::to_string(roomCount) +
    "name:" + name +
    "width:" + std::to_string(width) +
    "gameHeight:" + std::to_string(gameHeight);
    return str;
}


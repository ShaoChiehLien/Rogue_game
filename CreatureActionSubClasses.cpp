#include <iostream>
#include <string>
#include "CreatureActionSubClasses.hpp"
#include "CreatureAction.hpp"

Remove::Remove(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;
}

YouWin::YouWin(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

UpdateDisplay::UpdateDisplay(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

Teleport::Teleport(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

ChangedDisplayedType::ChangedDisplayedType(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

DropPack::DropPack(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

EndGame::EndGame(std::string _name, Creature _owner):CreatureAction(&_owner){
    name = _name;
    owner = _owner;
    std::cout << "name: " << name << "owner: " << owner << std::endl;

}

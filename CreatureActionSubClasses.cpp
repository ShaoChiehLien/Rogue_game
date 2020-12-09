#include <iostream>
#include <string>
#include "CreatureActionSubClasses.hpp"
#include "CreatureAction.hpp"

Remove::Remove(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;
}

YouWin::YouWin(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

UpdateDisplay::UpdateDisplay(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

Teleport::Teleport(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

ChangeDisplayedType::ChangeDisplayedType(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

DropPack::DropPack(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

EndGame::EndGame(std::string _name, Creature* _owner):CreatureAction(_owner){
    name = _name;
    owner = _owner;

}

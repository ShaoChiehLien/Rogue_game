#ifndef CREATUREACTIONSUBCLASSES_HPP
#define CREATUREACTIONSUBCLASSES_HPP
#include <iostream>
#include "CreatureAction.hpp"
#include "Creature.hpp"

class Remove : public CreatureAction{
    public:
        Remove(std::string _name, Creature* _owner);

    private:
        std::string name;
        Creature* owner;

};

class YouWin : public CreatureAction{
    public:
        YouWin(std::string _name, Creature* _owner);

    private:
        std::string name;
        Creature* owner;


};

class UpdateDisplay : public CreatureAction{
    public:
        UpdateDisplay(std::string _name, Creature* _owner);

    private:
        std::string name;
        Creature* owner;

};

class Teleport : public CreatureAction{
    public:
        Teleport(std::string _name, Creature* _owner);
    private:
        std::string name;
        Creature* owner;


};

class ChangedDisplayedType : public CreatureAction{
    public:
        ChangedDisplayedType(std::string _name, Creature* _owner);
    private:
        std::string name;
        Creature* owner;

};

class DropPack : public CreatureAction{
    public:
        DropPack(std::string _name, Creature* _owner);
    private:
        std::string name;
        Creature* owner;

};

class EndGame : public CreatureAction{
    public:
        EndGame(std::string _name, Creature* _owner);
    private:
        std::string name;
        Creature* owner;

};





#endif /* CREATUREACTIONSUBCLASSES_HPP */

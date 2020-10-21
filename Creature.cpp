#include <iostream>
#include "Creature.hpp"
#include "CreatureAction.hpp"

Creature::Creature(){
}

void Creature::setHp(int _h){
    h = _h;
    std::cout << "setHp h: " << h <<std::endl;
}

void Creature::setHpMoves(int _hpm){
    hpm = _hpm;
    std::cout << "setHpMoves hpm: " << hpm <<std::endl;
}

void Creature::setDeathAction(CreatureAction *_da){
    creatureActionsForCreatureDa.push_back(_da);
    std::cout << "setDeathAction da: " << da <<std::endl;
}

void Creature::setHitAction(CreatureAction *_ha){
    creatureActionsForCreatureHa.push_back(_ha);
    std::cout << "setHitAction ha: " << ha <<std::endl;
}

std::vector<CreatureAction*> Creature::getDeathAction(){
    return creatureActionsForCreatureDa;
}

std::vector<CreatureAction*> Creature::getHitAction(){
    return creatureActionsForCreatureHa;
}

int Creature::getH( ) const {return h; }

int Creature::getHpm( ) const {return hpm; }

std::ostream& operator<<(std::ostream& os, const Creature& arg) {
    int h = arg.getH( );
    int hpm = arg.getHpm( );
   os << "h: " << h << "hpm: " << hpm << std::endl;
   return os;
}

void Creature::toString(){
    
}

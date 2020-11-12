#include <iostream>
#include "Creature.hpp"
#include "Displayable.hpp"
#include "CreatureAction.hpp"

Creature::Creature(){
}

void Creature::setHp(int _h){
    Hp = _h;
}

void Creature::setHpMoves(int _hpm){
    hpMoves = _hpm;
}

void Creature::setDeathAction(CreatureAction *_da){
    creatureActionsForCreatureDa.push_back(_da);
}

void Creature::setHitAction(CreatureAction *_ha){
    creatureActionsForCreatureHa.push_back(_ha);
}

std::vector<CreatureAction*> Creature::getDeathAction(){
    return creatureActionsForCreatureDa;
}

std::vector<CreatureAction*> Creature::getHitAction(){
    return creatureActionsForCreatureHa;
}

int Creature::getH( ) const {return Hp; }

int Creature::getHpm( ) const {return hpMoves; }

std::ostream& operator<<(std::ostream& os, const Creature& arg) {
    int h = arg.getH( );
    int hpm = arg.getHpm( );
   os << "h: " << h << "hpm: " << hpm << std::endl;
   return os;
}

void Creature::toString(){
    
}

void Creature::SetPosX(int _x){
    posXforCreature = _x;
}

void Creature::setPosY(int _y){
    posYforCreature = _y;
}

int Creature::getPosX(){
    return posXforCreature;
}

int Creature::getPosY(){
    return posYforCreature;
}

int Creature::GetCreaturePosX(){
   return posXforCreature;
}

int Creature::GetCreaturePosY(){
   return posYforCreature;
}


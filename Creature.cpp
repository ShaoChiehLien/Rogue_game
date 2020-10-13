#include <iostream>
#include "Creature.hpp"
#include "CreatureAction.hpp"

void Creature::setHp(int _h){
    h = _h;
    std::cout << "setHp h: " << h <<std::endl;
}

void Creature::setHpMoves(int _hpm){
    hpm = _hpm;
    std::cout << "setHpMoves hpm: " << hpm <<std::endl;
}

void Creature::setDeathAction(CreatureAction *_da){
    da = _da;
    std::cout << "setDeathAction da: " << da <<std::endl;
}

void Creature::setHitAction(CreatureAction *_ha){
    ha = _ha;
    std::cout << "setHitAction ha: " << ha <<std::endl;
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

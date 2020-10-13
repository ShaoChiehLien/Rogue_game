#include <iostream>
#include "Displayable.hpp"

Displayable::Displayable(){
    std::cout << "Displayable::Displayable() " <<  std::endl;
}

void Displayable::setInvisible(){
    std::cout <<"In Displayable::setInvisible "<< std::endl;
}

void Displayable::setVisible(){
    std::cout <<"In Displayable::setVisible "<< std::endl;
}

void Displayable::setMaxHit(int _maxHit){
    maxHit = _maxHit;
    std::cout <<" maxHit: "<< maxHit << std::endl;
}

void Displayable::setHpMove(int _hpMoves){
    hpMoves = _hpMoves;
    std::cout <<"hpMoves: "<< hpMoves<< std::endl;    
}

void Displayable::setHp(int _Hp){
    Hp = _Hp;
    std::cout <<"setHp hp: "<< Hp<< std::endl;    
}

void Displayable::setType(char _t){
    t = _t;
    std::cout <<"setType t: "<< t<< std::endl;    
}

void Displayable::setIntValue(int _v){
    v = _v;
    std::cout <<"setIntValue v: "<< v<< std::endl;    
}

void Displayable::SetPosX(int _x){
    x = _x;
    std::cout <<"SetPosX x: "<< x<< std::endl;    
}

void Displayable::setPosY(int _y){
    y = _y;
    std::cout <<"SetPosY y: "<< y<< std::endl;    
}

void Displayable::SetWidth(int _x){
    x = _x;
    std::cout <<"SetWidth: "<< x<< std::endl;    
}

void Displayable::setHeight(int _y){
    y = _y;
    std::cout <<"SetPosX x: "<< y<< std::endl;    
}

std::string Displayable::toString(){
    std::string str;
    str = "maxHit" + std::to_string(maxHit) +   
            "hpMoves" + std::to_string(hpMoves)  +
            "Hp" + std::to_string(Hp) +
            "v" + std::to_string(v) +
            "x" + std::to_string(x) +
            "y" + std::to_string(y);

    return str;
}

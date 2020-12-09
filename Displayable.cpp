#include <iostream>
#include "Displayable.hpp"

Displayable::Displayable(){
}

Displayable::~Displayable(){
}

void Displayable::setInvisible(){
    visible = 0;
}

void Displayable::setVisible(){
    visible = 1;
}

void Displayable::setMaxHit(int _maxHit){
    maxHit = _maxHit;
}

int Displayable::getMaxHit(){
    return maxHit;
}

void Displayable::setHpMove(int _hpMoves){
    hpMoves = _hpMoves;
}

int Displayable::getHpMove(){
    return hpMoves;  
}

void Displayable::setHp(int _Hp){
    Hp = _Hp;
}

int Displayable::getHp(){
    return Hp;
}

void Displayable::setType(char _t){
    t = _t;  
}

char Displayable::getType(){
    return t;   
}

void Displayable::setIntValue(int _v){
    v = _v;
}

void Displayable::SetPosX(int _x){
    posX.push_back(_x); 
}

void Displayable::setPosY(int _y){
    posY.push_back(_y); 
}

int Displayable::getPosX(){
    int temp = posX.back();
    posX.pop_back();
    return temp; 
}

int Displayable::getPosY(){
    int temp = posX.back();
    posX.pop_back();
    return temp; 
}

void Displayable::SetWidth(int _width){
    width = _width;   
}

void Displayable::setHeight(int _height){
    height = _height;   
}

std::string Displayable::toString(){
    std::string str;
    str = "maxHit" + std::to_string(maxHit) +   
            "hpMoves" + std::to_string(hpMoves)  +
            "Hp" + std::to_string(Hp) +
            "v" + std::to_string(v);
    return str;
}

int Displayable::getIntValue(){
    return v;
}


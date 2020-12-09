#include <iostream>
#include "Action.hpp"

void Action::setMessage(std::string _msg){
    msg = _msg;
    //std::cout << "Action::setMessage : " << msg << std::endl;
}

void Action::setIntValue(int _v){
    v = _v;
    //std::cout << "Action::setIntValue : " << v << std::endl;
}

void Action::setCharValue(char _c){
    c = _c;
    //std::cout << "Action::setCharValue : " << c << std::endl;
}

std::string Action::toString(){
    std::string str;
    str = "Message: " + msg + " Int Value: " + std::to_string(v) + " Char Value: " + c + "\n";
    
    return str;
}

std::string Action::getMessage(){
    return msg;
}


int Action::getIntValue(){
    return v;
}


char Action::getCharValue(){
    return c;
}


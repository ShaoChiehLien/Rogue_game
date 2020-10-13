#include <iostream>
#include "Action.hpp"

void Action::setMessage(std::string _msg){
    msg = _msg;
    std::cout << "Action::setMessage : " << msg << std::endl;
}

void Action::setIntValue(int _v){
    v = _v;
    std::cout << "Action::setIntValue : " << v << std::endl;
}

void Action::setCharValue(char _c){
    c = _c;
    std::cout << "Action::setCharValue : " << c << std::endl;
}

std::string Action::toString(){
    std::string str;
    str = "string msg:" + msg +
            "v:" + std::to_string(v) + 
            "c:" + c;
    return str;
}


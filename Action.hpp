#ifndef ACTION_HPP
#define ACTION_HPP
#include <iostream>

class Action{
    public:
        void setMessage(std::string _msg);
        void setIntValue(int _v);
        void setCharValue(char _c);
        std::string toString();
    private:
        std::string msg;
        int v;
        char c;
};



#endif /* ACTION_HPP */
#ifndef ACTION_HPP
#define ACTION_HPP
#include <iostream>

class Action{
    public:
        void setMessage(std::string _msg);
        void setIntValue(int _v);
        void setCharValue(char _c);
        std::string toString();

        virtual std::string getMessage();
        virtual int getIntValue();
        virtual char getCharValue();
        
    protected:
        std::string msg = "";
        int v = 0;
        char c = 0;
};



#endif /* ACTION_HPP */
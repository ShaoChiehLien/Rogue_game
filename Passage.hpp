#ifndef PASSAGE_HPP
#define PASSAGE_HPP
#include <iostream>
#include <string>
#include "Structure.hpp"

class Passage: public Structure{
    public:
        Passage(int _room1, int _room2);
        void setName(std::string _passageName);
        void setID(int _room1, int _room2);
    std::string toString();

    private:
        std::string passageName;
        int room1;
        int room2;
      
};




#endif /* PASSAGE_HPP */

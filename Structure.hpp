#ifndef STRUCTURE_H_
#define STRUCTURE_H_
#include <iostream>
#include "Displayable.hpp"

class Structure: public Displayable{
    public:
        Structure( );
        virtual std::vector<int> GetStructurePosX();
        virtual std::vector<int> GetStructurePosY();
        virtual ~Structure();
};




#endif /* STRUCTURE_HPP */
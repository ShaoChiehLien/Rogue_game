#include <iostream>
#include "Structure.hpp"

Structure::Structure(){
    std::cout << "Structure::Structure() " <<  std::endl;
}

Structure::~Structure(){
}

std::vector<int> Structure::GetStructurePosX(){
   return posX;
}

std::vector<int> Structure::GetStructurePosY(){
   return posY;
}

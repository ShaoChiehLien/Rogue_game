#include <iostream>
#include "Structure.hpp"

Structure::Structure(){
}

Structure::~Structure(){
}

std::vector<int> Structure::GetStructurePosX(){
   return posX;
}

std::vector<int> Structure::GetStructurePosY(){
   return posY;
}

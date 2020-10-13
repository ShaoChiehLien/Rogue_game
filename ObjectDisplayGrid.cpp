#include <iostream>
#include <string>
#include "ObjectDisplayGrid.hpp"

void ObjectDisplayGrid::getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight){
    std::cout << "get gameheight: "<< _gameHeight << std::endl;
    std::cout << "get width: "<< _width << std::endl;
    std::cout << "get topHeight: "<< _topHeight << std::endl;

}

void ObjectDisplayGrid::setTopMessageHeight(int _topHeight){
     std::cout << "setting topHeight: "<< _topHeight << std::endl;
}

/*
ObjectDisplayGrid::ObjectDisplayGrid(int _gameHeight, int _width, int _topHeight){
    gameHeight = _gameHeight;
    width = _width;
    topHeight = _topHeight;
}
*/



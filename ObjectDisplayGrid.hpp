#ifndef OBJECTDISPLAYGRID_HPP_
#define OBJECTDISPLAYGRID_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "GridChar.hpp"


class ObjectDisplayGrid{
    public:
        ObjectDisplayGrid(int _gameHeight, int _width, int _topHeight);

        ObjectDisplayGrid(int _gameHeight, int _width, int posX, int posY);

        void setTopMessageHeight(int _topHeight);
        //ObjectDisplayGrid(int gameHeight, int width, int topHeight);
        ~ObjectDisplayGrid();
        //virtual void addObjectToDisplay(GridChar* ch, int x, int y);
        virtual void update();
        virtual void writeLine(int line, std::string message);
        virtual void writeTop(int line, std::string message);
        //virtual void addObjectToDisplay(GridChar* ch, int x, int y);
        virtual void addObjectToDisplay(char ch, int x, int y);
        void removeObjectFromDisplay(int x, int y);
        char topObjectFromDisplay(int x, int y);
    
        //add object stack code
        void addObj(Displayable *obj, int x, int y);
        void removeStackObj(int x, int y);
        Displayable* topObjStack(int x, int y);

        int getHeight();
        int getWidth();

    
    private:
        int topHeight;  
        int gameHeight;
        int width;
        int posX;
        int posY;
        GridChar*** objectGrid;
};




#endif /* OBJECTDISPLAYGRID_H_ */
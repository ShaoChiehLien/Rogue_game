#ifndef OBJECTDISPLAYGRID_H_
#define OBJECTDISPLAYGRID_H_
#include <iostream>
#include <string>

class ObjectDisplayGrid{
    public:
        void getObjectDisplayGrid(int _gameHeight, int _width, int _topHeight);
        void setTopMessageHeight(int _topHeight);
        //ObjectDisplayGrid(int gameHeight, int width, int topHeight);
    
    private:
        int topHeight;  
        int gameHeight;
        int width;

};




#endif /* OBJECTDISPLAYGRID_H_ */
#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP
#include <iostream>
#include <vector>

class Displayable{
    public:
        Displayable( );
        void setInvisible( );
        void setVisible( );
        void setMaxHit(int _maxHit );
        void setHpMove(int _hpMoves );
        void setHp(int _Hp);
        void setType(char _t);
        void setIntValue(int _v);
        void SetWidth(int _width);
        void setHeight(int _height);
        std::string toString();
        virtual ~Displayable();

        virtual void SetPosX(int _x);
        virtual void setPosY(int _y);
    
    protected:
        int visible = 0;
        int maxHit = 0;
        int hpMoves = 0;
        int Hp = 0;
        char t;
        int v = 0;
        std::vector<int> posX;
        std::vector<int> posY;

        int posXforCreature;
        int posYforCreature;

        int posXforItem;
        int posYforItem;

        int width = 0;
        int height = 0;
    
};




#endif /* DISPLAYABLE_HPP */
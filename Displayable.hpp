#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP
#include <iostream>

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
        void SetPosX(int _x);
        void setPosY(int _y);
        void SetWidth(int _x);
        void setHeight(int _y);
        std::string toString();
    
    private:
        int maxHit;
        int hpMoves;
        int Hp;
        char t;
        int v;
        int x;
        int y;
        //width x
        //wdity y ??
    
};




#endif /* DISPLAYABLE_HPP */
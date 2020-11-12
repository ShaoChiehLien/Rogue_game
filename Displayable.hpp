#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP
#include <iostream>
#include <vector>

class Displayable{
    public:
        Displayable( );
        void setInvisible( );
        void setVisible( );
        virtual void setMaxHit(int _maxHit );
        virtual void setHpMove(int _hpMoves );
        virtual void setHp(int _Hp);
        virtual void setType(char _t);
        virtual void setIntValue(int _v);
        virtual void SetWidth(int _width);
        virtual void setHeight(int _height);

        virtual int getMaxHit();
        virtual int getHpMove();
        virtual int getHp();
        virtual char getType();

        std::string toString();
        virtual ~Displayable();

        virtual void SetPosX(int _x);
        virtual void setPosY(int _y);

        virtual int getPosX();
        virtual int getPosY();
    
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
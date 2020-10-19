#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Displayable.hpp"
#include <iostream>

class CreatureAction;
class Creature : public Displayable{
    public:
        void setHp(int _h);
        void setHpMoves(int _hpm);
        void setDeathAction(CreatureAction *_da);
        void setHitAction(CreatureAction *_ha);
        void toString();

        //std::string toString();
        virtual int getH( ) const;
        virtual int getHpm( ) const;
    private:
        int h;
        int hpm;
        CreatureAction *da;
        CreatureAction *ha;
};

std::ostream& operator<<(std::ostream&, const Creature&);

#endif /* CREATURE_HPP */

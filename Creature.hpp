#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Displayable.hpp"
#include <iostream>

class CreatureAction;
class Creature : public Displayable{
    public:
        Creature();
        void setHp(int _h);
        void setHpMoves(int _hpm);
        void setDeathAction(CreatureAction *_da);
        void setHitAction(CreatureAction *_ha);
        std::vector<CreatureAction*> getDeathAction();
        std::vector<CreatureAction*> getHitAction();
        void toString();

        //std::string toString();
        virtual int getH( ) const;
        virtual int getHpm( ) const;

        virtual int GetCreaturePosX();
        virtual int GetCreaturePosY();

        virtual void SetPosX(int _x);
        virtual void setPosY(int _y);

    protected:
        int h;
        int hpm;
        std::vector<CreatureAction*> creatureActionsForCreatureDa;
        std::vector<CreatureAction*> creatureActionsForCreatureHa;
        CreatureAction *da = nullptr;
        CreatureAction *ha = nullptr;
};

std::ostream& operator<<(std::ostream&, const Creature&);

#endif /* CREATURE_HPP */

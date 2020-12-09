#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Displayable.hpp"
#include <iostream>

class CreatureAction;
class Creature : public Displayable{
    public:
        Creature();
        virtual void setHp(int _h);
        virtual void setHpMoves(int _hpm);
        virtual void setDeathAction(CreatureAction *_da);
        virtual void setHitAction(CreatureAction *_ha);
        virtual std::vector<CreatureAction*> getDeathAction();
        virtual std::vector<CreatureAction*> getHitAction();
        void toString();

        //std::string toString();
        virtual int getH( ) const;
        virtual int getHpm( ) const;

        virtual int GetCreaturePosX();
        virtual int GetCreaturePosY();

        virtual void SetPosX(int _x);
        virtual void setPosY(int _y);

        virtual int getPosX();
        virtual int getPosY();

    //protected:
    private:
        std::vector<CreatureAction*> creatureActionsForCreatureDa;
        std::vector<CreatureAction*> creatureActionsForCreatureHa;
        CreatureAction *da = nullptr;
        CreatureAction *ha = nullptr;
};

std::ostream& operator<<(std::ostream&, const Creature&);

#endif /* CREATURE_HPP */

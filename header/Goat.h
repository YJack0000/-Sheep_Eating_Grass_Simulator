#ifndef _GOAT_H
#define _GOAT_H

#include "Creature.h"

class Goat : public Creature{
    
    public:

        Goat(){
            life = 0;
            life_point = 0;
        }

        bool isGonnaDie(){
            return (life == 70) || (life_point == 0);
        }

        bool canHaveBaby(){
            return (life>=50) && (life<=55);
        }

        void getOneDayOlder(){
            life += 1;
        }

        void changeLifePoint(int k){
            life_point += k;
        }

    private:

        int life_point;

};

#endif
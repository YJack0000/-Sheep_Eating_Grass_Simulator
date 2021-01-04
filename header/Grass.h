#ifndef _GRASS_H
#define _GRASS_H

#include "Creature.h"

class Grass : public Creature{
    
    public:

        Grass(){
            life = 0;
        }

        bool isGonnaDie(){
            return (life >= 6);
        }

        bool canHaveBaby(){
            return (life>=3) && (life<=5);
        }

    private:

};

#endif
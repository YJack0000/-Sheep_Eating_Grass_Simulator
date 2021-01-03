#ifndef _CREATURE_H
#define _CREATURE_H

class Creature{

    protected:

        virtual bool isGonnaDie();

        virtual bool canHaveBaby();

        void increaseAge(){
            life += 1;
        }

    protected:
        
        int life;

};

#endif
#ifndef _CREATURE_H
#define _CREATURE_H

class Creature{

    public:
    
        void increaseAge(){
            life += 1;
        }

    protected:

        virtual bool isGonnaDie() = 0;

        virtual bool canHaveBaby() = 0;
        
        int life;

};

#endif
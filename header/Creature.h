#ifndef _CREATURE_H
#define _CREATURE_H

class Creature{

    public:
    
        void increaseAge(){
            life += 1;
        }

    protected:

        virtual bool isGonnaDie();

        virtual bool canHaveBaby();

    protected:
        
        int life;

};

#endif
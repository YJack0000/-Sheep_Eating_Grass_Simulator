#ifndef _GOATS_H
#define _GOATS_H

#include <map>

#include "Goat.h"
#include "RandomNum.h"

class Goats{
    
    public:

        Goats(int seed);

        bool isGoat(std::pair<int, int>);

        bool pregnant(std::pair<int, int>);

        void eat(std::pair<int, int>);

        void move(std::pair<int ,int>, std::pair<int, int>);

        void produce(std::pair<int, int>);

        bool older(std::pair<int ,int>);

        void die(std::pair<int, int>);

    private:

        std::map<std::pair<int, int>, Goat> goats;
        RandomNum _rand_;

};

#endif
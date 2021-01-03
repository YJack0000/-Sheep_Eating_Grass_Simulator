#ifndef _WORLD_H
#define _WORLD_H

#include <iostream>

#include "RandomNum.h"
#include "Goats.h"
#include "Grasses.h"

class World{

    public:
        
        World(int num_pass, int seed);

        void mainLoop(int interval);

    private:

        int remain_pass;

        RandomNum _rand_;

        Goats goats;
        Grasses grasses;

        void print();

        bool isOutOfRange(std::pair<int ,int>);

        bool check(std::pair<int, int>);

        std::pair<int, int> generateNewPos(std::pair<int, int>);

        void goatPass(std::pair<int ,int >);

        void grassPass(std::pair<int ,int>);

};

#endif
#ifndef _GRASSES_H
#define _GRASSES_H

#include <map>

#include "Grass.h"
#include "RandomNum.h"

class Grasses{

    public:

        Grasses(int seed);

        bool isGrass(std::pair<int, int>);

        bool pregnant(std::pair<int, int>);

        void produce(std::pair<int, int>);

        bool older(std::pair<int, int>);

        void die(std::pair<int, int>);

    private:

        std::map<std::pair<int, int>, Grass> grasses;
        RandomNum _rand_;

};

#endif
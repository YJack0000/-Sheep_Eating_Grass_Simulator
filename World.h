#ifndef _WORLD_H
#define _WORLD_H

class World{

    public:
        
        World(int num_pass, int seed);

        void mainLoop();

    private:

        RandomNum _rand_;
        int remain_pass;

        char world[35][20];

        map<pair<int, int>, Goat> goats;
        map<pair<int, int>, Grass> grasses; 

}

#endif
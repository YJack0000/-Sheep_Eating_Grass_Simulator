#include "../header/World.h"

World::World(int num_pass, int seed) : _rand_(seed), goats(seed), grasses(seed){
    remain_pass = num_pass;
}

void World::mainLoop(int interval){
    while(remain_pass--){
        for(int i=0; i<35; i++){
        for(int j=0; j<20; j++){
            std::pair<int, int> pos = std::make_pair(i, j);
            if(goats.isGoat(pos)){//goat
                this->goatPass( std::make_pair(i, j) );
            }else if(grasses.isGrass(pos)){//grass
                this->grassPass( std::make_pair(i, j) );
            }
        }
        }
        if(remain_pass % interval == 0) this->print();
    }
}

void World::print(){
    for(int i=0; i<35; i++)
        std::cout << i%10 << " ";
    for(int i=0; i<20; i++){
        std::cout << i%10 << " ";
        for(int j=0; j<35; j++){
            std::pair<int, int> pos = std::make_pair(i, j);
            if(goats.isGoat(pos)){//goat
                std::cout << 'X' ;
            }else if(grasses.isGrass(pos)){//grass
                std::cout << 'I' ;
            }
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

bool World::isOutOfRange(std::pair<int ,int> pos){
    return pos.first>=20 || pos.first<0 || pos.second>=35 || pos.second<0;
}

bool World::check(std::pair<int, int> pos){
    return !(goats.isGoat(pos)) && !(grasses.isGrass(pos)) && !this->isOutOfRange(pos) ;
}

std::pair<int, int> World::generateNewPos(std::pair<int, int> pos){
    std::pair<int, int> dir[4] = {std::make_pair(1, 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)};
    int choose = _rand_.getRandomNum(0, 3);
    return std::make_pair(pos.first + dir[choose].first, pos.second + dir[choose].second);
}

void World::goatPass(std::pair<int, int> this_pos){
    if( !goats.older(this_pos)){
        goats.die(this_pos);
        return ;
    }

    std::pair<int, int> to_pos = this->generateNewPos(this_pos);

    if( goats.pregnant(this_pos) ){
        if(grasses.isGrass(to_pos)){//pregnant goat eat grass
            goats.eat(this_pos);
            grasses.die(to_pos);
        }

        if(this->check(to_pos)){//pregnant goat give birth to new baby
            goats.produce(to_pos);
        }
    }else{
        if(this->check(to_pos)){
            goats.move(this_pos, to_pos);
        }
    }
}

void World::grassPass(std::pair<int, int> this_pos){
    if( !grasses.older(this_pos) ){
        grasses.die(this_pos);
        return ;
    }

    std::pair<int, int> to_pos = this->generateNewPos(this_pos);

    if( grasses.pregnant(this_pos) ){
        if(this->check(to_pos)){//pregnant goat give birth to new baby
            grasses.produce(to_pos);
        }
    }
}
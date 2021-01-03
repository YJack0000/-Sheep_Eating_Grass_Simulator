#include "../header/Goats.h"

Goats::Goats(int seed) : _rand_(seed){
    for(int i=0; i<5; i++){
        std::pair<int, int> pos(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        while(goats.count(pos)){
            pos = std::make_pair(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        }
        goats[pos] = Goat();
    }
}

bool Goats::isGoat(std::pair<int, int> pos){
    return goats.count(pos);
}

bool Goats::pregnant(std::pair<int, int> pos){
    return goats[pos].canHaveBaby();
}

bool older(std::pair<int, int> pos){
    goats[pos].getOneDayOlder();
    goats[pos].changeLifePoint(-1);
    return !(goats[pos].isGonnaDie());
}

void Goats::eat(std::pair<int, int> pos){
    goats[pos].changeLifePoint(+5);
}

void Goats::move(std::pair<int, int> from_pos, std::pair<int, int> to_pos){
    goats[to_pos] = goats[from_pos];
    goats.erase(from_pos);
}

void Goats::produce(std::pair<int, int> pos){
    goats[pos] = Goat();
}

void Goats::die(std::pair<int, int> pos){
    goats.erase(pos);
}
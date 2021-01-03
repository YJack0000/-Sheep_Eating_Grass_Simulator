World::World(int num_pass, int seed) : _rand_(seed){
    remain_pass = num_pass;
    
    for(int i=0; i<5; i++){
        std::pair<int, int> pos(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        while(goats.count(pos)){
            pos = make_pair(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        }

        goats[pos] = Goat();
    }

    for(int i=0; i<10; i++){
        std::pair<int, int> pos(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        while(grasses.count(pos)){
            pos = make_pair(_rand_.getRandomNum(0, 20-1), _rand_.getRandomNum(0, 35-1));
        }

        grasses[pos] = Grass();
    }
}

void World::mainLoop(){
    while(remain_pass--){
        for(int i=0; i<35; i++){
            for(int j=0; j<20; j++){
                pair<int, int> this_pos = make_pair(i, j);
                if(world == 'X'){//goat
                    this->goatPass(this_pos);
                }else if(world == 'I'){//grass

                }
            }
        }

        print(world);
    }
}

void goatPass(pair<int, int> this_pos){
    Goat this_goat = goats[this_pos];
    pair<int, int> to_pos;
                    
    if(this_goat.isGonnaDie()){
        goats.erase(this_pos);
        continue;
    }

    if( this_goat.canHaveBaby() ){
        to_pos = this_goat.produce();

        if(this->isGrass(to_pos)){//pregnant goat eat grass
            this_goat.eat();
            grassDie(to_pos);
        }

        if(this->check(to_pos)){//pregnant goat give birth to new baby
            goatProduce(to_pos);
        }
    }else{
        to_pos = this_goat.go();

        if(this->check(to_pos)){
            goatMove(to_pos);
            /*
            goats.earse(this_pos);
            goats[to_pos] = this_goat;
            */
        }
    }
}
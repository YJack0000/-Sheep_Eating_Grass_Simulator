#include <iostream>
#include "RandomNum.h"
using namespace std;

int main(){
    RandomNum r(123);
    for(int i=0; i<10; i++){
        cout << r.getRandomNum(1, 4) << endl;
    }
}
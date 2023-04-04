#include<iostream>
#include <string>

#include "player.hpp"
using namespace std;

namespace ariel
{

    int Player::stacksize(){
        return 1;
    }
    int Player::cardesTaken(){
        return 2;
    }

}; // namespace ariel
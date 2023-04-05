#include<iostream>
#include <string>

#include "player.hpp"
using namespace std;

namespace ariel
{

    int Player::stacksize(){
        return hand.size();
    }
    int Player::cardesTaken(){
        return this->cardsTaken;
    }

}; // namespace ariel
#include<iostream>
#include <string>

#include "player.hpp"
using namespace std;

namespace ariel
{

    int Player::stacksize(){
        return this->hand.size();
    }
    int Player::cardesTaken(){
        return this->cardsTaken;
    }

    Card Player::drawCard(){
        if (this->stacksize() == 0){ throw "No more cards.."; }
        Card card = hand.front();
        hand.pop_front();
        return card;    
    }

    void Player::addCardToHand(Card& card){
        hand.push_back(card);
        // std::cout << "Player " << name << " hand size: " << hand.size() << std::endl;            
    }

}; // namespace ariel
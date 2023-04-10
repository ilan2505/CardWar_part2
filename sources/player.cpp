/*
References :
 https://en.cppreference.com/w/cpp/container/deque
 https://cplusplus.com/reference/deque/deque/
 https://en.cppreference.com/w/cpp/container/deque/pop_front
 https://en.cppreference.com/w/cpp/container/vector
 https://cplusplus.com/reference/vector/vector/back/
 https://www.digitalocean.com/community/tags/c-plus-plus
 https://cplusplus.com/reference/cstdlib/rand/
*/

#include<iostream>
#include <string>

#include "player.hpp"
using namespace std;

namespace ariel
{

    int Player::stacksize(){  return this->hand.size(); }
    int Player::cardesTaken(){ return this->cardsWon.size(); }

    Card Player::drawCard(){
        if (this->stacksize() == 0){ throw "No more cards.."; }
        Card card = hand.front();          
        hand.pop_front();          
        return card;    
    }

    void Player::addCardToHand(Card& card){
        this->wins++;
        hand.push_back(card);
    }

    void Player::addWinningCard(vector<Card>& cards){
        this->wins++;
        while (!cards.empty()) {
            Card card = cards.back();   
            cards.pop_back();           
            cardsWon.push_back(card);
        }
        
    }

    void Player::addWinningCard(Card& card){ cardsWon.push_back(card); }

}; // namespace ariel

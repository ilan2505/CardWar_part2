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
        return this->cardsWon.size();
    }

    Card Player::drawCard(){
        if (this->stacksize() == 0){ throw "No more cards.."; }
        Card card = hand.front();          
        hand.pop_front();
        // std::cout << name << " hand size: " << hand.size() << std::endl;            
        // std::cout << "drawCard  " << card.toString() << std::endl; 
        // std::cout << name << " hand size: " << hand.size() << std::endl;          
        return card;    
    }

    void Player::addCardToHand(Card& card){
        hand.push_back(card);
        // std::cout << "Player " << name << " hand size: " << hand.size() << std::endl;            
    }
    void Player::addWinningCard(vector<Card>& cards){
        while (!cards.empty()) {
            Card card = cards.back();   
            cards.pop_back();           
            cardsWon.push_back(card);
            // std::cout << name << " cardsWon size: " << cardsWon.size() << std::endl;            
            // std::cout << "addWinningCard  " << card.toString() << std::endl; 
            // std::cout << name << " cardsWon size: " << cardsWon.size() << std::endl;    
        }
    }

    void Player::addWinningCard(Card& card){
        // std::cout << name << " cardsWon size: " << cardsWon.size() << std::endl;
        // std::cout << "addWinningCard  " << card.toString() << std::endl; 
        cardsWon.push_back(card); 
        // std::cout << name << " cardsWon size: " << cardsWon.size() << std::endl;  
    }

}; // namespace ariel
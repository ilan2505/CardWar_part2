#pragma once

#include<iostream>
#include <string>
#include <deque>

#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            deque<Card> hand;
        
            int cardsTaken;
        public:
            Player(const string& player_name): name(player_name), cardsTaken(0){}
            inline string playerName(){return this->name;}
            inline deque<Card>& getHand() { return hand; }
            void addCardToHand(Card& card);
            int stacksize();
            int cardesTaken();
            Card drawCard();
            
    }; // class Player

}; // namespace ariel


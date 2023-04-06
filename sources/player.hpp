#pragma once

#include<iostream>
#include <string>
#include <deque>
#include <vector>

#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            deque<Card> hand;
            vector<Card> cardsWon;

        public:
            Player(const string& player_name): name(player_name){}
            inline string playerName(){return this->name;}
            inline deque<Card>& getHand() { return hand; }
            void addCardToHand(Card& card);
            int stacksize();
            int cardesTaken();
            Card drawCard();
            void addWinningCard(vector<Card>& cards);
            void addWinningCard(Card& card);

            
    }; // class Player

}; // namespace ariel


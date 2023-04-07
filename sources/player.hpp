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
            int wins;

        public:
            Player(const string& player_name): name(player_name), wins(0){}

            Card drawCard();
            void addCardToHand(Card& card);
            void addWinningCard(vector<Card>& cards);
            void addWinningCard(Card& card);

            // #-#-# Getters #-#-#
            int stacksize();
            int cardesTaken();
            inline int getWins() const{return this->wins;}
            inline string playerName(){return this->name;}
            inline deque<Card>& getHand() { return hand; }

            
    }; // class Player

}; // namespace ariel


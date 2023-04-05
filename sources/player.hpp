#pragma once

#include<iostream>
#include <string>
#include <vector>

#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            vector<Card> hand;
            int cardsTaken;
        public:
            Player(const string& player_name): name(player_name), cardsTaken(0){}
            inline string playerName(){return this->name;}
            // return a Ref to the hand field
            inline const vector<Card>& getHand() const{ return hand; }
            inline void addCardToHand(const Card& card){ hand.push_back(card);}
            int stacksize ();
            int cardesTaken ();
            
    }; // class Player

}; // namespace ariel


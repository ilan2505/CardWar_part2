#pragma once
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel {

    // This is for readability only
    enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};

    class Card {

        private:
            Suit suit;
            int value;

        public:
            Card(int sut, int val);

            string toString() const;
            int getCardVal() const {return value;}
            Suit getSuit() const {return suit;}

    }; // class Card

} // namespace ariel

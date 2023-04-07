#pragma once
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel {

    // This is for readability only - can use integers but this is more clear
    enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};

    class Card {

        private:
            Suit suit;
            int value;

        public:
            Card(int sut, int val);
            string toString() const;

            // #-#-# Getters #-#-#
            inline int getCardVal() const {return value;}
            inline Suit getSuit() const {return suit;}

    }; // class Card

} // namespace ariel

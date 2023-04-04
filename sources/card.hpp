#pragma once
#include "card.hpp"
#include <string>
using namespace std;

namespace ariel {

    enum Suit {SPADES, HEARTS, CLUBS, DIAMONDS};
    enum Value {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING = 13};

    class Card {

        private:
            Suit suit;
            Value value;
            int card_value;

        public:
            Card(int sut, int val);

            string to_string() const;
            int get_card_value() const {return card_value;}

    }; // class Card

} // namespace ariel

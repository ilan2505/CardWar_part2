#include "card.hpp"
#include <string>

namespace ariel {

    Card::Card(int sut, int val){ 
        switch(sut) {
            case 0:   suit = SPADES;     break;
            case 1:   suit = HEARTS;     break;
            case 2:   suit = CLUBS;      break;
            case 3:   suit = DIAMONDS;   break;
        }

        switch(val) {
            case 1:   value = ACE;    break;
            case 2:   value = TWO;    break;
            case 3:   value = THREE;  break;
            case 4:   value = FOUR;   break;
            case 5:   value = FIVE;   break;
            case 6:   value = SIX;    break;
            case 7:   value = SEVEN;  break;
            case 8:   value = EIGHT;  break;
            case 9:   value = NINE;   break;
            case 10:  value = TEN;    break;
            case 11:  value = JACK;   break;
            case 12:  value = QUEEN;  break;
            case 13:  value = KING;   break;
        }
    }


    string Card::to_string() const {
        std::string suit_string;
        switch(suit) {
            case SPADES:    suit_string = "Spades";     break;
            case HEARTS:    suit_string = "Hearts";     break;
            case CLUBS:     suit_string = "Clubs";      break;
            case DIAMONDS:  suit_string = "Diamonds";   break;
        }

        std::string value_string;
        switch(value) {
            case ACE:   value_string = "Ace";    break;
            case TWO:   value_string = "Two";    break;
            case THREE: value_string = "Three";  break;
            case FOUR:  value_string = "Four";   break;
            case FIVE:  value_string = "Five";   break;
            case SIX:   value_string = "Six";    break;
            case SEVEN: value_string = "Seven";  break;
            case EIGHT: value_string = "Eight";  break;
            case NINE:  value_string = "Nine";   break;
            case TEN:   value_string = "Ten";    break;
            case JACK:  value_string = "Jack";   break;
            case QUEEN: value_string = "Queen";  break;
            case KING:  value_string = "King";   break;
        }

        return value_string + " of " + suit_string;
    }


}


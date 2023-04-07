#include "card.hpp"
#include <string>

namespace ariel {

    Card::Card(int sut, int val) : value(val) { 
        switch(sut) {
            case 0:   suit = SPADES;     break;
            case 1:   suit = HEARTS;     break;
            case 2:   suit = CLUBS;      break;
            case 3:   suit = DIAMONDS;   break;
        }

    }


    string Card::toString() const {
        
        std::string suitAsString;
        std::string valueAsString;

        switch(suit) {
            case SPADES:    suitAsString = "Spades";     break;
            case HEARTS:    suitAsString = "Hearts";     break;
            case CLUBS:     suitAsString = "Clubs";      break;
            case DIAMONDS:  suitAsString = "Diamonds";   break;
        }

        switch(value) {
            case 1:   valueAsString = "Ace";    break;
            case 2:   valueAsString = "Two";    break;
            case 3:   valueAsString = "Three";  break;
            case 4:   valueAsString = "Four";   break;
            case 5:   valueAsString = "Five";   break;
            case 6:   valueAsString = "Six";    break;
            case 7:   valueAsString = "Seven";  break;
            case 8:   valueAsString = "Eight";  break;
            case 9:   valueAsString = "Nine";   break;
            case 10:  valueAsString = "Ten";    break;
            case 11:  valueAsString = "Jack";   break;
            case 12:  valueAsString = "Queen";  break;
            case 13:  valueAsString = "King";   break;
        }

        return valueAsString + " of " + suitAsString;
    }

}


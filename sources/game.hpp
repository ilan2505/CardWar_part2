#pragma once

#include <string>
#include <vector>

#include "player.hpp"
#include "card.hpp"

const int DECK_SIZE = 52;
const int SUIT_SIZE = 4;
const int VALUE_SIZE = 14;

namespace ariel 
{
    class Game 
    {
    private:
        Player& p1;
        Player& p2;
        vector<Card> deck;
        void initializeDeck();
        void dealCardsToPlayers();
        void gameInitValidation();

    public:
        Game(Player& player1, Player& player2);
        void playTurn();
        void playAll();
        void printLastTurn();
        void printLog();
        void printWiner();
        void printStats();
        // void printDeck();

    }; // class Game 

} // namespace ariel


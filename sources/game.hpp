#pragma once

#include <string>
#include <vector>

#include "player.hpp"
#include "card.hpp"

const int DECK_SIZE = 52;
const int SUIT_SIZE = 4;
const int VALUE_SIZE = 13;

namespace ariel 
{
    class Game 
    {
    private:

        Player& p1;
        Player& p2;

        vector<Card> deck;
        vector<Card> currentTurnStash;

        vector<string> log;
        int draws;

        void initializeDeck();
        void dealCardsToPlayers();
        void gameInitValidation();
        void tieBreakerHandler();
        void splitStash();
        void uniqueCardValidation(Card& card1, Card& card2);
        bool isStacksAreEmpty(); // to avoid duplicate code

    public:
        Game(Player& player1, Player& player2);

        void playTurn();
        void playAll();

        void printLastTurn();
        void printLog();
        void printWiner();
        void printStats();

    }; // class Game 

} // namespace ariel


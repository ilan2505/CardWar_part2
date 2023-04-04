#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "game.hpp"
using namespace ariel;

namespace ariel {


    Game::Game(Player& player1, Player& player2) : p1(player1), p2(player2){

        Game::initializeDeck();
        Game::dealCardsToPlayers();

    }

    void Game::playTurn(){ cout << "playTurn" << endl; }
    void Game::printLastTurn(){ cout << "printLastTurn" << endl; }
    void Game::playAll(){ cout << "playAll" << endl; }
    void Game::printWiner(){  cout << "printWiner" << endl; }
    void Game::printLog(){  cout << "printLog" << endl; }
    void Game::printStats(){ cout << "printStats" << endl; }


    void Game::printDeck() {
        for (auto it = deck.begin(); it != deck.end(); ++it) {
            Card c = *it;
            std::cout << c.to_string() << endl;
        }
    }





    // Methods which the constructor is calling 
    // to orgnize the code
    void Game::initializeDeck(){
        for (int s = 0; s < SUIT_SIZE; s++) {
            for (int v = 1; v < VALUE_SIZE; v++) {
                Card card(s, v);
                deck.push_back(card);
            }
        }

        srand( (time(NULL)));
        // Shuffle the deck
        for (int i = 0; i < 1000; i++) {

            uint tmp1 = (uint) (rand() % DECK_SIZE);
            uint tmp2 = (uint) (rand() % DECK_SIZE);

            //Swap
            Card temporary = deck[tmp1];
            deck[tmp1] = deck[tmp2];
            deck[tmp2] = temporary;
        }
    }

    bool isEven(int i){ return i % 2 == 0;}
    void Game::dealCardsToPlayers(){
        for (int i = 0; i < DECK_SIZE; i++) {
            if (isEven(i)) { 
                 p1.addCardToHand(deck [(unsigned long)i]);
            } else {
                 p2.addCardToHand(deck [(unsigned long)i]);
            }
        }
    }
}; // namespace ariel
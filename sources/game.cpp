#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "game.hpp"
using namespace ariel;

namespace ariel {


    Game::Game(Player& player1, Player& player2) : p1(player1), p2(player2){
        Game::gameInitValidation();
        Game::initializeDeck();
        Game::dealCardsToPlayers();
    }

    void Game::playTurn(){ 
        if(p1.stacksize() == 0 || p2.stacksize() == 0){
             throw "Players cannot plays, ran out of cards."; 
        }else{
            // need here to take card from each player - implement this
            Card playerOneCard = p1.drawCard();
            Card playerTwoCard = p2.drawCard();

            if (playerOneCard.getCardVal() > playerTwoCard.getCardVal()){
                
            }else if (playerOneCard.getCardVal() < playerTwoCard.getCardVal()){
                
            }else{
                // Tie Breaker
            }
         }
    }
    void Game::printLastTurn(){ cout << "printLastTurn" << endl; }

    void Game::playAll(){
         while (p1.stacksize() != 0 && p2.stacksize() != 0){ Game::playTurn(); }
    }

    void Game::printWiner(){ 

        if (p1.cardesTaken() == p2.cardesTaken()){  throw "There is a tie, no one wins."; }
        else {
            if(p1.cardesTaken() > p2.cardesTaken()){
                cout << p1.playerName() << endl;
            }else{
                cout << p2.playerName() << endl;
            }
        }
    }

    void Game::printLog(){  cout << "printLog" << endl; }
    void Game::printStats(){ cout << "printStats" << endl; }


    // void Game::printDeck() {
    //     for (auto it = deck.begin(); it != deck.end(); ++it) {
    //         Card c = *it;
    //         std::cout << c.toString() << endl;
    //     }
    // }





    // Methods which the constructor is calling 
    // in order to orgnize the code
    void Game::gameInitValidation(){
        if (p1.stacksize() > 0 
        || p2.stacksize() > 0
        || p1.cardesTaken() > 0
        || p2.cardesTaken() > 0)
        {
            throw "Players can't play - maybe someone is cheating. : cannot start the game if players has cards. ";
        }
    }

    void Game::initializeDeck(){
        for (int s = 0; s < SUIT_SIZE; s++) {
            for (int v = 1; v < 13; v++) {
                Card card(s, v);
                deck.push_back(card);
            }
        }

        srand( (time(NULL)));
        // Shuffle the deck
        for (int i = 0; i < DECK_SIZE*DECK_SIZE; i++) {

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
                //  cout << " stack " << p1.stacksize() << endl;
            } else {
                 p2.addCardToHand(deck [(unsigned long)i]);
            }
        }

        // for (auto it = p1.getHand().begin(); it != p1.getHand().end(); ++it) {
        //     Card c = *it;
        //     std::cout << c.toString() << endl;
        // }
    }
}; // namespace ariel
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "game.hpp"
using namespace ariel;

namespace ariel {


    Game::Game(Player& player1, Player& player2) : p1(player1), p2(player2){
        gameInitValidation();
        initializeDeck();
        dealCardsToPlayers();
    }

    void Game::playTurn(){ 
        
        if(isStacksAreEmpty()){
             throw "Players cannot plays, ran out of cards."; 
        }else{

            uniqueCardValidation(p1.getHand().front(), p2.getHand().front());

            Card playerOneCard = p1.drawCard();
            Card playerTwoCard = p2.drawCard();
            currentTurnStash.push_back(playerOneCard);
            currentTurnStash.push_back(playerTwoCard);

            log.push_back(p1.playerName() + " played " + playerOneCard.toString() + " " + p2.playerName() + " played " + playerTwoCard.toString() + ". ");
            if (playerOneCard.getCardVal() > playerTwoCard.getCardVal()){

                p1.addWinningCard(currentTurnStash);
                log.back() += p1.playerName() + " wins. ";

            }else if (playerOneCard.getCardVal() < playerTwoCard.getCardVal()){

                p2.addWinningCard(currentTurnStash);
                log.back() += p2.playerName() + " wins. ";

            }else{

                draws++;
                log.back() += " Draw. ";
                tieBreakerHandler();

            }
         }

    }

    void Game::tieBreakerHandler(){

        if(isStacksAreEmpty()){ splitStash(); return; }

        while(true){

            if(isStacksAreEmpty()){ splitStash(); return; }

            Card faceDownCardP1 = p1.drawCard();
            Card faceDownCardP2 = p2.drawCard();
            currentTurnStash.push_back(faceDownCardP1);
            currentTurnStash.push_back(faceDownCardP2);

            if(isStacksAreEmpty()){ splitStash(); return; }

            Card playerOneCard = p1.drawCard();
            Card playerTwoCard = p2.drawCard();
            currentTurnStash.push_back(playerOneCard);
            currentTurnStash.push_back(playerTwoCard);

            log.back() += p1.playerName() + " played " + playerOneCard.toString() + " " + p2.playerName() + " played " + playerTwoCard.toString() + ". ";

            if (playerOneCard.getCardVal() > playerTwoCard.getCardVal()){

                p1.addWinningCard(currentTurnStash);
                log.back() += p1.playerName() + " wins. ";
                break;

            }else if (playerOneCard.getCardVal() < playerTwoCard.getCardVal()){

                p2.addWinningCard(currentTurnStash);
                log.back() += p2.playerName() + " wins. ";
                break;

            }
            draws++;
            log.back() += " Draw. ";

        }

    }
    bool Game::isStacksAreEmpty(){ return p1.stacksize() == 0 || p2.stacksize() == 0; }
    void Game::uniqueCardValidation(Card& card1, Card& card2){
        if (card1.getCardVal() == card2.getCardVal() && card1.getSuit() == card2.getSuit()){
            throw "Each card is unique - maybe we have one player."; 
        }
    }
    void Game::splitStash(){
        int half_size = currentTurnStash.size() / 2; 
        for (int i = 0; i < half_size; i++) {
            Card c = currentTurnStash.back(); 
            currentTurnStash.pop_back();     
            p1.addWinningCard(c);
        }
        for (int i = 0; i < half_size; i++) {
            Card c = currentTurnStash.back(); 
            currentTurnStash.pop_back();     
            p2.addWinningCard(c);
        }
    }

    void Game::printLastTurn(){ cout << log.back() << endl; }

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

    void Game::printLog(){
        for (auto it = log.begin(); it != log.end(); ++it) {
            string str = *it;
            std::cout << str << endl;
        }
    }

    void Game::printStats(){
        double p1WinRate = 100.0 * p1.getWins() / (p1.getWins() + p2.getWins() + draws);
        double p2WinRate = 100.0 * p2.getWins() / (p1.getWins() + p2.getWins() + draws);
        double drawRate = 100.0 * draws / (p1.getWins() + p2.getWins() + draws);
        cout << "| #-#-#-# " << p1.playerName() << " Stats #-#-#-#" << endl;
        cout << "| Win rate: " << p1WinRate << "%" << endl;
        cout << "| Cards won: " << p1.cardesTaken() << endl;
        cout << endl;
        cout << "| #-#-#-# " << p2.playerName() << " Stats #-#-#-#" << endl;
        cout << "| Win rate: " << p2WinRate << "%" << endl;
        cout << "| Cards won: " << p2.cardesTaken() << endl;
        cout << endl;
        cout << "| Draw rate: " << drawRate << "%" << endl;
    }




    // -#-#- Methods which the constructor is calling -#-#-


    void Game::gameInitValidation(){
        if (p1.stacksize() > 0 || p2.stacksize() > 0
        || p1.cardesTaken() > 0 || p2.cardesTaken() > 0){
            throw "Players can't play - maybe someone is cheating. : cannot start the game if players has cards. ";
        }
    }

    void Game::initializeDeck(){

        for (int s = 0; s < SUIT_SIZE; s++) {
            for (int v = 1; v <= VALUE_SIZE; v++) {
                Card card(s, v);
                deck.push_back(card);
            }
        }

        srand( (time(NULL)));

        // Shuffle the deck
        for (int i = 0; i < DECK_SIZE*DECK_SIZE; i++) {

            uint tmp1 = (uint) (rand() % DECK_SIZE);
            uint tmp2 = (uint) (rand() % DECK_SIZE);

            //Swap - shuffle the deck one by one. 52x52 = 2704 times.
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
using namespace std;
#include <iostream>
#include "Board.h"
#include "Position.h"
#include "CoinPicked.h"
#include "CoinLocation.h"



void Game::Game() {
    switchPlayer;
}



void Game::startGame(){
    cout << "game started" << endl;
    whoIsThePlayer(); 
    makeMove();
}



void Game::canIMove() {
    cout << "checking the next move" << endl;
    CoinPicked coinPickedToMove = stage.pickACoin(whoAmI);
    //move the picked coin
}


void Game::switchPlayer() {
    if (whoAmI == false) { //current black, next white
        whoAmI = true;
    }
    else {
        whoAmI = false;
    }
}

void Game::whoIsThePlayer() {
    if (whoAmI == true) {
        cout << "I am white" << endl;
    }
    else {
        cout << "I am black" << endl;
    }
}
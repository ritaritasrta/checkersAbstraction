using namespace std;
#include <iostream>
#include "CoinLocation.h"

void CoinLocation::setBoardState(char getMark, Coin &myChosenCoin) {
    mark = getMark;
    chosenCoin = myChosenCoin;
}

void CoinLocation::getCoinLocation() {
    cout << "Present mark is " << mark << "[" << chosenCoin.location.row <<  "]" 
    << "[" << chosenCoin.location.column << "]" << endl;
}
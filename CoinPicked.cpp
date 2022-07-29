using namespace std;
#include <iostream>
#include "CoinPicked.h"

void CoinPicked::setConditionsConstructor(CoinLocation &givenMyCoinOnBoard, CoinLocation &givenWhereToMoveCoin, CoinLocation &givenWhereToKill) {
    myCoinOnBoard = givenMyCoinOnBoard;
    whereToMoveCoin = givenWhereToMoveCoin;
    whereToKill = givenWhereToKill;
}

void CoinPicked::setCoinPickedState(CoinLocation &getCoinPicked, CoinLocation &getMoveLocation) {
    myCoinOnBoard = getCoinPicked;
    whereToMoveCoin = getMoveLocation;
}
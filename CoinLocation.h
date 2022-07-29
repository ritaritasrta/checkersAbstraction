#include "Coin.h"


class CoinLocation {
private:
    Coin chosenCoin;
public:
    char mark;
    void setBoardState(char getMark, Coin &myChosenCoin); //constructor
    void getCoinLocation();
};
#include "CoinLocation.h"


class CoinPicked {
public:
    CoinLocation myCoinOnBoard;
    CoinLocation whereToMoveCoin;
    CoinLocation whereToKill;
    void setConditionsConstructor(CoinLocation &givenMyCoinOnBoard, CoinLocation &givenWhereToMoveCoin, CoinLocation &givenWhereToKill);
    void setCoinPickedState(CoinLocation &getCoinPicked, CoinLocation &getMoveLocation);
};
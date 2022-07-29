using namespace std;
#include <iostream>
#include <vector>
#include <cassert>


class Position {
public:
    int row;
    int column;
};

class Coin {
public:
    Position location;
    bool isDead;
    bool isWhiteCoin;
};

class CoinLocation {
private:
    Coin chosenCoin;
public:
    char mark;
    void setBoardState(char getMark, Coin &myChosenCoin); //constructor
    void getCoinLocation();
};


class CoinPicked {
private:
    CoinLocation myCoinOnBoard;
    CoinLocation whereToMoveCoin;
    CoinLocation whereToKill;
public:
    void setConditionsConstructor(CoinLocation &givenMyCoinOnBoard, CoinLocation &givenWhereToMoveCoin, CoinLocation &givenWhereToKill);
    void setCoinPickedState(CoinLocation &getCoinPicked, CoinLocation &getMoveLocation);
};

class Board {
private:
    char emptyLocation = ' ';
    char whiteLocation = 'W';
    char blackLocation = 'B';
    int max_row = 7; //done
    int max_col = 7; //done

public:
    Board(); //done
    CoinLocation coinLocation[8][8]; //done
    Coin white[16]; //done
    Coin black[16]; //done
    void setInitialCoinPositions(bool isWhiteCoinSetup); //done
    void setUpCoinLocations(); //done
    CoinPicked pickACoin(bool isWhiteCoin) {
        if (isWhiteCoin) {
            return pickAWhiteCoin();
        }
        else {
            return pickABlackCoin();
    }
}
    CoinPicked pickAWhiteCoin() {
    CoinPicked m;
    cout << "Searching to pick a white coin to move" << endl;
    for (int r = 0; r <= max_row; r++) {
        for (int c = 0; c<= max_col; c++) {
            cout << "picked [" << r << "][" << c << "]" << endl;
            if ((c == 0 && c < 5) && (coinLocation[r][c].mark == whiteLocation)) {
                if (coinLocation[r+1][c+1].mark == emptyLocation) {
                    cout << "Found the coin" << endl;
                    coinLocation[r][c].getCoinLocation();
                    m.setCoinPickedState(coinLocation[r][c], coinLocation[r+1][c+1]);
                    return m; 
                }
                if ((coinLocation[r+1][c+1].mark == blackLocation) && (coinLocation[r+2][c+1].mark == emptyLocation)) {
                    cout << "Found coin to kill" << endl;
                    coinLocation[r][c].getCoinLocation();
                    m.setConditionsConstructor(coinLocation[r][c], coinLocation[r+2][c+2], coinLocation[r+1][c+1]);
                    return m;
                }
            }
        }
    }
        return m;
    }
    CoinPicked pickABlackCoin() { //FINISH
        CoinPicked m;
        cout << "searching to pick a black coin to move" << endl;
        return m;
    }
};


class Game {
public:
    Game();
    Board stage;
    void switchPlayer(); 
    void startGame();
    bool whoAmI;
    void whoIsThePlayer(); 
    bool move;
    void canIMove(); 
    void makeMove(); 
};

Game::Game() {
    switchPlayer();
}

void Game::startGame() {
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



void Board::setUpCoinLocations() {
    for (int row = 0; row <= max_row; row++) {
        for (int col = 0; col <= max_col; col++) {
            coinLocation[row][col].mark = emptyLocation;
        }
    }
}



void Board::setInitialCoinPositions(bool isWhiteCoinSetup) {
    int r = 0;
    int c = 0;
    if (isWhiteCoinSetup == false) {
        r = max_row;
        cout << "setting up black coins" << endl;
    }
    else {
        cout << "setting up white coins" << endl;
    }



    for (int col = c; col <= max_col; col++) {
        if (isWhiteCoinSetup == true) {
            white[col].location.row = r;
            white[col].location.column = col;
            coinLocation[r][col].setBoardState(whiteLocation, white[col]);

            white[col].location.row = r+1;
            white[col].location.column = col;
            coinLocation[r+1][col].setBoardState(whiteLocation, white[max_col + col]);
        }
        else {
            black[col].location.row = r;
            black[col].location.column = col;
            coinLocation[r][col].setBoardState(blackLocation, white[col]);

            black[col].location.row = r+1;
            black[col].location.column = col;
            coinLocation[r+1][col].setBoardState(blackLocation, white[col + max_col]);
        }
    }
}


Board::Board() {
    cout << "setting up current stage" << endl;
    setUpCoinLocations();
    setInitialCoinPositions(true);
    setInitialCoinPositions(false);
    cout << "stage setup complete" << endl;
}

void CoinLocation::getCoinLocation() {
    cout << "Present mark is " << mark << "[" << chosenCoin.location.row <<  "]" 
    << "[" << chosenCoin.location.column << "]" << endl;
}

void CoinLocation::setBoardState(char getMark, Coin &myChosenCoin) {
    mark = getMark;
    chosenCoin = myChosenCoin;
}


void CoinPicked::setConditionsConstructor(CoinLocation &givenMyCoinOnBoard, CoinLocation &givenWhereToMoveCoin, CoinLocation &givenWhereToKill) {
    myCoinOnBoard = givenMyCoinOnBoard;
    whereToMoveCoin = givenWhereToMoveCoin;
    whereToKill = givenWhereToKill;
}

void CoinPicked::setCoinPickedState(CoinLocation &getCoinPicked, CoinLocation &getMoveLocation) {
    myCoinOnBoard = getCoinPicked;
    whereToMoveCoin = getMoveLocation;
}

int main() {
    Game g;
    g.startGame();

    return 0;
}
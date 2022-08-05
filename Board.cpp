#include "CoinPicked.h"

class Board {
private:
    char emptyLocation = ' ';
    char whiteLocation = 'W';
    char blackLocation = 'B';
    int max_row = 7; 
    int max_col = 7; 

public:
    Board(); 
    CoinLocation coinLocation[8][8]; 
    Coin white[16]; 
    Coin black[16]; 
    void setInitialCoinPositions(bool isWhiteCoinSetup); 
    void setUpCoinLocations(); 
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
                } //do the same w r+1 c-1!!!!!!!
            }
        }
    }
        return m;
    }
    CoinPicked pickABlackCoin() { //FINISH
        CoinPicked m;
        cout << "searching to pick a black coin to move" << endl;
        for (int r = max_row; r >= 0; r--){
            for (int c = max_col; c >= 0; c--) {
                cout << "picked [" << r << "][" << c << "]" << endl;
                if ((c == max_col && c > 5) && (coinLocation[r][c].mark == blackLocation)) {
                    if (coinLocation[r-1][c+1].mark == emptyLocation) {
                        cout << "Found the coin" << endl;
                        coinLocation[r][c].getCoinLocation();
                        m.setCoinPickedState(coinLocation[r][c], coinLocation[r-1][c+1]);
                        return m; 
                }
                if ((coinLocation[r-1][c+1].mark == whiteLocation) && (coinLocation[r-2][c+2].mark == emptyLocation)) { //check same logic for white smth not right
                    cout << "Found coin to kill" << endl;
                    coinLocation[r][c].getCoinLocation();
                    m.setConditionsConstructor(coinLocation[r][c], coinLocation[r-2][c+2], coinLocation[r+1][c+1]);
                    return m;
                } //do the same w r+1 c-1!!!!!!!
            }
        }
        return m;
    }
};

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
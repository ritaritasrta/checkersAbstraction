#include "Board.h"

class Game {
public:
    Game();
    Board stage;
    void switchPlayer(); //DONE
    void startGame();
    bool whoAmI;
    void whoIsThePlayer(); //DONE
    bool move;
    void canIMove(); //done
    void makeMove(); //done
};
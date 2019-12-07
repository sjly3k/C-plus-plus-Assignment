//
// Created by Myeongwon Choi on 27/11/2019.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include "Player.h"
#include "Board.h"

class Game {
private:
    Board gameBoard = Board();
    Player firstPlayer = Player('X'), secondPlayer = Player('O');
    int turn = 1; //1 for the first player, 2 for the second player
    void runTurn(Player player);

public:
    Game();

    char run();
};


#endif //TICTACTOE_GAME_H

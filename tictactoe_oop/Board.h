//
// Created by Myeongwon Choi on 27/11/2019.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#define BOARD_LENGTH 3
#define BOARD_EMPTY 0
#include <string>
#include "Util.h"

class Board {
private:


public:
    char board[BOARD_LENGTH+2][BOARD_LENGTH+2];

    Board();

    bool isFull();
    char getWinner(char player1, char player2);
    void flushBoard();
    void printBoard();
    char placeSymbol(Point, char player);
    bool canBeSet(Point point);
};


#endif //TICTACTOE_BOARD_H

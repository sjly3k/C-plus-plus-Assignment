//
// Created by Myeongwon Choi on 05/12/2019.
//

#ifndef TICTACTOE_COMPUTER_H
#define TICTACTOE_COMPUTER_H

#include "Player.h"

struct Move {

    int row;
    int col;
};

class Computer : public Player {
private:
    bool isMovesLeft(Board board);
    int evaluate(Board board);
    int minimax(Board board, int depth, bool isMax);
    Move findBestMove(Board board);

public:
    explicit Computer(char symbol);
    Point getPointToPlace(Board board);

};


#endif //TICTACTOE_COMPUTER_H

//
// Created by Myeongwon Choi on 05/12/2019.
//

#ifndef TICTACTOE_COMPUTER_H
#define TICTACTOE_COMPUTER_H

#include "Player.h"

class Computer : public Player {
private:
    int minimax(char board[3][3], int depth, bool isMax);
public:
    explicit Computer(char symbol);

};


#endif //TICTACTOE_COMPUTER_H

//
// Created by Myeongwon Choi on 27/11/2019.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include "Util.h"
#include "Board.h"

class Player {
public:
    char symbol;

    Player(char symbol);

    Point getPointToPlace(Board board);
};


#endif //TICTACTOE_PLAYER_H

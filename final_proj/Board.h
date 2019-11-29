//
// Created by Seungjin LEE on 29/11/2019.
//

#ifndef FINAL_PROJ_BOARD_H
#define FINAL_PROJ_BOARD_H

#include <iostream>
#include <iomanip>

using namespace std;
enum state {
    nothing, win, lose, draw
};

enum player {
    human, computer, empty
};

class Board {
private :
    int size;
    bool turn;
    int count;
    char matrix[3][3] = {
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
    };
public:
    Board();
    virtual ~Board();
    void showBoard();
    bool canbeSet(int x, int y);
    state Result(player P);
    void setStone(int x, int y, player P);
    void clearBoard();
};

#endif //FINAL_PROJ_BOARD_H

//
// Created by Myeongwon Choi on 27/11/2019.
//

#include <cmath>
#include "Board.h"
#define BOARD(PAIR) board[(PAIR).first][(PAIR).second]

void Board::printBoard() {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            cout << setw(3) << board[i][j] << setw(3);
            if (j == 0 || j == 1) {
                cout << '|' << setw(3);
            }
        }// '     |     |     ' 와 같은 형식을 출력
        cout << endl;
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (i == 0 || i == 1) {
                cout << setw(3) << "---" << setw(3) << "---" << setw(3);
            }
        }
        cout << endl;
    }
}

Board::Board() {
    for (int i = 0; i < BOARD_LENGTH; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            board[i][j] = BOARD_EMPTY;
        }
    }
}

/*
 * Check player can set the stone on the board
 * if some stone is already set on the board, player can't put on.
 * Parameter x and y is the place where player wants to put his/her stone on the board.
 * Player can put the stone it returns true, else returns false.
 */
bool Board::canBeSet(Point point) {
    // Check the place where player wants to put is empty.
    return BOARD(point) == BOARD_EMPTY &&
           (point.first >= 0 && point.first < BOARD_LENGTH) && (point.second >= 0 && point.second < BOARD_LENGTH);
}

char Board::getWinner(char player1, char player2) {
    int score1, score2;

    for (int i = 0; i < BOARD_LENGTH; ++i) {
        score1 = score2 = 0;
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            if (board[i][j] == player1) score1++;
            if (board[i][j] == player2) score2++;
        }
        if(score1 >= 3 || score2 >= 3) return score1>score2?player1:player2;
    }

    for (int j = 0; j < BOARD_LENGTH; ++j) {
        score1 = score2 = 0;
        for (int i = 0; i < BOARD_LENGTH; ++i) {
            if (board[i][j] == player1) score1++;
            if (board[i][j] == player2) score2++;
        }
        if(score1 >= 3 || score2 >= 3) return score1>score2?player1:player2;
    }

    score1 = score2 = 0;
    for (int i = 0; i < BOARD_LENGTH; ++i) {
        if (board[i][i] == player1) score1++;
        if (board[i][i] == player2) score2++;
    }
    if(score1 >= 3 || score2 >= 3) return score1>score2?player1:player2;

    score1 = score2 = 0;
    for (int i = 0; i < BOARD_LENGTH; ++i) {
        if (board[i][BOARD_LENGTH-i-1] == player1) score1++;
        if (board[i][BOARD_LENGTH-i-1] == player2) score2++;
    }
    if(score1 >= 3 || score2 >= 3) return score1>score2?player1:player2;

    return BOARD_EMPTY;
}

char Board::placeSymbol(Point point, char player) {
    if(!canBeSet(point)) return 0;
    BOARD(point) = player;
    return 0;
}

void Board::flushBoard() {
    for (int i = 0; i < BOARD_LENGTH; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            board[i][j] = BOARD_EMPTY;
        }
    }
}

bool Board::isFull() {
    for (int i = 0; i < BOARD_LENGTH; ++i) {
        for (int j = 0; j < BOARD_LENGTH; ++j) {
            if(board[i][j] == BOARD_EMPTY) return false;
        }
    }
    return true;
}


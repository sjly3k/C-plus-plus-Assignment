//
// Created by Seungjin LEE on 29/11/2019.
//

#ifndef FINAL_PROJ_BOARD_H
#define FINAL_PROJ_BOARD_H

#include <iostream>
#include <iomanip>

using namespace std;
enum state {
    nothing, win, lose, draw;
};

enum player {
    human, computer, empty;
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

    /*
     *  Default Constructor
     */

    Board() {
        size = 3;
        turn = false;
        count = 0;
    }

    /*
     * Show board at the beginning of the player's turn
     */

    void showBoard() {
        for (int i = 0; i<3; i++) cout << endl;

        for (int i = 0; i<3; i++) {
            for (int j= 0; j<3; j++) {
                cout << setw(5) << matrix[i][j] << setw(5);
                if (j == 0 || j == 1) {
                    cout << '|' << setw(5);
                }
            }// '     |     |     ' 와 같은 형식을 출력
            cout << endl;
            for (int j = 0; j<3; j++) {
                if (j == 0 || j == 1) {
                    cout << setw(5) << "-----" << setw(5) << "-----" << setw(5);
                }
            }
            cout << endl;
        }
    }

    /*
     * Check player can set the stone on the board
     * if some stone is already set on the board, player can't put on.
     * Parameter x and y is the place where player wants to put his/her stone on the board.
     * Player can put the stone it returns true, else returns false.
     */

    bool canbeSet(int x, int y) {
        // Check the place where player wants to put is empty.
        if (matrix[x][y] == ' ') {
            if ( (x >= 0 && x < 3) && (y >= 0 && y < 3) )
                return true;
            else
                return false;
        }
            return false;
    }

    /*
     * Think about all the cases that player can win the game.
     * Return cases are 'win', 'lose', 'draw', 'nothing'
     */

    state Result(player P) {

        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' ') {
            // check diagonal from left to right down
            return P != human ? win : lose;
        } else if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[1][1] != ' ') {
            // check diagonal from right to left down
            return P != human ? win : lose;
        } else if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && ' ' != matrix[0][2] ) {
            // First Row
            return P != human ? win : lose;
        }else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[1][1] != ' '){
            // Diagonal Row from right to left
            return P != human ? win : lose;
        }else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && matrix[1][0] != ' '){
            // First Col
            return P != human ? win : lose;
        }else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && matrix[1][2] !=' '){
            // Third Col
            return P != human ? win : lose;
        }else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && matrix[2][1] != ' '){
            // Third Row
            return P != human ? win : lose;
        }else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && matrix[1][1] != ' '){
            // Second Col
            return P != human ? win : lose;
        }else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && matrix[1][1] != ' '){
            // Second Row
            return P != human ? win : lose;
        }else if(count == 9){
            return draw;
        }else{
            return nothing;
        }
    }

    /*
     * If player is human, human will put 'X', if not, will put 'O'
     */

    void setStone(int x, int y, player P) {
        if (P != empty) {
            if (P == human) matrix[x][y] = 'X', count++;
            else matrix[x][y] = 'O', count++;
        }
        // Checking error that empty player is playing the game.
        else
            matrix[x][y] = ' ', count--;
    }

    /*
     * Make the board clear and play the game again.
     */

    void clearBoard() {
        count = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j <3; j++) {
                matrix[i][j] = ' ';
            }
    }
};





#endif //FINAL_PROJ_BOARD_H

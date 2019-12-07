//
// Created by Myeongwon Choi on 05/12/2019.
//
//
#include "Computer.h"
#include "Player.h"

bool Computer::isMovesLeft(Board board)
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board.canBeSet({i, j}))
                return true;
    return false;
}

int Computer::evaluate(Board board)
{
    // Checking Rows for X or O victory
    for (int row = 0; row<3; row++)
    {
        if (board.board[row][0]==board.board[row][1] &&
            board.board[row][1]==board.board[row][2])
        {
            if (board.board[row][0] == 'X'){
                return +10;
            }
            else if (board.board[row][0]=='O')
                return -10;
        }
    }

    // Checking Columns for X or O victory
    for (int col = 0; col<3; col++)
    {
        if (board.board[0][col]==board.board[1][col] &&
            board.board[1][col]==board.board[2][col])
        {
            if (board.board[0][col]=='X'){
                return +10;
            }
            else if (board.board[0][col]=='O')
                return -10;
        }
    }

    // Checking Diagonals for X or O victory
    if (board.board[0][0]==board.board[1][1]
        && board.board[1][1]==board.board[2][2])
    {
        if (board.board[0][0]=='X'){
            return +10;
        }
        else if (board.board[0][0]=='O')
            return -10;
    }

    if (board.board[0][2]==board.board[1][1]
        && board.board[1][1]==board.board[2][0])
    {
        if (board.board[0][2]=='X'){
            return +10;
        }
        else if (board.board[0][2] == 'O')
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

int Computer::minimax(Board board, int depth, bool isMax)
{
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board.board[i][j] == BOARD_EMPTY)
                {
                    // Make the move
                    board.board[i][j] = 'X';

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                                minimax(board, depth+1, !isMax) );

                    // Undo the move
                    board.board[i][j] = BOARD_EMPTY;
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board.canBeSet({i, j}))
                {
                    // Make the move
                    board.board[i][j] = 'X';

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minimax(board, depth+1, !isMax));

                    // Undo the move
                    board.board[i][j] = BOARD_EMPTY;
                }
            }
        }
        return best;
    }
}

Move Computer::findBestMove(Board board)
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evalutae minimax function for all empty cells. And return the cell with optimal value
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if celll is empty
            if (board.board[i][j] == BOARD_EMPTY)
            {
                // Make the move
                board.board[i][j] = 'X';
                // compute evaluation function for this move
                int moveVal = minimax(board, 0, false);
                // Undo the move
                board.board[i][j] = BOARD_EMPTY;
                //update the best
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

Point Computer::getPointToPlace(Board board) {
    Move bestMove = findBestMove(board);

    int r, c;
    r = bestMove.row;
    c = bestMove.col;

    return {r, c};
}

Computer::Computer(char symbol) : Player(symbol) {}
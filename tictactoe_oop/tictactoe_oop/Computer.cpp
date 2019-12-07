//
// Created by Myeongwon Choi on 05/12/2019.
//
//
//#include "Computer.h"
//
//int minimax(Board board, int depth, bool isMax)
//{
//    int score = board.getWinner();
//
//    // If Maximizer has won the game return his/her
//    // evaluated score
//    if (score == 10)
//        return score;
//
//    // If Minimizer has won the game return his/her
//    // evaluated score
//    if (score == -10)
//        return score;
//
//    // If there are no more moves and no winner then
//    // it is a tie
//    if (isMovesLeft(board)==false)
//        return 0;
//
//    // If this maximizer's move
//    if (isMax)
//    {
//        int best = -1000;
//
//        // Traverse all cells
//        for (int i = 0; i<3; i++)
//        {
//            for (int j = 0; j<3; j++)
//            {
//                // Check if cell is empty
//                if (board[i][j]=='_')
//                {
//                    // Make the move
//                    board[i][j] = player;
//
//                    // Call minimax recursively and choose
//                    // the maximum value
//                    best = max( best,
//                                minimax(board, depth+1, !isMax) );
//
//                    // Undo the move
//                    board[i][j] = '_';
//                }
//            }
//        }
//        return best;
//    }
//
//        // If this minimizer's move
//    else
//    {
//        int best = 1000;
//
//        // Traverse all cells
//        for (int i = 0; i<3; i++)
//        {
//            for (int j = 0; j<3; j++)
//            {
//                // Check if cell is empty
//                if (board[i][j]=='_')
//                {
//                    // Make the move
//                    board[i][j] = opponent;
//
//                    // Call minimax recursively and choose
//                    // the minimum value
//                    best = min(best,
//                               minimax(board, depth+1, !isMax));
//
//                    // Undo the move
//                    board[i][j] = '_';
//                }
//            }
//        }
//        return best;
//    }
//}
//
//Point Player::getPointToPlace(Board board) {
//
//}
//
//Computer::Computer(char symbol) : Player(symbol) {}

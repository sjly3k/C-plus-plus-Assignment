//
// Created by Myeongwon Choi on 27/11/2019.
//

#include "Game.h"



void Game::run() {

    cout << "Select menu" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer" << endl;

    int menu;
    cin >> menu;

    char winner = BOARD_EMPTY;
    gameBoard.flushBoard();

    switch (menu) {
        case 1:
            cout << "1. Player vs Player" << endl;
            while (1) {
                gameBoard.printBoard();

                if (turn == 1) {
                    runTurn(firstPlayer);
                    turn = 2;
                } else if (turn == 2) {
                    runTurn(secondPlayer);
                    turn = 1;
                }

                winner = gameBoard.getWinner(firstPlayer.symbol, secondPlayer.symbol);

                if (winner == 'O' || winner == 'X') {
                    if (winner == 'X') {
                        gameBoard.printBoard();
                        cout << "Player 1 win the game !" << endl;
                        break;
                    } else {
                        gameBoard.printBoard();
                        cout << "Player 2 win the game !" << endl;
                        break;
                    }
                } else if (gameBoard.isFull()) {
                    gameBoard.printBoard();
                    cout << "Draw !" << endl;
                    break;
                }
            }
            break;

        case 2:
            cout << "2. Player vs Computer" << endl;
            while (1) {
                gameBoard.printBoard();

                if (turn == 1) {
                    runTurn(firstPlayer);
                    winner = gameBoard.getWinner(firstPlayer.symbol, computer.symbol);
                    if (winner) break;
                    turn = 2;
                } else if (turn == 2) {
                    runTurnC(computer);
                    winner = gameBoard.getWinner(firstPlayer.symbol, computer.symbol);
                    if (winner) break;
                    turn = 1;
                }

                // winner = gameBoard.getWinner(firstPlayer.symbol, computer.symbol);

                if (gameBoard.isFull()) {
                    gameBoard.printBoard();
                    cout << "Draw !" << endl;
                    break;
                }
            }
            if (winner == 'X') {
                gameBoard.printBoard();
                cout << "Player win the game !" << endl;
                break;
            } else {
                gameBoard.printBoard();
                cout << "Computer win the game !" << endl;
                break;
            }
    }
}

void Game::runTurn(Player player) {
    Point point = player.getPointToPlace(gameBoard);
    while (!gameBoard.canBeSet(point)) point = player.getPointToPlace(gameBoard);
    gameBoard.placeSymbol(point, player.symbol);
}
void Game::runTurnC(Computer player) {
    Point point = player.getPointToPlace(gameBoard);
    gameBoard.placeSymbol(point, player.symbol);
}


Game::Game() {};


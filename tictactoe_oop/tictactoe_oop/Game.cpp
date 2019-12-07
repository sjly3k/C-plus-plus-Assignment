//
// Created by Myeongwon Choi on 27/11/2019.
//

#include "Game.h"



char Game::run() {
    char winner = BOARD_EMPTY;
    gameBoard.flushBoard();
    while (!winner || !gameBoard.isFull()) {
        gameBoard.printBoard();

        if (turn == 1) {
            runTurn(firstPlayer);
            turn = 2;
        } else if (turn == 2) {
            runTurn(secondPlayer);
            turn = 1;
        }

        winner = gameBoard.getWinner(firstPlayer.symbol, secondPlayer.symbol);
    }

    return winner;
}

void Game::runTurn(Player player) {
    Point point = player.getPointToPlace(gameBoard);
    while (!gameBoard.canBeSet(point)) point = player.getPointToPlace(gameBoard);
    gameBoard.placeSymbol(point, player.symbol);
}

Game::Game() {}


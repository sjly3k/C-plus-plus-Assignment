//
// Created by Myeongwon Choi on 27/11/2019.
//

#include "Player.h"

Player::Player(char symbol) : symbol(symbol) {}

Point Player::getPointToPlace(Board board) {
    int r, c;
    cout << "Provide the row and col number(0~2):";
    cin >> r >> c;
    return {r, c};

}

//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include "Ship.h"
#include "AttackResult.h"
#include "Cell.h"

class Board {
public:
    static const int SIZE = 10;
private:
    Cell *grid[Board::SIZE][Board::SIZE];

public:
    Board();
    bool addShip(Ship *ship, int x, int y);
    ATTACK_RESULT hitBoard(int x, int y);
    void initializeBoard();
private:
    bool canAddShip(Ship *ship, int x, int y);
};


#endif //BATTLESHIP_BOARD_H

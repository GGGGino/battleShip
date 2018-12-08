//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include "Ship.h"

class Board {
public:
    static const int SIZE = 10;
private:
    Ship *grid[Board::SIZE][Board::SIZE];

public:
    bool addShip(Ship *ship, int x, int y);
private:
    bool canAddShip(Ship *ship, int x, int y);
};


#endif //BATTLESHIP_BOARD_H

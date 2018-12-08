//
// Created by david ginanni on 08/12/2018.
//

#ifndef BATTLESHIP_CELL_H
#define BATTLESHIP_CELL_H

#include "Ship.h"
#include "CellStatus.h"

struct Cell {
    Ship *ship;
    bool isHitted = false;
    CELL_STATUS status = CELL_STATUS::EMPTY;
};

#endif //BATTLESHIP_CELL_H

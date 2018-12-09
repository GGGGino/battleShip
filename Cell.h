//
// Created by david ginanni on 08/12/2018.
//

#ifndef BATTLESHIP_CELL_H
#define BATTLESHIP_CELL_H

#include "Ship.h"
#include "AttackResult.h"

struct Cell {
    Ship *ship;
    bool isHitted = false;
    ATTACK_RESULT status = ATTACK_RESULT ::EMPTY;
};

#endif //BATTLESHIP_CELL_H

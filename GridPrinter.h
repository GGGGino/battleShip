//
// Created by david ginanni on 13/12/2018.
//

#ifndef BATTLESHIP_GRIDPRINTER_H
#define BATTLESHIP_GRIDPRINTER_H

#include <iostream>
#include "Board.h"
#include "Player.h"

class GridPrinter {
public:
    void printGrid(const Board *board);
    void printPlayerGrid(Player *player);
};

#endif //BATTLESHIP_GRIDPRINTER_H

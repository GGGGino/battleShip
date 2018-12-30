//
// Created by david ginanni on 03/12/2018.
//

#include "Board.h"
#include "Ship.h"
#include "Cell.h"
#include "CellStatus.h"
#include "Exception/CellNotEmptyException.h"

Board::Board() {
    initializeBoard();
}

/**
 * Prepare the board with empty Cell
 */
void Board::initializeBoard() {
    for(int i = 0; i<SIZE; i++) {
        for(int k = 0; k<SIZE; k++) {
            Cell *cella = new Cell;
            cella->ship = nullptr;
            grid[i][k] = cella;
        }
    }
}

/**
 * Add the ship to the board doing some check
 *
 * @param ship
 * @param x
 * @param y
 * @return
 */
bool Board::addShip(Ship *ship, int x, int y) {
    if( !canAddShip(ship, x, y) ) {
        return false;
    }

    // controllo che non ci siano altre navi in quella casella
    for(int i = 0; i<ship->getXLength(); i++) {
        for(int k = 0; k<ship->getYLength(); k++) {
            Cell *cella = grid[x+i][y+k];
            cella->ship = ship;
        }
    }

    ship->put();

    return true;
}

/**
 * Where i check if a ship can be added to the board
 *
 * @param ship
 * @param x
 * @param y
 * @return
 */
bool Board::canAddShip(Ship *ship, int x, int y) {
    // controllo che non vada fuori dallo schermo a dx
    if( x + ship->getXLength() > Board::SIZE ) {
        return false;
    }

    // controllo che non vada fuori dallo schermo a sx
    if( y + ship->getYLength() > Board::SIZE ) {
        return false;
    }

    // controllo che non ci siano altre navi in quella casella
    for(int i = 0; i<ship->getXLength(); i++) {
        for(int k = 0; k<ship->getYLength(); k++) {
            Cell *cellaTemp = grid[x+i][y+k];
            if( cellaTemp && cellaTemp->ship ) {
                throw CellNotEmptyException(cellaTemp->ship);
            }
        }
    }

    return true;
}

ATTACK_RESULT Board::tryHit(int x, int y) {
    Cell *cellTemp = grid[x][y];

    if( cellTemp->status != ATTACK_RESULT::EMPTY ) {
        return ATTACK_RESULT::ALREADY_HITTED;
    }

    if( !cellTemp->ship ) {
        cellTemp->status = ATTACK_RESULT::SPLASH;
        return ATTACK_RESULT::SPLASH;
    }

    if( cellTemp->ship ) {
        cellTemp->status = cellTemp->ship->tryHit(x, y);
        return cellTemp->status;
    }

    return ATTACK_RESULT::SPLASH;
}

Cell *Board::getCell(int x, int y) const{
    return grid[x][y];
}
//
// Created by david ginanni on 03/12/2018.
//

#include "Board.h"
#include "Ship.h"
#include "Cell.h"

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
    if( !canAddShip(ship, x, y) ){
        return false;
    }

    // controllo che non ci siano altre navi in quella casella
    for(int i = 0; i<ship->getXLength(); i++) {
        for(int k = 0; k<ship->getYLength(); k++) {
            Cell *cella = grid[x+i][y+k];
            cella->ship = ship;
        }
    }

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
                return false;
            }
        }
    }

    return true;
}

ATTACK_RESULT Board::hitBoard(int x, int y) {
    return ATTACK_RESULT::SPLASH;
}
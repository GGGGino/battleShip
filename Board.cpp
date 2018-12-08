//
// Created by david ginanni on 03/12/2018.
//

#include "Board.h"
#include "Ship.h"

bool Board::addShip(Ship *ship, int x, int y) {
    if( !canAddShip(ship, x, y) ){
        return false;
    }

    // controllo che non ci siano altre navi in quella casella
    for(int i = 0; i<ship->getXLength(); i++) {
        for(int k = 0; k<ship->getYLength(); k++) {
            grid[x+i][y+k] = ship;
        }
    }

    return true;
}

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
            if( grid[x+i][y+k] ) {
                return false;
            }
        }
    }

    return true;
}
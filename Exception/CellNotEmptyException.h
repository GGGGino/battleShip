//
// Created by david ginanni on 29/12/2018.
//

#ifndef BATTLESHIP_CELLNOTEMPTYEXCEPTION_H
#define BATTLESHIP_CELLNOTEMPTYEXCEPTION_H

#include <exception>
#include "../Ship.h"

class CellNotEmptyException: std::exception {
private:
    Ship *shipInPlace;
public:
    CellNotEmptyException(Ship *ship): shipInPlace(ship) {}

    /**
     * Prendo la nave che è già nella cella
     *
     * @return
     */
    Ship *getShip() {
        return shipInPlace;
    }
};

#endif //BATTLESHIP_CELLNOTEMPTYEXCEPTION_H

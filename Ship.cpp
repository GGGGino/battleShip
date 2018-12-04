//
// Created by david ginanni on 03/12/2018.
//

#include "Ship.h"

void Ship::changeOrientation() {
    int tempX = xLength;
    yLength = xLength;
    xLength = tempX;
}

int Ship::getSize() {
    return size;
}

int Ship::getXLength() {
    return xLength;
}

int Ship::getYLength() {
    return yLength;
}
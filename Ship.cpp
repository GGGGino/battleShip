//
// Created by david ginanni on 03/12/2018.
//

#include "Ship.h"

void Ship::changeOrientation() {
    int tempX = xLength;
    yLength = xLength;
    xLength = tempX;
}
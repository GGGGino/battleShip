//
// Created by david ginanni on 03/12/2018.
//

#include "Ship.h"

void Ship::changeOrientation() {
    int tempX = xLength;
    yLength = xLength;
    xLength = tempX;
}

Ship1::Ship1() {
    size = 1;
    xLength = 1;
    yLength = 1;
}

Ship2::Ship2() {
    size = 2;
    xLength = 2;
    yLength = 1;
}

Ship3::Ship3() {
    size = 3;
    xLength = 3;
    yLength = 1;
}

Ship4::Ship4() {
    size = 2;
    xLength = 4;
    yLength = 1;
}
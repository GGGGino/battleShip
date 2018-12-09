//
// Created by david ginanni on 03/12/2018.
//

#include "Ship.h"
#include "AttackResult.h"

/*bool Ship::isSinked() {
    return sinked;
}*/

void Ship::changeOrientation() {
    int tempX = xLength;
    yLength = xLength;
    xLength = tempX;
}

/*ATTACK_RESULT Ship::tryHit(int x, int y) {
    timeHitted++;

    if( timeHitted == size ){
        sinked = true;
        return ATTACK_RESULT::SINK;
    }

    return ATTACK_RESULT::HIT;
}*/
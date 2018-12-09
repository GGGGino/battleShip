//
// Created by david ginanni on 08/12/2018.
//

#ifndef BATTLESHIP_ATTACKRESULT_H
#define BATTLESHIP_ATTACKRESULT_H

enum ATTACK_RESULT {
    ALREADY_HITTED = -1,
    EMPTY = 0,
    SPLASH = 1,
    HIT = 2,
    SINK = 3,
    WIN = 4
};

#endif //BATTLESHIP_ATTACKRESULT_H

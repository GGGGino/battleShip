//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include "AttackResult.h"

class Ship {
protected:
    int size;
    int xLength;
    int yLength;
    bool alreadyPutted = false;
    bool sinked = false;
    int timeHitted;

public:
    bool isSinked() {
        return sinked;
    }
    void positionate(int x, int y);
    void changeOrientation();
    ATTACK_RESULT tryHit(int x, int y) {
        timeHitted++;

        if( timeHitted == size ){
            sinked = true;
            return ATTACK_RESULT::SINK;
        }

        return ATTACK_RESULT::HIT;
    }
    
    inline int getSize() {
        return size;
    }

    inline int getXLength() {
        return xLength;
    }

    inline int getYLength() {
        return yLength;
    }

    inline void put(){
        alreadyPutted = true;
    }

    inline bool isAlreadyPutted(){
        return alreadyPutted;
    }
};

class Ship1: public Ship {
public:
    Ship1() {
        size = 1;
        xLength = 1;
        yLength = 1;
        timeHitted = 0;
    }
};

class Ship2: public Ship {
public:
    Ship2() {
        size = 2;
        xLength = 2;
        yLength = 1;
        timeHitted = 0;
    }
};

class Ship3: public Ship {
public:
    Ship3() {
        size = 3;
        xLength = 3;
        yLength = 1;
        timeHitted = 0;
    }
};

class Ship4: public Ship {
public:
    Ship4() {
        size = 4;
        xLength = 4;
        yLength = 1;
        timeHitted = 0;
    }
};

#endif //BATTLESHIP_SHIP_H

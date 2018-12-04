//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

class Ship {
protected:
    int size;
    int xLength;
    int yLength;

public:
    void positionate(int x, int y);
    void changeOrientation();
    int getSize();
    int getXLength();
    int getYLength();
};

class Ship1: public Ship {
public:
    Ship1() {
        size = 1;
        xLength = 1;
        yLength = 1;
    }
};

class Ship2: public Ship {
public:
    Ship2() {
        size = 2;
        xLength = 2;
        yLength = 1;
    }
};

class Ship3: public Ship {
public:
    Ship3() {
        size = 3;
        xLength = 3;
        yLength = 1;
    }
};

class Ship4: public Ship {
public:
    Ship4() {
        size = 4;
        xLength = 4;
        yLength = 1;
    }
};

#endif //BATTLESHIP_SHIP_H

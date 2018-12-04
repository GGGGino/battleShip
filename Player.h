//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include "Ship.h"
#include <vector>

class Player {
private:
    char *name;
    int punteggio;
    int tempoRimasto;
    std::vector<Ship> ships;

public:
    Player(char *t_name, int t_punteggio);
    ~Player(){}
    Player *setPunteggio(int t_punteggio);
    char *getName();
    int getPunteggio();
    int getTemporimasto();
    void createStartingShips();
};

struct VariabileGrossa {
private:
    unsigned short corto;
    unsigned short corto2;
    unsigned short corto3;
};

struct VariabilePiccola {
private:
    unsigned corto:1;
    unsigned corto2:1;
    unsigned corto3:1;
    unsigned corto4:1;
    unsigned corto5:1;
    unsigned corto6:1;
    unsigned corto7:1;
    unsigned corto8:1;
};

struct VariabilePiccolissima {
private:
    unsigned short int corto:1;
    unsigned short int corto2:1;
    unsigned short int corto3:1;
};


#endif //BATTLESHIP_PLAYER_H

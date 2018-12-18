//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <vector>
#include "Ship.h"
#include "Board.h"
#include "AttackResult.h"

class Player {
private:
    char *name;
    int punteggio;
    int tempoRimasto;
    int nNaviRimaste;
    std::vector<Ship> ships;
    Board board;

public:
    Player(char *t_name, int t_punteggio);
    ~Player(){}
    Player *setPunteggio(int t_punteggio);
    char *getName();
    int getPunteggio();
    int getTemporimasto();
    inline std::vector<Ship> getShips() {
        return ships;
    }
    Board *getBoard();
    void createStartingShips();
    bool putShipOnBoard(int shipLength, int x, int y);
    Ship *getAvailableShipPerLength(int shipLength);

    /**
     * Method that do the attack
     *
     * @param playerAttacked
     * @param x
     * @param y
     * @return
     */
    ATTACK_RESULT attackPlayer(Player *playerAttacked, int x, int y);

    /**
     * Method that suffer the attack
     *
     * @param attackinPlayer
     * @param x
     * @param y
     * @return
     */
    ATTACK_RESULT takeHit(Player *attackinPlayer, int x, int y);

    /**
     * Check if the player has at least one ship alive
     *
     * @return
     */
    bool checkIfHasShipAlive();
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

//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <vector>
#include <string>
#include "Ship.h"
#include "Board.h"
#include "AttackResult.h"

class Player {
private:
    std::string name;
    int punteggio;
    int tempoRimasto;
    int nNaviRimaste;
    std::vector<Ship> ships;
    Board board;

public:
    Player(std::string t_name, int t_punteggio);
    ~Player(){}
    Player *setPunteggio(int t_punteggio);
    std::string getName();
    int getPunteggio();
    int getTemporimasto();
    inline std::vector<Ship> getShips() {
        return ships;
    }
    inline std::vector<Ship*> getAvailableShip() {
        std::vector<Ship*> availableShips;

        // another way to filter but i don't want a copy
        // std::copy_if(ships.begin(), ships.end(), availableShips, [](Ship ship){ return !ship.isAlreadyPutted(); } );

        for(Ship &ship : ships) {
            if( !ship.isAlreadyPutted() ) {
                availableShips.push_back(&ship);
            }
        }

        return availableShips;
    }
    Board *getBoard();
    void createStartingShips();

    /**
     * Here I put the ship of the size "shipLength" in the x,y staring point
     *
     * @param shipLength
     * @param x
     * @param y
     * @return
     */
    bool putShipOnBoard(int shipLength, int x, int y);

    /**
     * Here i get the list of the remaining ship, ready for being positioned in the grid
     *
     * @param shipLength
     * @return
     */
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

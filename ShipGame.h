//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_SHIPGAME_H
#define BATTLESHIP_SHIPGAME_H

#include "Player.h"
#include "Board.h"
#include "GridPrinter.h"
#include <stdio.h>
#include <vector>
#include <string>

class ShipGame {
private:
    std::vector<Player> players;
    GridPrinter gridPrinter;

public:
    /**
     *
     * @param player
     */
    void addPlayer(Player player);
    //ShipGame();
    //~ShipGame();
    std::vector<Player> getPlayers();
    void removePlayer(Player *player);
    void removePlayerAtIndex(int index);
    static Player *createRandomPlayer(std::string name);
    void createRandomPlayers(int nGiocatori);
    void attackNextPlayer();
    void printPlayerGrid(Player *player);
};

#endif //BATTLESHIP_SHIPGAME_H

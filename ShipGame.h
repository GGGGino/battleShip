//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_SHIPGAME_H
#define BATTLESHIP_SHIPGAME_H

#include "Player.h"
#include "Board.h"
#include <stdio.h>
#include <vector>

class ShipGame {
private:
    std::vector<Player> players;

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
    static Player *createRandomPlayer(char *name);
    void createRandomPlayers(int nGiocatori);
};

#endif //BATTLESHIP_SHIPGAME_H

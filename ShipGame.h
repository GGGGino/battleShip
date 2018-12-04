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
    Board board;

public:
    void addPlayer(Player player);
    void removePlayer(Player player);
    void removePlayerAtIndex(int index);
};

#endif //BATTLESHIP_SHIPGAME_H

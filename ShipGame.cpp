//
// Created by david ginanni on 03/12/2018.
//

#include "ShipGame.h"
#include <algorithm>

void ShipGame::addPlayer(Player player) {
    players.push_back(player);
}

void ShipGame::removePlayer(Player *player) {
    // @todo non lo posso fare perche: invalid operands to binary expression ('Player' and 'const Player')
    // if (!(*__i == __value_))
    // players.erase(std::remove(players.begin(), players.end(), player), players.end());
}

void ShipGame::removePlayerAtIndex(int index) {
    players.erase(players.begin() + index);
}

Player *ShipGame::createRandomPlayer(char *name) {
    Player *player = new Player(name, 1000);
    return player;
}
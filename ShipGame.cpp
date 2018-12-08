//
// Created by david ginanni on 03/12/2018.
//

#include "ShipGame.h"
#include <iostream>

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

std::vector<Player> ShipGame::getPlayers() {
    return players;
}

Player *ShipGame::createRandomPlayer(char *name) {
    Player *player = new Player(name, 1000);
    return player;
}

void ShipGame::createRandomPlayers(int nGiocatori) {
    srand(time(NULL));
    for(int i = 0; i < nGiocatori; i++) {
        Player *player = createRandomPlayer("Gino");
        addPlayer(*player);
        int rangeXY = 10 - 0 + 1;
        int rangShip = 4 - 0 + 1;
        int x = rand() % rangeXY + 0;
        int y = rand() % rangeXY + 0;
        int shipLength = rand() % rangShip + 0;
        int random = rand();

        std::cout << "Provo a mettere una barca lunga: " << shipLength << " in x: " << x << " - y: " << y << std::endl;
        player->putShipOnBoard(&board, shipLength, x, y);
    }
}
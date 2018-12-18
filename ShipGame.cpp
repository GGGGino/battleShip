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
    Player *player = nullptr;
    srand(time(0));

    for(int i = 0; i < nGiocatori; i++) {
        player = createRandomPlayer("Gino");
        addPlayer(*player);

        for(int k = 0; k < player->getShips().size() - 4; k++) {
            bool naveInserita = false;
            do{
                naveInserita = false;

                int rangeXY = 10 - 0 + 1;
                int rangShip = 4 - 0 + 1;
                int x = rand() % rangeXY + 0;
                int y = rand() % rangeXY + 0;
                int shipLength = rand() % rangShip + 0;

                // std::cout << i << " prova a mettere una barca lunga: " << shipLength << " in x: " << x << " - y: " << y << std::endl;
                naveInserita = player->putShipOnBoard(shipLength, x, y);
            }while(!naveInserita);
        }
    }
}

void ShipGame::attackNextPlayer() {
    srand(time(NULL));
    for(int i = 1; i < players.size(); i++) {
        for(int k = 1; k < 2; k++) {
            Player *attackingPlayer = &players[i];
            Player *playerAttacked = &(players[i-1]);
            int rangeXY = 10 - 0 + 1;
            int rangShip = 4 - 0 + 1;
            int x = rand() % rangeXY + 0;
            int y = rand() % rangeXY + 0;

            ATTACK_RESULT resultAttack = attackingPlayer->attackPlayer(playerAttacked, x, y);
            // std::cout << "Attacco in x: " << x << " - y: " << y << " con risultato: " << resultAttack << std::endl;
        }
    }
}

void ShipGame::printPlayerGrid(Player *player) {
    gridPrinter.printPlayerGrid(player);
}
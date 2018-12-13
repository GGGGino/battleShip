//
// Created by david ginanni on 03/12/2018.
//

#include <iostream>
#include "Player.h"
#include "Ship.h"
#include "AttackResult.h"

Player::Player(char *t_name, const int t_punteggio) {
    name = t_name;
    punteggio = t_punteggio;
    createStartingShips();
}

Player *Player::setPunteggio(const int t_punteggio) {
    punteggio = t_punteggio;
    return this;
}

char *Player::getName() {
    return name;
}

int Player::getPunteggio() {
    return punteggio;
}

int Player::getTemporimasto() {
    return tempoRimasto;
}

void Player::createStartingShips() {
    for(int i = 0; i < 4; i++) {
        Ship1 tempShip;
        ships.push_back(tempShip);
    }

    for(int i = 0; i < 3; i++) {
        Ship2 tempShip;
        ships.push_back(tempShip);
    }

    for(int i = 0; i < 2; i++) {
        Ship3 tempShip;
        ships.push_back(tempShip);
    }

    for(int i = 0; i < 1; i++) {
        Ship4 tempShip;
        ships.push_back(tempShip);
    }
}

Ship* Player::getAvailableShipPerLength(int shipLength) {
    Ship *ship;

    for(auto i = ships.begin(); i != ships.end(); i++) {
        Ship *shipTemp;
        shipTemp = &*i;
        if( shipTemp->getSize() == shipLength && !shipTemp->isAlreadyPutted() ){
            shipTemp->put();
            ship = shipTemp;
            break;
        }
    }

    return ship;
}

bool Player::putShipOnBoard(int shipLength, int x, int y) {
    Ship *ship = getAvailableShipPerLength(shipLength);
    bool shipInsertedInBoard = false;

    if( ship ){
        shipInsertedInBoard = board.addShip(ship, x, y);
    }

    if( !shipInsertedInBoard ){
        std::cout << "Nave non inserita" << std::endl;
    }
}

bool Player::checkIfHasShipAlive() {
    for(auto i = ships.begin(); i != ships.end(); i++) {
        Ship *shipTemp;
        shipTemp = &*i;

        if( !shipTemp->isSinked() )
            return true;
    }

    return false;
}

ATTACK_RESULT Player::attackPlayer(Player *playerAttacked, int x, int y) {
    ATTACK_RESULT result = playerAttacked->takeHit(this, x, y);
    bool playerHasWin = false;

    if( result == ATTACK_RESULT::SINK )
        playerHasWin = playerAttacked->checkIfHasShipAlive();

    if( playerHasWin )
        result = ATTACK_RESULT::WIN;

    return result;
}

ATTACK_RESULT Player::takeHit(Player *attackinPlayer, int x, int y) {
    ATTACK_RESULT result = board.tryHit(x, y);

    return result;
}

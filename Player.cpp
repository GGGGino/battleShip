//
// Created by david ginanni on 03/12/2018.
//

#include "Player.h"
#include "Ship.h"

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
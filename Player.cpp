//
// Created by david ginanni on 03/12/2018.
//

#include "Player.h"

Player::Player(char *t_name, const int t_punteggio) {
    name = t_name;
    punteggio = t_punteggio;
}

Player Player::setPunteggio(const int t_punteggio) {
    punteggio = t_punteggio;
}

int Player::getPunteggio() {
    return punteggio;
}
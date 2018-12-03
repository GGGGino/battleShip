//
// Created by david ginanni on 03/12/2018.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H


class Player {
private:
    char *name;
    int punteggio;
    int tempoRimasto;

public:
    Player(char *t_name, int t_punteggio);
    Player setPunteggio(int t_punteggio);
    int getPunteggio();
};


#endif //BATTLESHIP_PLAYER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include "ShipGame.h"
#include "Board.h"
#include "Player.h"
#include "Utility.h"

#define PORT 8080

/**
 *
 * @param sockfd
 * @param address
 */
void readFromStream(int *sockfd, sockaddr_in address) {
    char buffer[1024] = {0};
    ssize_t continua;
    char *hello = "Goodbye\n";
    char *exitWord = "exit\n";
    int new_socket, valread;
    int addressLength = sizeof(address);

    do{
        if ((new_socket = accept(*sockfd, (struct sockaddr *)&address, (socklen_t*)&addressLength))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        std::cout << "aperto socket";

        read(new_socket , buffer, 1024);
        printf("buffer: %s", buffer);
    }while( strcmp(buffer, exitWord) != 0);

    printf("ciaooo");
    send(new_socket , hello, strlen(hello), 0);
    close(new_socket);
}

/**
 *
 */
void createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    struct sockaddr_in address;
    std::thread threads[5];

    if( sockfd == 0 ) {
        std::cout << "Socket non funzionante";
    }

    int socketOpt = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    if( socketOpt == 0 ) {
        std::cout << "Non posso settare opzioni per il socket";
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    readFromStream(&sockfd, address);

    /*for(int i = 0; i < 5; i++) {
        threads[i] = std::thread(readFromStream, &sockfd, address);
    }

    for(int i = 0; i < 5; i++) {
        threads[i].join();
    }*/

    printf("Bye bye\n");
}

/**
 *
 */
ShipGame *instantiateShipGame() {
    ShipGame *shipGame = new ShipGame();
    std::string input;
    int nGiocatori = 0;
    std::string playerName;

    std::cout << "Inserisci il numero dei giocatori: ";
    std::cin >> nGiocatori;
    std::cout << "-----------------" << std::endl;

    for (int i = 0; i < nGiocatori; ++i) {
        std::cout << "Inserisci il nome del giocatore: ";
        std::cin >> playerName;
        Player *player = ShipGame::createRandomPlayer(playerName);
        int nShipPutted = 0;

        do{
            myutility::elencoStringhe sizePosizioneShip;
            std::string sizeBarcaEPosizione;
            std::cout << "Inserisci la grandezza della barca e la posizione separate da \"-\"(SizeBarca-X-Y): ";
            std::cin >> sizeBarcaEPosizione;

            sizePosizioneShip = myutility::explode(sizeBarcaEPosizione, '-');
            int sizeShip = std::stoi(sizePosizioneShip.at(0));
            int shipX = std::stoi(sizePosizioneShip.at(1));
            int shipY = std::stoi(sizePosizioneShip.at(2));

            if( !player->putShipOnBoard(sizeShip, shipX, shipY) ) {
                std::cout << "Nave nn inserita" << std::endl;
                continue;
            }

            std::cout << "Nave lunga: " << sizeShip << " in x: " << shipX << " - y: " << shipY << std::endl;
            nShipPutted++;
        }while(nShipPutted < player->getShips().size());

        shipGame->addPlayer(*player);
    }

    shipGame->attackNextPlayer();

    return shipGame;
}

void prindGridForEveryPlayer(ShipGame *shipGame) {
    std::vector<Player> players = shipGame->getPlayers();

    for (int i = 0; i < players.size(); ++i) {
        shipGame->printPlayerGrid(&players[i]);
    }
}

int main(int argc, char const *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    ShipGame *shipGame = instantiateShipGame();

    prindGridForEveryPlayer(shipGame);

    //createSocket();

    return 0;
}
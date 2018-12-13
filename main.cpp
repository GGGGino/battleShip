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

    if ((new_socket = accept(*sockfd, (struct sockaddr *)&address, (socklen_t*)&addressLength))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    do{
        read(new_socket , buffer, 1024);
        printf("buffer: %s", buffer);
    }while( strcmp(buffer, exitWord) != 0);

    printf("ciaooo");
    send(new_socket , hello , strlen(hello) , 0);
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

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 5; i++) {
        threads[i] = std::thread(readFromStream, &sockfd, address);
    }

    for(int i = 0; i < 5; i++) {
        threads[i].join();
    }

    printf("Bye bye\n");
}

/**
 *
 */
ShipGame *instantiateShipGame() {
    ShipGame *shipGame = new ShipGame();
    shipGame->createRandomPlayers(5);

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
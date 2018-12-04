#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include "ShipGame.h"
#include "Player.h"

#define PORT 8080

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

void instantiateShipGame() {
    ShipGame shipGame;
    Player *player1 = ShipGame::createRandomPlayer("Gino");
    Player *player2 = ShipGame::createRandomPlayer("Paolo");
    Player *player3 = ShipGame::createRandomPlayer("Giovanni");
    Player *player4 = ShipGame::createRandomPlayer("Alloh");

    std::cout << sizeof(player1) << std::endl;
    std::cout << sizeof(player2) << std::endl;
    std::cout << sizeof(player3) << std::endl;
    std::cout << sizeof(player4) << std::endl;

    shipGame.addPlayer(*player1);
    shipGame.addPlayer(*player2);
    shipGame.addPlayer(*player3);

    delete player1;
    delete player2;
    delete player3;
    delete player4;
    player4 = NULL;

    std::cout << "---------" << std::endl;
    std::cout << sizeof(player1) << std::endl;
    std::cout << sizeof(player2) << std::endl;
    std::cout << sizeof(player3) << std::endl;
    std::cout << sizeof(player4) << std::endl;
}

int main(int argc, char const *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    instantiateShipGame();

    createSocket();

    return 0;
}
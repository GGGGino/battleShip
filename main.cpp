#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>

#define PORT 8080

void readFromStream(int newSocket) {
    char buffer[1024] = {0};
    ssize_t continua = 1;
    char *hello = "Hello from server\n";

    while((continua = read(newSocket , buffer, 1024)) > 0){
        send(newSocket , hello , strlen(hello) , 0);
        printf("buffer: %s", buffer);
    }
}

void createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int new_socket, valread;
    int sockets[5];
    int opt = 1;
    struct sockaddr_in address;
    int addressLength = sizeof(address);
    std::thread ts[5];

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

    for(int i = 0; i<5; i++) {
        if ((new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addressLength))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        std::thread reader(readFromStream, new_socket);

        reader.join();
    }

    printf("Bye bye\n");
}

int main(int argc, char const *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    createSocket();
    return 0;
}
//
// Created by david ginanni on 13/12/2018.
//

#include "GridPrinter.h"
#include <iostream>

void GridPrinter::printGrid(const Board *board) {
    std::string cancellaRiga = "\r";
    Cell *tempCell = nullptr;

    std::cout << "  | ";
    for(int i=0; i<Board::SIZE; i++) {
        std::cout << "" << i << " | " ;
    }
    std::cout << std::endl;

    for(int i=0; i<Board::SIZE; i++) {
        std::cout << i << " | " ;
        for(int k=0; k<Board::SIZE; k++) {
            tempCell = board->getCell(i, k);
            if( !tempCell->ship ) {
                std::cout << "o" << " | ";
            }else{
                std::cout << tempCell->ship->getSize() << " | ";
            }
        }
        std::cout << std::endl;
        std::cout << "  ";
        for(int k=0; k<Board::SIZE; k++) {
            std::cout << "----";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GridPrinter::printPlayerGrid(Player *player) {
    printGrid(player->getBoard());
}
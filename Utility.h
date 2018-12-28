//
// Created by david ginanni on 28/12/2018.
//

#ifndef BATTLESHIP_UTILITY_H
#define BATTLESHIP_UTILITY_H

#include <string>
#include <vector>
#include <sstream>

namespace myutility {
    typedef std::vector<std::string> elencoStringhe;

    elencoStringhe explode(std::string const &stringa, char delimitator) {
        elencoStringhe result;
        std::istringstream iss(stringa);

        for(std::string token; std::getline(iss, token, delimitator); ) {
            result.push_back(token);
        }

        return result;
    }
}

#endif //BATTLESHIP_UTILITY_H

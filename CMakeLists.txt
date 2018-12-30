cmake_minimum_required(VERSION 3.12)
project(battleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(battleShip main.cpp ShipGame.cpp ShipGame.h Player.cpp Player.h Board.cpp Board.h Ship.h AttackResult.h CellStatus.h Cell.h GridPrinter.cpp GridPrinter.h Utility.h Exception/CellNotEmptyException.h)
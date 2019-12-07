cmake_minimum_required(VERSION 3.9)
project(tictactoe)

set(CMAKE_CXX_STANDARD 11)

add_executable(tictactoe main.cpp Board.cpp Board.h Player.cpp Player.h Util.h Game.cpp Game.h Computer.cpp Computer.h)
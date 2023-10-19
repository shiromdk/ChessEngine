cmake_minimum_required(VERSION 3.26)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChessEngine main.cpp
        src/bitboard.cpp
        src/bitboard.h
        src/squares.h
        src/helper.h
        src/prng.cpp
        src/prng.h
        src/helper.cpp)

//
// Created by c3131 on 18/10/2023.
//


#ifndef CHESSENGINE_BITBOARD_H
#define CHESSENGINE_BITBOARD_H

#include "helper.h"

class Bitboard{
private:
    U64 bitboard;
    U64 pawnAttacks[2][64]{};
    U64 knightAttacks[64]{};
    U64 kingAttacks[64]{};
public:
    explicit Bitboard(U64 bitboard);
    U64 maskPawnAttacks(int square,int side);
    U64 maskKingAttacks(int square);
    U64 maskBishopAttacks(int square);
    U64 maskRookAttacks(int square);
    U64 maskKnightAttacks(int square);

    static U64 setOccupancy(int index, int bitsInMask, U64 attackMask);

    U64 generateBishopAttacksOnTheFly(int square, U64 block);
    U64 generateRookAttacksOnTheFly(int square, U64 block);
    void printBitboard() const;

    int getBit(int square) const;
    void setBit(int square);
    void popBit(int square);
    void initLeaperAttacks();
    U64 returnBitboard();

    static int countBits(U64 board);
    static int getLS1BIndex(U64 board);
    static void printBitboard(U64 bb) ;
};



#endif //CHESSENGINE_BITBOARD_H

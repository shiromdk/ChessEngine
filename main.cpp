#include <iostream>
#include "src/bitboard.h"
#include "src/squares.h"
#include "src/helper.h"
#include "src/prng.h"


using namespace std;

int main(){
    U64 bitboard = 0LL;

    auto * bitboard1 = new Bitboard(bitboard);

    auto * rng = new PRNG();

    Bitboard::printBitboard((U64)rng->getRandomUInt32());
    Bitboard::printBitboard((U64)rng->getRandomUInt32() & 0xFFFF);
    Bitboard::printBitboard(rng->getRandomUInt64());
    Bitboard::printBitboard(rng->generateMagicNumber());
    return 0;
}
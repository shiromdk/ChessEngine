#include <iostream>
#include "bitboard.h"
#include "squares.h"
#define U64 unsigned long long

using namespace std;

int main(){
    U64 bitboard = 0LL;
    auto * bitboard1 = new Bitboard(bitboard);
    auto * bitboard2 = new Bitboard(bitboard);
    bitboard2->setBit(D7);
    bitboard2->setBit(D3);
    bitboard2->setBit(B4);
    bitboard2->setBit(G4);
    bitboard2->printBitboard();

    bitboard1->printBitboard(bitboard1->generateRookAttacksOnTheFly(D4, bitboard2->returnBitboard()));

//    for(int i = 1; i <= 64; i++){
//        bitboard1->printBitboard(bitboard1->maskBishopAttacks(i));
//    }

    return 0;
}
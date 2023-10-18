#include <iostream>
#include "bitboard.h"
#include "squares.h"
#define U64 unsigned long long

using namespace std;

int main(){
    U64 bitboard = 0LL;
    auto * bitboard1 = new Bitboard(bitboard);
    for(int i = 1; i <= 64; i++){
        bitboard1->printBitboard(bitboard1->maskKnightAttacks(i));
    }

    return 0;
}
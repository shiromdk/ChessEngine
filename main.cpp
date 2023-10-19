#include <iostream>
#include "bitboard.h"
#include "squares.h"
#include "Helper.h"

#define U64 unsigned long long

using namespace std;

int main(){
    U64 bitboard = 0LL;
    auto * bitboard1 = new Bitboard(bitboard);

    for(int rank = 0; rank < 8; rank++){
        for(int file = 0; file < 8; file++){
            int square = rank * 8 + file;
            cout << Bitboard::countBits(bitboard1->maskRookAttacks(square)) << ",";
        }
        cout << endl;
    }

    return 0;
}
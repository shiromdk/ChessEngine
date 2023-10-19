//
// Created by c3131 on 18/10/2023.
//
#include <iostream>
#include "bitboard.h"
#include "squares.h"

#define get_bit(bitboard,square)(bitboard & (1ULL<< square)
#define set_bit(bitboard,square)(bitboard |= (1ULL<< square))
#define pop_bit(bitboard,square)(get_bit(bitboard,square)? bitboard ^= (1ULL << square): 0)

const U64 notAFile = 18374403900871474942ULL;
const U64 notABFile = 18229723555195321596ULL;
const U64 notHFile = 9187201950435737471ULL;
const U64 notHGFile = 4557430888798830399ULL;

using namespace std;
//Enum board squares




void Bitboard::printBitboard() const{
    for(int rank = 0; rank < 8; rank++){
        for(int file = 0; file< 8; file++) {
            int square = rank * 8 + file;
            int exp = get_bit(this->bitboard, square) ? 1 : 0);
            if(!file){
                cout << " " << 8 - rank;
            }
            cout << " " << exp;
        }
        cout << endl;

    }
    cout << "   A B C D E F G H";

    cout << endl <<"Bitboard : " << bitboard <<endl;
}
void Bitboard::printBitboard(U64 bb) const{
    for(int rank = 0; rank < 8; rank++){
        for(int file = 0; file< 8; file++) {
            int square = rank * 8 + file;
            int exp = get_bit(bb, square) ? 1 : 0);
            if(!file){
                cout << " " << 8 - rank;
            }
            cout << " " << exp;
        }
        cout << endl;

    }
    cout << "   A B C D E F G H";

    cout << endl <<"Bitboard : " << bb <<endl;
}

int Bitboard::getBit(int square) const {
    return get_bit(this->bitboard, square));
}
void Bitboard::setBit(int square) {
    set_bit(this->bitboard, square);
}
Bitboard::Bitboard(unsigned long long int bitboard) {
    this->bitboard = bitboard;


    this->initLeaperAttacks();
}

void Bitboard::popBit(int square) {
    pop_bit(this->bitboard, square));
}

// Attacks

U64 Bitboard::maskPawnAttacks(int square, int side) {
    U64 attacks = 0ULL;
    U64 pieceBitboard = 0ULL;
    set_bit(pieceBitboard, square);
    if(!side){
        if((pieceBitboard >> 7) & notAFile){
            attacks |= (pieceBitboard >> 7);
        }
        if((pieceBitboard >> 9) & notHFile){
            attacks |= (pieceBitboard >> 9);
        }
    }else{
        if((pieceBitboard << 7) & notHFile){
            attacks |= (pieceBitboard << 7);
        }
        if((pieceBitboard << 9) & notAFile){
            attacks |= (pieceBitboard << 9);
        }
    }

    return attacks;
}

U64 Bitboard::maskKingAttacks(int square) {
    U64 attacks = 0ULL;
    U64 pieceBitboard = 0ULL;
    set_bit(pieceBitboard, square);
    if(pieceBitboard >> 8) {
        attacks |= (pieceBitboard >> 8);
    }
    if((pieceBitboard >> 9 )& notHFile) {
        attacks |= (pieceBitboard >> 9);
    }
    if((pieceBitboard >> 7 )& notAFile) {
        attacks |= (pieceBitboard >> 7);
    }
    if((pieceBitboard >> 1 )& notHFile) {
        attacks |= (pieceBitboard >> 1);
    }

    if(pieceBitboard << 8) {
        attacks |= (pieceBitboard << 8);
    }
    if((pieceBitboard << 9 )& notAFile) {
        attacks |= (pieceBitboard << 9);
    }
    if((pieceBitboard << 7 )& notHFile) {
        attacks |= (pieceBitboard << 7);
    }
    if((pieceBitboard << 1 )& notAFile) {
        attacks |= (pieceBitboard << 1);
    }

    return attacks;
}


U64 Bitboard::maskKnightAttacks(int square) {
    U64 attacks = 0ULL;
    U64 pieceBitboard = 0ULL;
    set_bit(pieceBitboard, square);

    if((pieceBitboard >> 17) & notHFile) {
        attacks |= (pieceBitboard >> 17);
    }
    if((pieceBitboard >> 15) & notAFile) {
        attacks |= (pieceBitboard >> 15);
    }
    if((pieceBitboard >> 10) & notHGFile) {
        attacks |= (pieceBitboard >> 10);
    }
    if((pieceBitboard >> 6) & notABFile) {
        attacks |= (pieceBitboard >> 6);
    }

    if((pieceBitboard << 17) & notAFile) {
        attacks |= (pieceBitboard << 17);
    }
    if((pieceBitboard << 15) & notHFile) {
        attacks |= (pieceBitboard << 15);
    }
    if((pieceBitboard << 10) & notABFile) {
        attacks |= (pieceBitboard << 10);
    }
    if((pieceBitboard << 6) & notHGFile) {
        attacks |= (pieceBitboard << 6);
    }
    // generate knight attacks 17 15, 10 ,6

    return attacks;
}


void Bitboard::initLeaperAttacks() {
    // Loop over 64 board square
    for(int square = 0; square < 64; square++){
        // Init pawn attacks
        this->pawnAttacks[white][square] = maskPawnAttacks(square,white);
        this->pawnAttacks[black][square] = maskPawnAttacks(square, black);
        this->kingAttacks[square] = maskKingAttacks(square);
        this->knightAttacks[square] = maskKnightAttacks(square);
    }

}

U64 Bitboard::maskBishopAttacks(int square) {
    U64 attacks = 0ULL;
    // init rank and files
    int rank, file;
    // init target rank and files
    int targetRank = square / 8;
    int targetFile = square % 8;

    // mask relevant bishop occupancy bits
    for(rank = targetRank + 1, file = targetFile + 1; rank<= 6 && file <=6; rank++, file++){
        attacks |= (1ULL << (rank*8+file));
    }
    for(rank = targetRank - 1, file = targetFile + 1; rank>= 1 && file <=6; rank--, file++){
        attacks |= (1ULL << (rank*8+file));
    }

    for(rank = targetRank + 1, file = targetFile - 1; rank<= 6 && file >= 1; rank++, file--){
        attacks |= (1ULL << (rank*8+file));
    }

    for(rank = targetRank -1, file = targetFile - 1; rank>= 1 && file >= 1; rank--, file--){
        attacks |= (1ULL << (rank*8+file));
    }
    return attacks;
}

U64 Bitboard::maskRookAttacks(int square) {
    U64 attacks = 0ULL;
    // init rank and files
    int rank, file;
    // init target rank and files
    int targetRank = square / 8;
    int targetFile = square % 8;
    // mask relevant rook occupancy bits
    for(rank = targetRank + 1; rank<= 6; rank++){
        attacks |= (1ULL << (rank*8+targetFile));
    }
    for(rank = targetRank -1; rank>= 1; rank--){
        attacks |= (1ULL << (rank*8+targetFile));
    }
    for(file = targetFile + 1; file <= 6; file++){
        attacks |= (1ULL << (targetRank*8+file));
    }
    for(file = targetFile - 1; file >= 1; file--){
        attacks |= (1ULL << (targetRank*8+file));
    }
    return attacks;
}

U64 Bitboard::generateBishopAttacksOnTheFly(int square, U64 block) {
    U64 attacks = 0ULL;
    // init rank and files
    int rank, file;
    // init target rank and files
    int targetRank = square / 8;
    int targetFile = square % 8;

    // generate bishop attacks
    for(rank = targetRank + 1, file = targetFile + 1; rank<= 7 && file <=7; rank++, file++){
        attacks |= (1ULL << (rank*8+file));
        if( (1ULL << (rank*8+file) & block)){
            break;
        }
    }
    for(rank = targetRank - 1, file = targetFile + 1; rank>= 0 && file <=7; rank--, file++){
        attacks |= (1ULL << (rank*8+file));
        if( (1ULL << (rank*8+file) & block)){
            break;
        }
    }

    for(rank = targetRank + 1, file = targetFile - 1; rank<= 7 && file >= 0; rank++, file--){
        attacks |= (1ULL << (rank*8+file));
        if( (1ULL << (rank*8+file) & block)){
            break;
        }
    }

    for(rank = targetRank -1, file = targetFile - 1; rank>= 0 && file >= 0; rank--, file--){
        attacks |= (1ULL << (rank*8+file));
        if( (1ULL << (rank*8+file) & block)){
            break;
        }
    }
    return attacks;
}

U64 Bitboard::returnBitboard() {
    return this->bitboard;
}

U64 Bitboard::generateRookAttacksOnTheFly(int square, U64 block) {
    U64 attacks = 0ULL;
    // init rank and files
    int rank, file;
    // init target rank and files
    int targetRank = square / 8;
    int targetFile = square % 8;
    // mask relevant rook occupancy bits
    for(rank = targetRank + 1; rank<= 7; rank++){
        attacks |= (1ULL << (rank*8+targetFile));
        if( (1ULL << (rank*8+targetFile) & block)){
            break;
        }
    }
    for(rank = targetRank -1; rank>= 0; rank--){
        attacks |= (1ULL << (rank*8+targetFile));
        if( (1ULL << (rank*8+targetFile) & block)){
            break;
        }
    }
    for(file = targetFile + 1; file <= 7; file++){
        attacks |= (1ULL << (targetRank*8+file));
        if((1ULL << (targetRank*8+file) & block)){
            break;
        }
    }
    for(file = targetFile - 1; file >= 0; file--){
        attacks |= (1ULL << (targetRank*8+file));
        if( (1ULL << (targetRank*8+file) & block)){
            break;
        }
    }
    return attacks;
}





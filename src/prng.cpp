//
// Created by c3131 on 20/10/2023.
//

#include "prng.h"
#include "helper.h"


PRNG::PRNG() {
    this->state = 1804289383;
}
unsigned int PRNG::getRandomUInt32() {
    // Get current state
    unsigned int number = state;
    // XOR Shift
    number ^= number << 13;
    number ^= number >> 17;
    number ^= number << 5;
    state = number;
    return state;
}

unsigned int PRNG::getRandomUInt64() {
    U64 n1,n2,n3,n4;
    // init random numbers slicing 16 bits from ms1b side
    n1 = (U64)(getRandomUInt32() & 0xFFFF);
    n2 = (U64)(getRandomUInt32() & 0xFFFF);
    n3 = (U64)(getRandomUInt32() & 0xFFFF);
    n4 = (U64)(getRandomUInt32() & 0xFFFF);

    return  n1 | (n2 << 16) | (n3 << 32)| (n4 << 48);
}

U64 PRNG::generateMagicNumber() {
    return getRandomUInt64() & getRandomUInt64() & getRandomUInt64()  ;
}



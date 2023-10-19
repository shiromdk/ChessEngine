//
// Created by c3131 on 20/10/2023.
//

#ifndef CHESSENGINE_PRNG_H
#define CHESSENGINE_PRNG_H


#include "helper.h"

class PRNG {
private:
    unsigned int state;
public:
    PRNG();
    unsigned int getRandomUInt32();
    unsigned int getRandomUInt64();
    U64 generateMagicNumber();
};


#endif //CHESSENGINE_PRNG_H

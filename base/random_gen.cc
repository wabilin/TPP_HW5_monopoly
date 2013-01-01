// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "base/random_gen.h"


#ifndef __MINGW32__
#include <random>
RandomGen::RandomGen(int min, int max)
  : gen_(std::random_device()()),
    distribution_(std::uniform_int_distribution<int> (min, max))
    {}


int RandomGen::operator()() {
    return distribution_(gen_);
}

#else
#include <cstdlib>
#include <ctime>

RandomGen::RandomGen(int min, int max)
  : kRange_(max-min+1), kMin_(min) {
    srand(time(NULL));
}


int RandomGen::operator()() {
    return rand()%kRange_ + kMin_;
}

#endif

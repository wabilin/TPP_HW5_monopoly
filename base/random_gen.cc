// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "base/random_gen.h"
#include <random>

RandomGen::RandomGen(int min, int max)
  : gen_(std::random_device()()),
    distribution_(std::uniform_int_distribution<int> (min, max))
    {}

RandomGen::~RandomGen() {}

int RandomGen::operator()() {
    return distribution_(gen_);
}

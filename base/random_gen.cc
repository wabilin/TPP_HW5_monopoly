#include "base/random_gen.h"
#include <random>

RandomGen::RandomGen(int min, int max) {
    std::random_device rd;
    gen_ = new std::mt19937(rd());
    distribution_ = new std::uniform_int_distribution<int> (min, max);
}

RandomGen::~RandomGen() {
    delete gen_;
    delete distribution_;
}

int RandomGen::operator()() {
    return (*distribution_)(*gen_);
}

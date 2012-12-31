#ifndef BASE_RANDOM_GEN_H_
#define BASE_RANDOM_GEN_H_

#include <random>

class RandomGen {
 public:
    // init with random range
    explicit RandomGen(int min, int max);
    ~RandomGen();

    // return a random number
    int operator()();

 private:
    std::mt19937* gen_;
    std::uniform_int_distribution<int>* distribution_;
};

#endif  // BASE_RANDOM_GEN_H_

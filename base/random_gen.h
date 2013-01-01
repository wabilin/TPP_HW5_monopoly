// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef BASE_RANDOM_GEN_H_
#define BASE_RANDOM_GEN_H_

// MinGW 4.6 do not support <random> as GCC do
#ifndef __MINGW32__
  #include <random>
#endif

class RandomGen {
 public:
    // init with random range
    explicit RandomGen(int min, int max);

    // return a random number
    int operator()();

 private:
#ifndef __MINGW32__
    std::mt19937 gen_;
    std::uniform_int_distribution<int> distribution_;
#else
    const int kRange_;
    const int kMin_;
#endif
};

#endif  // BASE_RANDOM_GEN_H_

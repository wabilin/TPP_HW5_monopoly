#ifndef UNIT_RANDOM_COST_UNIT_H_
#define UNIT_RANDOM_COST_UNIT_H_

#include "pay_unit.h"
#include "base/random_gen.h"

class RandomCostUnit : public PayUnit {
 public:
    // override MapUnit
    void TravelEven(Player* traveler);
    void PrintInfo() const;

    // override PayUnit
    int  fine() const;
    void Release();

 protected:
    int base_fine_;
    static const int kDiceSurface = 6;
    static RandomGen s_dice_;

    static int Dice();
};

#endif  // RANDOM_COST_UNIT_H_INCLUDED

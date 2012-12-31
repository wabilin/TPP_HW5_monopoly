// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#ifndef UNITS_RANDOM_COST_UNIT_H_
#define UNITS_RANDOM_COST_UNIT_H_

#include <string>
#include "units/pay_unit.h"
#include "base/random_gen.h"

class RandomCostUnit : public PayUnit {
 public:
    explicit RandomCostUnit
    (int id, const std::string& name, int players_num, int cost, int base_fine);

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

#endif  // UNITS_RANDOM_COST_UNIT_H_

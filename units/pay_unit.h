// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_PAY_UNIT_H_
#define UNITS_PAY_UNIT_H_
#include <string>
#include "./map_unit.h"

class PayUnit : public MapUnit {
 public:
    PayUnit(const std::string& name, int cost)
      :MapUnit(name), cost_(cost) {}

    virtual int fine()const = 0;
    int cost()const { return cost_; }

    void AskBuy(Player&);
    void AskPay(Player&);

 protected:
    int cost_;
};

#endif  // UNITS_PAY_UNIT_H_

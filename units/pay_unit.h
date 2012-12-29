// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_PAY_UNIT_H_
#define UNITS_PAY_UNIT_H_
#include <string>
#include "units/map_unit.h"

// A virtual class for cost units

class PayUnit : public MapUnit {
 public:
    PayUnit(const std::string& name, int cost)
      :MapUnit(name), cost_(cost), owner_(nullptr) {}

    virtual int fine()const = 0;
    int cost()const { return cost_; }

    const std::string& owner_name()const;
    int owner_id()const;

    // used in StopAct() by children
    void AskBuy(Player*);
    void AskPay(Player*) const;

 protected:
    int cost_;
    Player* owner_;

};

#endif  // UNITS_PAY_UNIT_H_

// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_PAY_UNIT_H_
#define UNITS_PAY_UNIT_H_
#include <string>
#include "units/map_unit.h"

// A virtual class for units can be bought

class PayUnit : public MapUnit {
 public:
    PayUnit(const std::string& name, int player_num, int cost);

    virtual int fine() const = 0;
    int cost()const { return cost_; }

    const std::string& owner_name()const;
    int owner_id()const;

    bool CanBuyBy(const Player* traveler) const;
    virtual void Release() = 0;

    // used in TravelEven() by children
    void AskBuy(Player* traveler);
    void AskPay(Player* traveler) const;

 protected:
    int cost_;
    Player* owner_;
};

#endif  // UNITS_PAY_UNIT_H_

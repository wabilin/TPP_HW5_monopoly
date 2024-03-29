// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#ifndef UNITS_PAY_UNIT_H_
#define UNITS_PAY_UNIT_H_

#include <string>
#include "units/map_unit.h"

// A virtual class for units can be bought
class PayUnit : public MapUnit {
 public:
    explicit PayUnit
    (int id, const std::string& name, int players_num, int cost);

    virtual int fine() const = 0;
    int cost()const { return cost_; }

    const std::string& owner_name()const;
    int owner_id()const;

    bool Abandoned() const { return owner_ == nullptr; }
    bool CanBuyBy(const Player* traveler) const;
    bool NeedFine(const Player* traveler) const;

    // unit should be release if its owner have been out
    virtual void Release() = 0;

 protected:
    const int cost_;
    Player* owner_;

    // used in TravelEven() by children
    void AskBuy(Player* traveler);
    void AskPay(Player* traveler) const;
};

#endif  // UNITS_PAY_UNIT_H_

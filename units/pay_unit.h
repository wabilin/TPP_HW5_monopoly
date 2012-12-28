#ifndef PAY_UNIT_H_INCLUDED
#define PAY_UNIT_H_INCLUDED

#include "map_unit.h"

class PayUnit : public MapUnit{
public:
    PayUnit(const std::string& name, int cost)
      :MapUnit(name), cost_(cost){}

    virtual int fine() = 0;
    int cost(){ return cost_; }

    void AskBuy(Player&);
    void AskPay(Player&);

protected:
    int cost_;
};

#endif // PAY_UNIT_H_INCLUDED

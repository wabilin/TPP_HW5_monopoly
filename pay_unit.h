#ifndef PAY_UNIT_H_INCLUDED
#define PAY_UNIT_H_INCLUDED

#include "map_unit.h"

class PayUnit : public MapUnit{
public:
    virtual int stop_cost() = 0;
    virtual int buy_cost() = 0;
protected:
    int _cost_;
};

#endif // PAY_UNIT_H_INCLUDED

#ifndef RANDOM_COST_UNIT_H_INCLUDED
#define RANDOM_COST_UNIT_H_INCLUDED

#include "pay_unit.h"

class RandomCostUnit : public PayUnit {
public:
    int fine();
protected:
    int _base_fine_;
};

#endif // RANDOM_COST_UNIT_H_INCLUDED

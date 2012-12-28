#ifndef UNIT_RANDOM_COST_UNIT_H_
#define UNIT_RANDOM_COST_UNIT_H_

#include "pay_unit.h"

class randomCostUnit : public PayUnit {
 public:
    int fine();
 protected:
    int base_fine_;
};

#endif  // RANDOM_COST_UNIT_H_INCLUDED

#ifndef UPGRADABLE_UNIT_H_INCLUDED
#define UPGRADABLE_UNIT_H_INCLUDED

#include <vector>
#include "map_unit.h"

class UpgradableUnit : public MapUnit{
public:
    explicit UpgradableUnit
    (int buy_cost, int upgrade_cost, std::vector<int> passing_costs);

    ~UpgradableUnit();

protected:
    int _level_;
    int _buy_cost_;
    int _upgrade_cost_;
    std::vector<int> _passing_costs_;
};

#endif // UPGRADABLE_UNIT_H_INCLUDED

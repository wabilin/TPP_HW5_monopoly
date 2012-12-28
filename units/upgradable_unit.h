#ifndef UPGRADABLE_UNIT_H_INCLUDED
#define UPGRADABLE_UNIT_H_INCLUDED

#include <vector>
#include "pay_unit.h"

class UpgradableUnit : public PayUnit{
public:
    explicit UpgradableUnit
    (const std::string& name, int cost,
     int upgrade_cost, const std::vector<int>& fines);
    ~UpgradableUnit(){}

    int fine(){ return fines_[level_]; }

    bool CanUpgradeBy(const Player&);

protected:
    int upgrade_cost_;
    int level_;
    std::vector<int> fines_;
};

#endif // UPGRADABLE_UNIT_H_INCLUDED

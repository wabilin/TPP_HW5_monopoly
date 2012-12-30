#ifndef UPGRADABLE_UNIT_H_INCLUDED
#define UPGRADABLE_UNIT_H_INCLUDED

#include <vector>
#include "pay_unit.h"

class UpgradableUnit : public PayUnit{
public:
    explicit UpgradableUnit
    (const std::string& name, int player_num, int cost,
     int upgrade_cost, const std::vector<int>& fines);
    ~UpgradableUnit(){}

    int fine()const { return fines_[level_]; }
    int upgrade_cost()const { return upgrade_cost_; }
    int level() const { return level_;  }
    int highest_level()const { return fines_.size() - 1; }

    bool CanUpgradeBy(const Player* traveler) const;
    void AskUpgrade();

    // make owner pay and level up
    void Upgrade();

    // override MapUnit
    void TravelEven(Player* traveler);

protected:
    int upgrade_cost_;
    int level_;
    std::vector<int> fines_;
};

#endif // UPGRADABLE_UNIT_H_INCLUDED

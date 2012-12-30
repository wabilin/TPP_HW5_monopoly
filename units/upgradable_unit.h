// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#ifndef UNITS_UPGRADABLE_UNIT_H_
#define UNITS_UPGRADABLE_UNIT_H_

#include <vector>
#include <string>
#include "units/pay_unit.h"

class UpgradableUnit : public PayUnit {
 public:
    explicit UpgradableUnit
    (int id, const std::string& name, int player_num, int cost,
     int upgrade_cost, const std::vector<int>& fines);
    ~UpgradableUnit() {}

    int fine()const { return fines_[level_]; }
    int upgrade_cost()const { return upgrade_cost_; }
    int level() const { return level_;  }
    int highest_level()const { return fines_.size() - 1; }

    bool CanUpgradeBy(const Player* traveler) const;

    // override MapUnit
    void TravelEven(Player* traveler);
    void PrintInfo() const;

 protected:
    int upgrade_cost_;
    int level_;
    std::vector<int> fines_;

    // ask owner to upgrade or not, if Yes, call Upgrade()
    void AskUpgrade();

    // make owner pay and level up
    void Upgrade();
};

#endif  // UNITS_UPGRADABLE_UNIT_H_

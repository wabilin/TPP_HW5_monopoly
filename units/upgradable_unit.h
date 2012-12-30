// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan

#ifndef UNITS_UPGRADABLE_UNIT_H_
#define UNITS_UPGRADABLE_UNIT_H_

#include <array>
#include <string>
#include "units/pay_unit.h"

class UpgradableUnit : public PayUnit {
 public:
    static const int kLevelNum = 5;

    explicit UpgradableUnit
    (int id, const std::string& name, int player_num, int cost,
     int upgrade_cost, const std::array<int, kLevelNum>& fines);
    ~UpgradableUnit() {}


    int upgrade_cost()const { return upgrade_cost_; }
    int level() const { return level_;  }
    static int highest_level() { return kLevelNum - 1; }

    bool CanUpgradeBy(const Player* traveler) const;

    // override MapUnit
    void TravelEven(Player* traveler);
    void PrintInfo() const;

    // override PayUnit
    int  fine()const { return fines_[level_]; }
    void Release();

 protected:
    const int upgrade_cost_;
    int level_;
    const std::array<int, kLevelNum> fines_;

    // ask owner to upgrade or not, if Yes, call Upgrade()
    void AskUpgrade();

    // make owner pay and level up
    void Upgrade();
};

#endif  // UNITS_UPGRADABLE_UNIT_H_

// Copyright 2012 N.S.Lin @ CSEI.NTNU@Taiwan
#include "units/upgradable_unit.h"
#include <array>
#include <string>
#include "player/player.h"
#include "base/controll.h"
using std::string;
using std::array;

UpgradableUnit::UpgradableUnit
(int id, const string& name, int players_num,  int cost,
  int upgrade_cost, const array<int, kLevelNum>& fines)
    :PayUnit(id, name, players_num, cost), upgrade_cost_(upgrade_cost),
     level_(0), fines_(fines) {}

bool UpgradableUnit::CanUpgradeBy(const Player* traveler) const {
    return (traveler == owner_)
        && (owner_->money() > upgrade_cost())
        && level() < highest_level();
}

void UpgradableUnit::AskUpgrade() {
    printf("%s, do you want to upgrade %s? (1: Yes [default] / 2: No) ...>",
           owner_name().c_str(), name().c_str());

    if (GetYesOrNo()) {
        Upgrade();
    }
}

void UpgradableUnit::Upgrade() {
    if (level() >= highest_level()) {
        perror("Error at UpgradableUnit::Upgrade(): over highest level.\n");
    }
    if (owner_->money() <= upgrade_cost()) {
        perror("Error at UpgradableUnit::Upgrade(): no enough money.\n");
    }

    owner_->Pay(upgrade_cost());
    ++level_;
}

void UpgradableUnit::TravelEven(Player* traveler) {
    if (CanBuyBy(traveler)) {
        AskBuy(traveler);
    } else if (CanUpgradeBy(traveler)) {
        AskUpgrade();
    } else if (NeedFine(traveler)) {
        AskPay(traveler);
    }
}

void UpgradableUnit::PrintInfo() const {
    PrintBasicInfo();

    if (Abandoned()) {
        printf("    B$%5d   ", cost());
    } else {
        printf("(%d) U$%5d L%d", owner_id(), upgrade_cost(), level());
    }
}

void UpgradableUnit::Release() {
    level_ = 0;
    owner_ = nullptr;
}

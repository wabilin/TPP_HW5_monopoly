#include "upgradable_unit.h"
#include "player/player.h"
#include "base/controll.h"

UpgradableUnit::UpgradableUnit
(const std::string& name, int player_num,  int cost,
 int upgrade_cost, const std::vector<int>& fines)
  :PayUnit(name, player_num, cost), upgrade_cost_(upgrade_cost),
   level_(0), fines_(fines) {}

bool UpgradableUnit::CanUpgradeBy(const Player* traveler) const {
    return (traveler->id() == owner_id())
        && (owner_->money() > upgrade_cost())
        && level() < highest_level();
}

void UpgradableUnit::AskUpgrade() {
    printf("%s, do you want to upgrade %s? (1: Yes [default] / 2: No) ...>",
           owner_name().c_str(), name().c_str());

    if(GetYesOrNo()) {
        Upgrade();
    }
}

void UpgradableUnit::Upgrade() {
    if (level() >= highest_level()) {
        perror("Error at UpgradableUnit::Upgrade(): over highest level.\n");
    }
    if(owner_->money() <= upgrade_cost()) {
        perror("Error at UpgradableUnit::Upgrade(): no enough money.\n");
    }

    owner_->Pay(upgrade_cost());
    ++level_;
}

void UpgradableUnit::TravelEven(Player* traveler) {

}
